#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n,k,ans = 0;
    scanf("%d %d",&n,&k);
    bool vis[11];

    int temp;
    for(int i = 0;i < n;i++){
        memset(vis,0,sizeof(vis));
        scanf("%d",&temp);
        while(temp){
            int a = temp%10;
            vis[a] = 1;
            temp /= 10;
        }

        bool flag = 0;
        for(int j = 0;j <= 10;j++){
            if(vis[j] == 0 && j <= k){flag = 1;break;}
            //if(vis[j] == 1 && j > k){flag = 1;break;}
        }
        if(flag == 0)ans++;
        //cout <<ans<<endl;
    }
    printf("%d\n",ans);

    return 0;
}
