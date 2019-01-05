#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int n;
int lis[300005];
long long sum;

int main(){
    sum = 0;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&lis[i]);sum += lis[i];
    }sort(lis,lis+n);

    long long ans = sum;
    for(int i = 0;i < n-1;i++){
        ans += sum;sum-=lis[i];
    }
    printf("%I64d\n",ans);

    return 0;
}
