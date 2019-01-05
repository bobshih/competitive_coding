#include <iostream>

using namespace std;

int main()
{
    double n,m;
    cin >>n>>m;
    if(n == 1)cout <<1<<endl;
    else cout <<1./n+(n-1.)/n*(m-1)/(m*n-1)<<endl;
    return 0;
}
