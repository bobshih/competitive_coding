#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
long long int lott[10005],sum;

long long int gcd(long long int a,long long int b){
    if(b == 0)return a;
    return gcd(b,a%b);
}

int main()
{
    while(scanf("%d %d",&n,&m) != EOF){
        if(!n && !m)break;
        memset(lott,0,sizeof(lott));

        sum = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)scanf("%lld",&lott[i]);
            sum += lott[i];
        }

        for(int i = 0;i < n;i++){
            long long int a = lott[i];
            if(a == 0)printf("0 / 1\n");
            else {
                long long int g = gcd(a,sum);
                printf("%lld / %lld\n",a/g,sum/g);
            }

        }

    }

    return 0;
}
