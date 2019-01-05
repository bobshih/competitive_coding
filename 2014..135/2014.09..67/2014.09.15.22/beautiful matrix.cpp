#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int x,y;
    int t;
    for(int i = 1;i <= 5;i++){
        for(int j = 1;j <= 5;j++){
            scanf("%d",&t);
            if(t == 1){
                x = j;
                y = i;
            }
        }
    }

    int ans = abs(3-x)+abs(3-y);
    cout <<ans<<endl;

    return 0;
}
