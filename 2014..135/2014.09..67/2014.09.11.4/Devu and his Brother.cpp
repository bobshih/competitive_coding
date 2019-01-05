#include <cstdio>
#include <algorithm>
using namespace std;
long long a[100005],b[100005];
int n1,n2;
long long op;

int main()
{
    scanf("%d %d",&n1,&n2);
    for(int i = 0;i < n1;i++){
        scanf("%d",&a[i]);
    }sort(a,a+n1);
    for(int i = 0;i < n2;i++){
        scanf("%d",&b[i]);
    }sort(b,b+n2);reverse(b,b+n2);

    op = 0;
    for(int i = 0;i < min(n1,n2);i++){
        if(a[i] < b[i])op+=b[i]-a[i];
    }

    printf("%I64d\n",op);

    return 0;
}
