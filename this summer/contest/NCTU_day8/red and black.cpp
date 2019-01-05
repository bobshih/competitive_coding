#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n,m;
char floor[25][25];
bool visit[25][25];
int x,y;
int ans;

void step(int x,int y){
    if(y < 0 || y >= n || x < 0 || x >= m){
        return;
    }
    if(visit[x][y])return;
    else if(floor[x][y] == '.'){
        visit[x][y] = 1;
        ans++;
        //cout <<"ans = "<<ans<<" x = "<<x<<" y = "<<y<<" content = "<<floor[x][y]<<" dx = "<<x<<" xy = "<<y<<endl;
        step(x+1,y);
        step(x,y+1);
        step(x-1,y);
        step(x,y-1);
    }else {return;}

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    while(scanf("%d %d",&n,&m) == 2){
        if(n == 0 && m == 0)break;

        ans = 1;
        memset(visit,0,sizeof(visit));
        for(int i = 0;i < m;i++){
            scanf("%s",floor[i]);
            for(int j = 0;j < n;j++){
                if(floor[i][j] == '@'){y = i;x = j;break;}
            }
        }
        //cout <<"start_x = "<<y<<" start_y = "<<x<<" content = "<<floor[y][x]<<endl;
        step(y+1,x);
        step(y-1,x);
        step(y,x+1);
        step(y,x-1);
        printf("%d\n",ans);
    }


    return 0;
}
