#include <cstdio>
#include <algorithm>
using namespace std;
int cha[100005];
int main()
{
    int n,x;scanf("%d %d",&n,&x);

    for(int i = 0;i < n;i++){
        scanf("%d",&cha[i]);
    }sort(cha,cha+n);

    //for(int i = 0;i < n;i++){
    //    printf("cha[%d] = %d\n",i,cha[i]);
    //}

    long long sum = 0,temp;
    for(int i = 0;i < n;i++){
        temp = (long long)cha[i]*(long long)x;
        if(x != 1)x--;
        sum += temp;
    }
    printf("%I64d\n",sum);

    return 0;
}
