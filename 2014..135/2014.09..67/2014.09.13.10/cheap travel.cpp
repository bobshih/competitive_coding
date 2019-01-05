#include <iostream>

using namespace std;

int main()
{
    int n,m,a,b;
    cin >>n>>m>>a>>b;

    int mon = n*a;
    int ano = n/m*b+(n - n/m*m)*a;
    int other = n/m*b+b;
    //cout <<mon<<endl<<ano<<endl<<other<<endl;

    if(mon >= ano && ano <= other)cout <<ano<<endl;
    else if(other <= ano && mon >= other)cout <<other<<endl;
    else cout <<mon<<endl;

    return 0;
}
