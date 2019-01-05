#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int n,t,s;
    scanf("%d %d %d",&n,&t,&s);

    int nums;
    int temp = 0;
    int sum = 0;

    for(int i = 0;i < n;i++){
        scanf("%d",&nums);
        if(nums <= t){temp++;}
        else {
            if(temp >= s)sum+=(temp-s+1);
            temp = 0;
        }
    }
    if(temp >= s)sum += (temp-s+1);
    printf("%d\n",sum);
    /*
    temp = 0;
    for(int i = 0;i < n;i++){
        if(nums[i] == 0){temp++;}
        else {
            if(temp >= s)sum +=(temp-s+1);temp = 0;}
    }*/


    return 0;
}
