#include <iostream>
#include <cstdio>
using namespace std;
char maps[4][4];
bool flag;

void counting(int i,int j,int f){
    char temp = maps[i][j];
    int ff = f;
    if(maps[i+1][j] != temp)ff++;
    if(maps[i][j+1] != temp)ff++;
    if(maps[i+1][j+1] != temp)ff++;
    if(ff <= 1)flag = 1;
}

int main()
{
    for(int i = 0;i < 4;i++){
        scanf("%s",maps[i]);
    }
    flag = 0;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            counting(i,j,0);
            if(maps[i][j] == '#'){
                maps[i][j] = '.';
                counting(i,j,1);
                maps[i][j] = '#';
            }else {
                maps[i][j] = '#';
                counting(i,j,1);
                maps[i][j] = '.';
            }
            if(flag)break;
        }
        if(flag)break;
    }

    if(flag)cout <<"YES\n";
    else cout <<"NO\n";
    return 0;
}
