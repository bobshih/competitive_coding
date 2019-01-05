#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;cin >>n;
    int num[105];
    int a[1001] = {};
    for(int i = 0;i < n;i++){
        cin >>num[i];
        a[num[i]]++;
        if(a[num[i]] > (n+1)/2){
            cout <<"NO\n";
            return 0;
        }
    }cout <<"YES\n";
    return 0;
}
