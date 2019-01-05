#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int m;
    int matrix[105][105];
    int row[105];
    int column[105];

    while(scanf("%d",&m) != EOF){
        if(m == 0)break;
        memset(row,0,sizeof(row));
        memset(column,0,sizeof(column));

        for(int i = 0;i < m;i++){
            for(int j = 0;j < m;j++){
                scanf("%d",&matrix[i][j]);
                row[i] += matrix[i][j];
            }
        }

        for(int i = 0;i < m;i++){
            for(int j = 0;j < m;j++){
                column[i] += matrix[j][i];
            }
        }


        int chang_r = 0;
        int chang_c = 0;
        int x,y;
        for(int i = 0;i < m;i++){
            if(row[i]%2 != 0){chang_r++;y = i+1;}
            if(column[i]%2 != 0){chang_c++;x = i+1;}
        }

        if(chang_c == 0 && chang_r == 0){
            printf("OK\n");
        }else if(chang_c == 1 && chang_r == 1){
            printf("Change bit (%d,%d)\n",y,x);
        }else {printf("Corrupt\n");}

    }



    return 0;
}
