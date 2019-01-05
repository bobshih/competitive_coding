#include <iostream>
#include <cstdio>
using namespace std;

int n,k,s;
int ans;
int sets[25];
int l;
bool flag;

void DFS(int num,int set_num,int remain){
    //cout <<"num = "<<num<<" set_num = "<<set_num<<" remain = "<<remain<<endl;
    //if(remain == 0){
    //    if(num + remain > s)return;
    //    DFS(num-1,set_num+1,num);
    //}

    if(num + remain > s)return;
    if(num + remain == s && set_num == k){
        ans++;//flag = 1;
        //sets[set_num] = num;
        //cout <<"ans = "<<ans<<endl;
        //for(int i = 1;i <= n;i++)printf("%d ",sets[i]);
        //system("pause");
        return;
    }
    else if(num + remain == s)return;

    for(int i = 1;i < num;i++){
        DFS(num-i,set_num+1,remain+num);
        //if(flag){sets[set_num] = num;break;}
    }
}

int main()
{
    //freopen("in.txt","r",stdin);

    while(scanf("%d %d %d",&n,&k,&s) == 3){
        if(n == 0 && k == 0 && s == 0)break;

        int temp = k*(n*2-k+1)/2;
        if(k > n){
            printf("0\n");continue;
        }else if(temp < s){
            printf("0\n");continue;
        }else if(k*(k+1)/2 > s){
            printf("0\n");continue;
        }

        ans = flag = 0;
        for(int i = 0;i < n;i++){
            //cout <<"i = "<<i<<endl;
            if(!flag)DFS(n-i,1,0);
            else break;
        }
        printf("%d\n",ans);
        //cout <<"finally ans = "<<ans<<endl;
        //for(int i = 1;i <= k;i++){
        //    printf("%d\n",sets[i]);
        //}



    }

    return 0;
}
