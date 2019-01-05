#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,l;
int ant[25][4];

int main()
{
    freopen("in.txt","r",stdin);

    while(scanf("%d %d",&n,&l) == 2){
        if(n == 0 && l == 0)break;
        memset(ant,0,sizeof(ant));

        char t;
        for(int i = 0;i < n;i++){
            scanf(" %c %d",&t,&ant[i][0]);
            if(t == 'R'){ant[i][1] = 1;}
            else if(t == 'L'){ant[i][1] = -1;}
            ant[i][0] *= 2;
        }l *= 2;

        int ti = 0;
        int ans;
        int pp = 1;
        while(true){
            //cout <<"ti = "<<ti<<endl;
            ti++;
            for(int i = 0;i < n;i++){
                if(ant[i][0] != -100)ant[i][0] += ant[i][1];
                if((ant[i][0] < 0 || ant[i][0] > l) && ant[i][0] != -100){
                    //cout <<"bye i = "<<i<<" pp = "<<pp<<endl;
                    ant[i][0] = -100;ant[i][2] = pp++;
                    ant[i][3] = ti;
                    if(pp > n){
                        if(ant[i][1] == -1){ans = i+1;}
                        else {
                            ans = i+1;
                            for(int a = 0;a < n;a++){
                                if(ant[a][2] == n-1 && ant[a][3] == ti){
                                    ans = a+1;
                                }
                            }
                        }
                        goto output;
                    }
                }
            }

            for(int i = 0;i < n;i++){
                if(ant[i][0] == -100)continue;
                for(int j = i+1;j < n;j++){
                    if(ant[i][0] == ant[j][0]){
                        if(ant[i][0]%2 == 0){
                            ant[i][1] *= -1;
                            ant[j][1] *= -1;
                        }
                    }

                }
            }

        }
        output:
            printf("%d %d\n",ti/2,ans);

    }

    return 0;
}
