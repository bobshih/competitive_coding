#include <iostream>
#include <cstdio>

using namespace std;

int coins[10010];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    int co = 1;
    int money = 1;
    coins[0] = 0;

    for(int i = 1;i < 10010;i++){
        for(int j = 0;j < co;i++,j++){
            //cout <<"i = "<<i<<" j = "<<j<<" coin = "<<co<<" money = "<<money<<endl;
            coins[i] = coins[i-1] + money;
        }co++;money++;i--;
    }

    int n;
    while(scanf("%d",&n)){
        if(n == 0)break;
        printf("%d %d\n",n,coins[n]);
    }


    return 0;
}
