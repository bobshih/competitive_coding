#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
/*
struct laptop{
    int quality,price;
}Laptop[100005];*/
int laptop[100005];

int main()
{
    scanf("%d",&n);
    memset(laptop,0,sizeof(laptop));

    int t1,t2;
    for(int i = 0;i < n;i++){
        scanf("%d %d",&t1,&t2);
        laptop[t1] = t2;
    }
    bool flag = 0;
    int temp = laptop[1];
    for(int i = 2;i <= n;i++){
        if(laptop[i]  < temp){flag = 1;break;}
        temp = laptop[i];
    }
    if(flag){puts("Happy Alex");}
    else puts("Poor Alex");

    return 0;
}
