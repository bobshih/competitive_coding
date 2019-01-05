#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double n,m;
    cin >>m>>n;

    double sum = 0;
    for(double i = 1;i <= m;i++){
        double t = (pow(i/m,n)) - (pow((i-1)/m,n));
        sum += t*i;
    }
    cout <<sum<<endl;
    return 0;
}
