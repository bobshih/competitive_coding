#include <iostream>
#include <cstdio>
#include <cstring>

#define INF 0xffffff
using namespace std;
int n,k;
int grid[100][100];
int dp[100][100][10][4];
int p[100][100][10][4];
int pass,sum;

int dynamic(int i,int j,int left,int from){
    //cout <<"i = "<<i<<" j = "<<j<<" pos = "<<grid[i][j]<<endl;
    if(left < 0)return -INF;
    if(p[i][j][left][from])return dp[i][j][left][from];
    if(i == n && j == n)return grid[n][n];

    int a = -INF,b = -INF,c = -INF;
    if(i != n){                 //1代表從上面來的
        if(grid[i+1][j] < 0)a = dynamic(i+1,j,left-1,1);
        else a = dynamic(i+1,j,left,1);
    }
    if(j != 1 && from != 3){    //3代表從右邊來的
        if(grid[i][j-1] < 0)b = dynamic(i,j-1,left-1,2);
        else b = dynamic(i,j-1,left,2);
    }
    if(j != n && from != 2){    //2代表從左邊來的
        if(grid[i][j+1] < 0)c = dynamic(i,j+1,left-1,3);
        else c = dynamic(i,j+1,left,3);
    }


    p[i][j][left][from] = 1;
    if(a == -INF && b == -INF && c == -INF){
        return dp[i][j][left][from] = -INF;
    }
    return dp[i][j][left][from] = max(a,max(b,c))+grid[i][j];
}

int main()
{
    int c = 0;
    while(scanf("%d %d",&n,&k) == 2){
        if(n == 0 && k == 0)break;
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++){
                scanf("%d",&grid[i][j]);
            }
        }

        memset(p,0,sizeof(p));
        memset(dp,0,sizeof(dp));
        if(grid[1][1] < 0)k--;
        sum = dynamic(1,1,k,0);
        if(sum != -INF)printf("Case %d: %d\n",++c,sum);
        else printf("Case %d: impossible\n",++c);
    }

    return 0;
}
