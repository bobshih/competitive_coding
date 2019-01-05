#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

#define MOD 1000000007
using namespace std;
int n;
int ver[100005];
long long dp[100005][2];
bool flag;
vector<int> ed[100005];

void DFS(int x){
    dp[x][ver[x]] = 1;
    for(int i = 0;i < ed[x].size();i++){
        int y = ed[x][i];
        DFS(y);

        long long x0 = dp[x][0],x1 = dp[x][1],y0 = dp[y][0],y1 = dp[y][1];
        dp[x][0] = (x0*y0+x0*y1)%MOD;
        dp[x][1] = ((x1*y0 + x1*y1)%MOD + x0*y1)%MOD;
    }
}

int main()
{
    scanf("%d",&n);
    int temp;
    for(int i = 0;i < n-1;i++){
        scanf("%d",&temp);
        ed[temp].push_back(i+1);
    }
    for(int i = 0;i < n;i++){
        scanf("%d",&ver[i]);
    }
    memset(dp,0,sizeof(dp));
    DFS(0);

    //for(int i = 0;i < n;i++){
    //    printf("i = %d dp[i][0] = %I64d dp[i][1] = %I64d\n",i,dp[i][0],dp[i][1]);
    //}

    printf("%I64d\n",dp[0][1]);

    return 0;
}
