#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int n;
    long long a,b;
    int temp = 0;

    cin >>n>>a>>b;
    long long* day_get = new long long[n];
    long long* day_save = new long long[n];

    for(int i = 0;i < n;i++){

        cin >>day_get[i];

        day_save[i] = day_get[i]*a%b/a;
        cout <<day_save[i]<<" ";
        //temp = day_save[i];
    }


    delete [] day_get;
    delete [] day_save;
    return 0;
}
