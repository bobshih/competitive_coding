#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
    int n,m,d;cin >>n>>m>>d;
    int num[10005];
    int dd[10005];
    for(int i = 0;i < n*m;i++){
        cin >>num[i];
        dd[i] = num[i]-num[0];
    }
    for(int i = 0;i < n*m;i++){
        if(dd[i]%d != 0){
            cout <<-1<<endl;
            return 0;
        }
    }sort(num,num+n*m);

    int mid1 = n*m/2,mid2 = n*m/2+1;
    int ans1 = 0,ans2 = 0;
    for(int i = 0;i < n*m;i++){
        ans1 += abs((num[i]-num[mid1])/d);
        ans2 += abs((num[i]-num[mid2])/d);
    }
    cout <<min(ans2,ans1)<<endl;

    return 0;
}
