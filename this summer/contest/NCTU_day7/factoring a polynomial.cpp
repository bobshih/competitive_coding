#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    int a0,a1,a2;


    while(scanf("%d",&n) == 1){
        if(n > 2){
            for(int i = 0;i <= n;i++)scanf("%d",&a0);
            printf("NO\n");
        }else if(n < 2){
            for(int i = 0;i <= n;i++)scanf("%d",&a0);
            printf("YES\n");
        }else if(n == 2){
            scanf("%d %d %d",&a2,&a1,&a0);

            if(a1*a1 - 4*a2*a0 >= 0){printf("NO\n");}
            else {printf("YES\n");}
        }
    }

    return 0;
}
