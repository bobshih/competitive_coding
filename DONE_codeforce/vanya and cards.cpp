#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int card_n,m;
    int sum = 0;
    int temp;

    while(scanf("%d %d",&card_n,&m) == 2){
        for(int i = 0;i < card_n;i++){
            scanf("%d",&temp);
            sum += temp;
        }
        if(!(sum%m)){
                if(sum < 0){sum *= -1;}
                printf("%d\n",sum/m);}
        else {
                if(sum < 0){sum *= -1;}
                printf("%d\n",sum/m+1);}
        sum = 0;
    }

    return 0;
}
