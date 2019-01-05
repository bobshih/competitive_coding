#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
bool prime[35000];

int main()
{
    long long a;
    memset(prime,1,sizeof(prime));
    prime[0] = 0;
    prime[1] = 0;
    for(int i = 3;i < 35000;i++){
        for(int j = 2;j < sqrt(i);j++){
            if(i%j == 0)prime[i] = 0;
        }
        //printf("i = %d prime = %d\n",i,prime[i]);
    }

    scanf("%I64d",&a);
    long long sum = a;

    while(a != 1){
        bool flag = 0;
        for(int i = 2;i < 35000;i++){
            if(prime[i] && a%(long long)i == 0){
                //cout <<"a = "<<a<<" i = "<<i<<" sum = "<<sum<<endl;
                sum += (a/i);
                a /= i;
                flag = 1;
                break;
            }
        }

        if(flag == 0){
            a = 1;
            sum++;
            break;
        }
    }

    printf("%I64d\n",sum);

    return 0;
}
