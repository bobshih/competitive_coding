#include <cstdio>
#include <cstring>
using namespace std;

int tset(int p,int r,int s){
    if(p != 0 && r != 0 && s != 0)return 0;
    if(p == 0 && r != 0 && s != 0)return 2;
    if(p != 0 && r == 0 && s != 0)return 3;
    if(p != 0 && r != 0 && s == 0)return 1;
    return 0;
}
int main()
{
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        int win[15];memset(win,0,sizeof(win));
        char game[15][40];memset(game,0,sizeof(game));
        for(int i = 0;i < n;i++){
            scanf("%s",game[i]);
        }

        for(int i = 0;i < strlen(game[0]);i++){
            int R = 0,P = 0,S = 0;
            for(int j = 0;j < n;j++){
                if(game[j][i] == 'R' && win[j] == 0)R++;
                if(game[j][i] == 'P' && win[j] == 0)P++;
                if(game[j][i] == 'S' && win[j] == 0)S++;
            }int t = tset(P,R,S);
            if(t == 0 )continue;
            else {
                if(t == 1){
                    for(int j = 0;j < n;j++){
                        if(game[j][i] != 'P')win[j] = 1;
                    }
                }else if(t == 2){
                    for(int j = 0;j < n;j++){
                        if(game[j][i] != 'R')win[j] = 1;
                    }
                }else {
                    for(int j = 0;j < n;j++){
                        if(game[j][i] != 'S')win[j] = 1;
                    }
                }

            }
        }

        int winner,pp = 0;
        for(int i = 0;i < n;i++){
            if(win[i] == 0){winner = i;pp++;}
        }

        if(pp > 1)printf("0\n");
        else printf("%d\n",winner+1);
    }

    return 0;
}
