#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;scanf("%d",&n);
    int town[100005],num[100005];
    for(int i = 0;i < n;i++){
        scanf("%d",&town[i]);
        num[i] = town[i];
    }sort(town,town+n);

    if(town[0] == town[1]){
        printf("Still Rozdil\n");
    }else {
        for(int i = 0;i < n;i++){
            if(town[0] == num[i]){
                printf("%d\n",i+1);
                break;
            }
        }
    }

    return 0;
}
