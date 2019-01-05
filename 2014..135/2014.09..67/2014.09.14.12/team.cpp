#include <iostream>

using namespace std;

int main()
{
    int n;cin >>n;
    int s,ans = 0,a;
    for(int i = 0;i < n;i++){
        s = 0;
        for(int j = 0;j < 3;j++){
            cin >>a;
            if(a == 1)s++;
        }if(s >= 2)ans++;
    }cout <<ans<<endl;

    return 0;
}
