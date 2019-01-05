#include <iostream>

using namespace std;

int main()
{
    int n;cin >>n;
    int a[105];
    if(n%2)cout <<-1<<endl;
    else {
        for(int i = 1;i <= n;i++){
            cout <<n-i+1<<" ";
        }cout <<endl;
    }


    return 0;
}
