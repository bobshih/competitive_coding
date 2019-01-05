#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool a[101][101];
bool row[101];
bool col[101];
bool b[101][101];
int n,m;

int main()
{
    scanf("%d %d", &m, &n);
    memset(row, 1, sizeof(row));
    memset(col, 1, sizeof(col));

    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] == 0)row[i] = 0;
        }
    }

    for(int j = 0;j < n;j++){
        for(int i = 0;i < m;i++){
            if(a[i][j] == 0)col[j] = 0;
        }
    }

    bool ex = 0;
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n;j++){
            if(a[i][j]){
                if(row[i] || col[j])continue;
                else {ex = 1;break;}
            }
        }if(ex)break;
    }

    if(ex){
        printf("NO\n");
        return 0;
    }else {
        bool t1 = 0;
        for(int i = 0;i < m;i++){
            if(row[i] == 1){
                t1 = 1;break;
            }
        }
        bool t2 = 0;
        for(int j = 0;j < n;j++){
            if(col[j] == 1){
                t2 = 1;break;
            }
        }
        //cout <<t1<<"\t"<<t2<<endl;
        if((t1 == 1 && t2 == 0) || (t1 == 0 && t2 == 1)){
            printf("NO\n");
            return 0;
        }

        printf("YES\n");
    }
    for(int i = 0;i < m;i++){
        for(int j = 0;j < n-1;j++){
            printf("%d ", row[i] & col[j]);
        }printf("%d\n", row[i] & col[n-1]);
    }


    return 0;
}
