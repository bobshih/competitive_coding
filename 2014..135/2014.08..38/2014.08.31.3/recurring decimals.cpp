#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int len,a;
int temp[25];
int dec[10];

int main()
{
    int pos;

    while(scanf("%d %d",&a,&len) != EOF && (a || len)){
        pos =  0;

        again:
        temp[pos] = a;pos++;
        for(int i = 0;i < pos;i++){

        }

        for(int i = 0;i < len;i++){
            dec[i] = a%10;
            a/=10;
        }sort(dec,dec+len);

        int t1 = 0,t2 = 0;
        for(int i = 0;i < len;i++){
            t1+=dec[i]*pow(10.0,len-i-1);
            t2+=dec[len-1-i]*pow(10.0,len-i-1);
        }//printf("%d %d\n",t1,t2);
        a = t2 - t1;
        bool flag = 0;

        //printf("temp:\n");
        //for(int i = 0;i < pos;i++){
        //    printf("%d = %d\n",i,temp[i]);
        //}

        for(int i = 0;i < pos;i++){
            for(int j = i+1;j < pos;j++){
                if(temp[i] == temp[j]){
                    printf("%d %d %d\n",i,temp[j],j-i);
                    flag = 1;
                }
            }
        }if(flag == 0)goto again;
    }

    return 0;
}
