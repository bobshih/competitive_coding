#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
long long n,k,d;
int student[1005];

int main()
{
    scanf("%I64d %I64d %I64d",&n,&k,&d);
    double pp = pow((double)k,(double)d);

    if(n > d && n > k && n - pp > 1e-5){
        //printf("%lf\n",pp);
        puts("-1");
        return 0;
    }
    if(k == 1 && n > 1){
        puts("-1");
        return 0;
    }

    for(int i = 1;i <= n;i++){
        student[i] = i;
    }

    for(int i = 0;i < d;i++){
        for(int a = 1;a < n;a++){
            printf("%d ",student[a]%k+1);
            student[a] /= k;
        }
        printf("%d\n",student[n]%k+1);
        student[n] /= k;
    }

    return 0;
}
