#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long type;

int main()
{
    //freopen("in.txt", "r", stdin);
    type coconut;

    while(scanf("%lld", &coconut)){
        if(coconut == -1)break;

        type ans = -1;
        type temp;
        bool flag;
        type i;
        for(i = 2;pow((float)i,(float)i) < coconut;i++){
            temp = coconut;
            flag = 0;
            for(type j = 0;j < i;j++){
                temp--;
                if(temp%i != 0){
                    flag = 1;
                    break;
                }
                temp = temp/i*(i-1);
            }
            if(flag)continue;
            else if(temp%i == 0)ans = i;
        }

        temp = coconut;
        flag = 0;
        for(type j = 0;j < i;j++){
            temp--;
            if(temp%i != 0){
                flag = 1;
                break;
            }
            temp = temp/i*(i-1);
        }
        if(!flag && temp%i == 0)ans = i;

        if(ans == -1){
            printf("%lld coconuts, no solution\n", coconut);
        }else {
            printf("%lld coconuts, %lld people and 1 monkey\n", coconut, ans);
        }
    }

    return 0;
}
