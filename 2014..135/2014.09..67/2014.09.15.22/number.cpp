#include <iostream>
#include <cstring>
using namespace std;

int gcd(int a,int b){
    if(a%b == 0)return b;
    else return gcd(b,a%b);
}

int main()
{
    int num[1001];memset(num,0,sizeof(num));
    for(int i = 3;i <= 1000;i++){
        for(int j = i;j <= 1000;j++){
            int tt = j;
            while(tt){
                num[j] += (tt%(i-1));
                tt /= (i-1);
            }
        }
    }
    int n;
    cin >>n;
    int temp = gcd(num[n],n-2);
    cout <<num[n]/temp<<"/"<<(n-2)/temp<<endl;
    return 0;
}
