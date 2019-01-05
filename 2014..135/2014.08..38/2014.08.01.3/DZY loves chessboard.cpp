#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int n,m;
int board[105][105];

int main()
{
    char temp[105];
    scanf("%d %d",&n,&m);
    memset(board,0,sizeof(board));

    for(int i = 1;i <= n;i++){
        scanf("%s",temp);
        for(int j = 0;j < m;j++){
            if(temp[j] != '-'){board[i][j] = 0;}
            else {board[i][j] = 1;}
        }
    }

    //for(int i = 1;i <= n;i++){
    //    for(int j = 0;j < m;j++){
    //        printf("%d",board[i][j]);
    //    }cout <<endl;
    //}

    for(int i = 1;i <= n;i++){
        for(int j = 0;j < m;j++){
            if(board[i][j] == 1){printf("-");}
            else {
                if(i%2 && j%2){
                    printf("W");
                    //chess[i][j] = 'w';
                }else if(i%2 == 0 && j%2 == 0){
                    //chess[i][j] = 'w';
                    printf("W");
                }else {
                    printf("B");
                    //chess[i][j] = 'B';
                }
            }
        }printf("\n");
    }

    return 0;
}
