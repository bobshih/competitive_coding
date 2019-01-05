#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;scanf("%d",&n);

    for(int i = 1;i <= n;i+=2){
        int k = n/2-i/2;
        int l = n/2+i/2;
        for(int j = 0;j < n;j++){
            if(j < k){printf("*");}
            else if(j > l){printf("*");}
            else {printf("D");}
        }cout <<endl;
    }

    for(int i = n-2;i >= 1;i-=2){
        int k = n/2-i/2;
        int l = n/2+i/2;
        for(int j = 0;j < n;j++){
            if(j < k){printf("*");}
            else if(j > l){printf("*");}
            else {printf("D");}
        }cout <<endl;
    }


    return 0;
}
