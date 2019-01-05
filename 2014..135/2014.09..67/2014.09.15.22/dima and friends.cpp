#include <iostream>

using namespace std;

int main()
{
    int n;cin >>n;
    int num,sum = 0;
    for(int i = 0;i < n;i++){
        cin >>num;
        sum+=num;
    }
    int i,ans = 0;
    for(i = 1;i <= 5;i++){
        if((sum+i)%(n+1) == 1)continue;
        else ans++;
    }
    cout <<ans<<endl;
    return 0;
}
