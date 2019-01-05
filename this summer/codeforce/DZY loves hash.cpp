#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int p,n;
    bool h[301];
    scanf("%d %d",&p,&n);
    memset(h,false,p);

    int temp;
    int conflict = -1;
    for(int i = 0;i < n;i++){
        scanf("%d",&temp);
        if(conflict == -1){
            if(h[temp%p]){conflict = i+1;}
            else h[temp%p] = true;
        }
    }
    if(conflict == -1){printf("-1\n");}
    else printf("%d\n",conflict);

    return 0;
}
