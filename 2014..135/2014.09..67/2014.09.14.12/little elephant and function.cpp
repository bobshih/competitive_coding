#include <iostream>
#include <cstdio>
using namespace std;
int num[1001];
void fun(int x){
    if(x == 0)return ;

    int temp = num[x];
    num[x] = num[x-1];
    num[x-1] = temp;
    fun(x-1);
}

int main()
{
    int n;cin >>n;

    for(int i = 0;i < n;i++)num[i] = i;
    fun(n-1);
    //fun(n-1);

    printf("%d",num[0]+1);
    for(int i = 1;i < n;i++){
        printf(" %d",num[i]+1);
    }cout <<endl;

    return 0;
}
