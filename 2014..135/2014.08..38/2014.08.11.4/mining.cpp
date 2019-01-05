#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int row,col;
char map1[32][32];
int map2[32][32];
int temp[32][32];

void add(int r,int c){
    map2[r-1][c]++;
    map2[r-1][c-1]++;
    map2[r-1][c+1]++;
    map2[r][c-1]++;
    map2[r][c+1]++;
    map2[r+1][c]++;
    map2[r+1][c-1]++;
    map2[r+1][c+1]++;
}

int main()
{
    while(scanf("%d %d",&row,&col) != EOF){
        memset(map2,0,sizeof(map2));
        memset(temp,0,sizeof(temp));

        for(int i = 1;i <= row;i++){
            scanf("%s",map1[i]);
            for(int a = 0;a < col;a++){
                if(map1[i][a] == '*'){
                    add(i,a);
                }else if(map1[i][a] == '?'){
                    add(i,a);
                }
            }
        }

        //for(int i = 1;i <= row;i++){
        //    printf("%s\n",map1[i]);
        //}

       // for(int i = 1;i <= row;i++){
       //     for(int a = 0;a < col;a++){
       //         cout <<"i = "<<i<<" a = "<<a<<" num = "<<map2[i][a]<<endl;
       //     }
       // }

        bool flag = 0;
        for(int i = 1;i <= row;i++){
            if(flag)break;
            for(int a = 0;a < col;a++){
                if(flag)break;
                if(map1[i][a] >= 48 && map1[i][a] <= 57){
                    if(map2[i][a] < map1[i][a]-48){
                        //cout <<"qq i = "<<i<<" a = "<<a<<" should be "<<map1[i][a]<<" actually is "<<map2[i][a]<<endl;
                        flag = 1;}
                }

            }
        }

        if(flag == 0){printf("PASS\n");}
        else printf("LIE\n");
    }

    return 0;
}
