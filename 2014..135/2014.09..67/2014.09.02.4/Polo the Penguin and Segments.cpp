#include <iostream>

using namespace std;
int n,k;

int main()
{
    cin >>n>>k;

    int t1,t2,sum = 0;
    for(int i = 0;i < n;i++){
        cin >>t1>>t2;
        sum += (t2-t1+1);
    }
    if(sum%k == 0){cout <<"0\n";}
    else cout <<k-sum%k<<endl;

    return 0;
}
