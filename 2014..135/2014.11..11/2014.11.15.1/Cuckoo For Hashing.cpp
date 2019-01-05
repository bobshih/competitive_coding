#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n1,n2,m;
int t1[1001], t2[1001];

void insert_table(int t, int target){
    if(target == 1){
        int pos = t%n1;
        if(t1[pos] == -1){
            t1[pos] = t;
        }else {
            int temp = t1[pos];
            t1[pos] = t;
            insert_table(temp, 2);
        }
    }else {
        int pos = t%n2;
        if(t2[pos] == -1){
            t2[pos] = t;
        }else {
            int temp = t2[pos];
            t2[pos] = t;
            insert_table(temp, 1);
        }
    }
}

int main()
{
    int ca = 1;
    while(scanf("%d %d %d", &n1, &n2,&m)== 3){
        if(!n1 && !n2 && !m)break;
        memset(t1, -1, sizeof(t1));
        memset(t2, -1, sizeof(t2));

        int temp;
        for(int i = 0;i < m;i++){
            scanf("%d", &temp);
            insert_table(temp, 1);
        }

        printf("Case %d:\n", ca++);
        printf("Table 1\n");
        for(int i = 0;i < n1;i++){
            if(t1[i] == -1)continue;
            printf("%d:%d\n", i, t1[i]);
        }
        bool t = 0;
        for(int i = 0;i < n2;i++){
            if(t2[i] != -1){
                t = 1;break;
            }
        }
        if(t){
            printf("Table 2\n");
            for(int i = 0;i < n2;i++){
                if(t2[i] == -1)continue;
                printf("%d:%d\n", i, t2[i]);
            }
        }
    }

    return 0;
}
