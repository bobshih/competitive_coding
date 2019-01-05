#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    //printf("%I64d\n",LONG_LONG_MAX);
    long long x,y;
    scanf("%I64d %I64d",&x,&y);
    long long n;
    scanf("%I64d",&n);

    long long temp[6];
    temp[0] = x-y;
    temp[1] = x;
    temp[2] = y;
    temp[3] = y-x;
    temp[4] = -x;
    temp[5] = -y;

    long long t = temp[n%6];
    if(t > 0){t = t % 1000000007;}
    else {
        while(t < 0){
            t += 1000000007;
        }
    }

    printf("%I64d\n",t);

    return 0;
}
