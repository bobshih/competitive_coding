#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    int n,s;
    scanf("%d %d",&n,&s);
    int sum = 0;

    int temp, maxi;
    for(int i = 0;i < n;i++){
        scanf("%d",&temp]);
        sum += temp;
        maxi = (maxi > temp) ? maxi : temp;
    }

    sum -= maxi;
    if(sum <= s){printf("YES\n");return 0;}
    printf("NO\n");
    return 0;
}
