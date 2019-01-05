#include <cstdio>

using namespace std;

int main()
{
    int n,s,x,y,M = 0;
    bool flag = 0;
    scanf("%d %d",&n,&s);
    for(int i = 0;i < n;i++){
        scanf("%d %d",&x,&y);
        if(100*x+y <= 100*s){
            flag = 1;
            y = 100-y;
            if(y == 100)y = 0;

            if(M < y)M = y;
        }
    }
    if(flag == 0){printf("-1\n");return 0;}
    printf("%d\n",M);
    return 0;
}
