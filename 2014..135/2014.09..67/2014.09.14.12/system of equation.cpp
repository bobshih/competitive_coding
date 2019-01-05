#include <iostream>

using namespace std;

int main()
{
    int n,m,ans = 0;
    cin >>n>>m;
    for(int i = 0;i <= max(n,m);i++){
        for(int j = i;j <= max(n,m);j++){
            //cout <<"i = "<<i<<" j = "<<j<<endl;
            if(i*i+j == n && i+j*j == m)ans++;
            if(i+j*j == n && i*i+j == m && i!=j)ans++;
        }
    }cout <<ans<<endl;

    return 0;
}
