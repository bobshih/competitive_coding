#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;cin >>n;
    int station[105],sum[105];
    for(int i = 0;i < n;i++){
        cin >>station[i];
        if(i == 0)sum[i] = 0;
        else {
            sum[i] = sum[i-1]+station[i-1];
        }
    }sum[n] = sum[n-1]+station[n-1];

    //for(int i = 0;i <= n;i++){
    //    cout <<"i = "<<i<<" sum = "<<sum[i]<<endl;
    //}
    int s,t;
    cin >>s>>t;
    s--;t--;
    if(s > t)swap(s,t);

    //if(s == t)cout <<0<<endl;
    //else {
        int len1 = sum[t]-sum[s];
        int len2 = sum[n]-sum[t]+sum[s];

        cout <<min(len1,len2)<<endl;
    //}

    return 0;
}
