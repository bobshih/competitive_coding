#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main()
{
    int x,n;scanf("%d %d",&n,&x);
    int track[1001];
    for(int i = 0;i <= 1000;i++){
        track[i] = 0;
    }

    for(int i = 0;i < n;i++){
        int t1,t2;
        scanf("%d %d",&t1,&t2);if(t1 > t2)swap(t1,t2);
        for(int j = t1;j <= t2;j++){
            track[j]++;
        }
    }
    int dis = 100000,flag = 0;
    for(int i = 0;i <= 1000;i++){
        if(track[i] == n && abs(i-x) < dis){
            //cout <<"i = "<<i<<endl;
            flag = 1;
            dis = abs(i-x);
        }
    }
    if(flag)printf("%d\n",dis);
    else printf("-1\n");
    return 0;
}
