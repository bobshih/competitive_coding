#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    long long n;scanf("%I64d",&n);
    long long num[100005],ans = 0;
    for(int i = 0;i < n;i++){
        scanf("%I64d",&num[i]);
        if(i > 0 && num[i] < num[i-1]){
            ans += num[i-1]-num[i];
        }
    }
    printf("%I64d\n",ans);
    return 0;
}
