#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int cow[10010];

int main()
{
    int n;

    while(scanf("%d",&n) != EOF){
        for(int i = 0;i < n;i++){
            scanf("%d",&cow[i]);
        }
        sort(cow,cow+n);
        printf("%d\n",cow[n/2]);
    }

    return 0;
}
