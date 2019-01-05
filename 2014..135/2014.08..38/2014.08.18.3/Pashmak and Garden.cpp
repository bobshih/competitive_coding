#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int x1,x2,y1,y2;
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);

    if(x1 != x2 && y1 != y2){
        if(abs(x1-x2) != abs(y1-y2)){puts("-1");return 0;}
        else {
            printf("%d %d %d %d\n",x1,y2,x2,y1);
        }
    }else if(x1 == x2){
        int len = abs(y1-y2);
        printf("%d %d %d %d\n",x1+len,y1,x2+len,y2);
    }else if(y1 == y2){
        int len = abs(x1-x2);
        printf("%d %d %d %d\n",x1,y1+len,x2,y2+len);
    }
    return 0;
}
