#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    printf("%lld\n",(long long)(1<<18)*100*18);
    int n,m;
    int temp;
    int num1,num2;
    bool locker[4000] = {0};
    int Max = 0,Min = 0;
    int flag = 0;

    while(scanf("%d %d",&n,&m) == 2){
        for(int i = 0;i < m;i++){
            scanf("%d",&temp);
            if(temp == 2){scanf("%d",&num1);locker[num1] = true;}
            else {scanf("%d %d",&num1,&num2);locker[num1] = true;locker[num2] = true;}
        }

        for(int i = 1;i < n;i++){
            if(locker[i] == false && flag == 0){
                    flag = 1;Max++;Min++;}
            else if(locker[i] == false && flag == 1){
                    Max++;flag = 0;
            }
            else {flag = 0;}

        }

        for(int i = 0;i < n;i++){locker[i] = false;}
        printf("%d %d\n",Min,Max);
    }


    return 0;
}
