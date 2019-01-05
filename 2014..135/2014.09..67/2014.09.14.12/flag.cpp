#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,m;cin >>n>>m;
    bool out = 0;
    int flag = 0;
    char maps[105][105];
    for(int i = 0;i < n;i++){
        scanf("%s",maps[i]);
        flag = maps[i][0];
        if(i > 0 && flag == maps[i-1][0])out = 1;
        for(int j = 1;j < m;j++){
            if(maps[i][j] != flag){
                out = 1;break;
            }
        }
    }
    if(out)cout <<"NO\n";
    else cout <<"YES\n";

    return 0;
}
