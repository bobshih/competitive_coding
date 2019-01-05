#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    freopen("pA/a5.in","r",stdin);

    int n,t[4];
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d %d %d %d",&t[0],&t[1],&t[2],&t[3]);
        sort(t,t+4);
        int t1 = t[0]*2 + t[1] + t[2] + t[3];
        int t2 = t[0] + t[1]*3 + t[3];
        //cout <<t1<<"\t"<<t2<<endl;
        printf("%d\n",min(t1,t2));
        //cout <<min(t1,t2)<<endl;
    }

    return 0;
}
