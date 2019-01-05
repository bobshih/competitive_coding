#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long prime,ball;

    while(scanf("%I64d %I64d",&ball,&prime) != EOF){
        long long num = 0;
        num = ball/(prime-1);
        //for(int i = 1;i <= ball;i++){
        //    if(i%(prime-1) == 0)num++;
        //}
        if(num%2 == 0){printf("NO\n");}
        else {printf("YES\n");}

    }

    return 0;
}
