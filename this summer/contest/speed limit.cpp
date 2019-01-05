#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int test;
    int speed,time;
    int sum_t,sum_m;

    while(scanf("%d",&test)){
        if(test == -1){break;}

        sum_t = sum_m = 0;
        for(int i = 0;i < test;i++){
            scanf("%d %d",&speed,&time);
            sum_m += speed * (time-sum_t);
            sum_t = time;
        }
        printf("%d miles\n",sum_m);
    }



    return 0;
}
