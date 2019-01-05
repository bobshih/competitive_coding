#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char board[105][105];
int a[105][105];

int main()
{
    int n;
    scanf("%d",&n);

    int ans = 0;
    memset(board,0,sizeof(board));
    memset(a,0,sizeof(a));

    for(int i = 1;i <= n;i++){
        scanf("%s",board[i]);
        for(int l = 0;l < n;l++){
            if(board[i][l] == 'o')a[i][l] = 1;
        }
    }

    //cout <<ans<<endl;
    for(int i = 1;i <= n;i++){
        for(int j = 0;j < n;j++){
            int tt = a[i+1][j]+a[i-1][j]+a[i][j+1]+a[i][j-1];
            if(tt%2){printf("NO\n");return 0;}
        }
    }

    printf("YES\n");

    return 0;
}
