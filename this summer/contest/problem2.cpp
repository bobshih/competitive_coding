#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long coun(int cir,int start,int gap){
    if(cir == 0){return 0;}
    else return 4*start+6*gap+coun(cir-1,start+3*gap+gap+2,gap+2);
}

int main()
{
    int k;
    scanf("%d",&k);

    int circle = k/2;

    long long ans = 1;
    ans += coun(circle,3,2);

    cout <<ans<<endl;

    return 0;
}
