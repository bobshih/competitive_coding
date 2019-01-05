#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

long long degree[10010];

int main()
{
    int t;
    scanf("%d",&t);
    long long ans;

    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        memset(degree,0,sizeof(degree));

        for(int i = 0;i < m;i++){
            int t1,t2;
            scanf("%d %d",&t1,&t2);
            degree[t1]++;
            degree[t2]++;
        }

        ans = 0;
        for(int i = 1;i <= n;i++){
            //cout <<degree[i]<<endl;
            ans += (degree[i]*degree[i]);
        }

        printf("%lld\n",ans);
        if(t != 0){printf("\n");}
    }



    return 0;
}
