#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int num[100010];
long long ans[100010];

int main()
{
    //again:
    scanf("%d",&n);
    memset(num,0,sizeof(num));

    int temp;
    int m = 0;
    for(int i = 0;i < n;i++){
        scanf("%d",&temp);
        if(m < temp)m = temp;
        num[temp]++;
    }

    ans[0] = 0;
    for(int i = 1;i <= m;i++){
        ans[i] = max(ans[i-1],(long long)num[i]*i + (i>2)*ans[i-2]);
        //cout <<ans[i]<<endl;
    }
    cout <<ans[m]<<endl;
    //goto again;
    return 0;
}
