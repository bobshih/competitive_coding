#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long sum,dia;
int node;
int maps[805][805];

long long DFS(long long x,long long par){
    long long h1 = 0,h2 = 0;
    for(int i = 1;i <= node;i++){
        if(maps[x][i] && i != par && maps[i][0] > 1){
            long long h = DFS(i,x)+maps[x][i];
            if(maps[x][0] == 1){h -= maps[x][i];}
            if(h > h1){h2 = h1;h1 = h;}
            else if(h > h2){h2 = h;}
        }
    }
    dia = max(dia,h1+h2);
    return h1;
}

int main()
{
    while(scanf("%d",&node) != EOF){
        if(node == 0)break;
        sum = 0;
        memset(maps,0,sizeof(maps));

        int temp[805];
        for(int i = 0;i < node-1;i++){
            scanf("%d",&temp[i]);
            maps[i+2][0]++;
            maps[temp[i]][0]++;
        }
        int t;
        for(int i = 0;i < node-1;i++){
            scanf("%d",&t);
            sum += t;
            maps[i+2][temp[i]] = t;
            maps[temp[i]][i+2] = t;
        }

        long long sum_leaf = 0;
        for(int i = 1;i <= node;i++){
            if(maps[i][0] == 1){
                for(int j = 1;j <= node;j++){
                    sum_leaf+=maps[i][j];
                    //maps[i][j] = 0;
                }
            }
        }

        //cout <<"sum = "<<sum<<" sum_leaf = "<<sum_leaf<<endl;
        //for(int i = 1;i <= node;i++){
        //    for(int j = 0;j <= node;j++){
        //        printf("%d ",maps[i][j]);
        //  }cout <<endl;
        //}

        dia = 0;
        DFS(1,1);
        //cout <<"diameter = "<<dia<<endl;
        long long double_sum = sum-sum_leaf-dia;

        printf("%lld\n",double_sum*2 + sum + dia);
        //cout <<"diameter = "<<dia<<endl;
        //for(int i = 1;i <= node;i++){
        //    for(int j = 1;j <= node;j++){
        //        printf("%d ",maps[i][j]);
        //    }cout <<endl;
        //}

    }


    return 0;
}
