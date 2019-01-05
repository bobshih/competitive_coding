#include <iostream>

using namespace std;

int main()
{
    int n;cin >>n;
    int wire[105];
    for(int i = 0;i < n;i++)cin >>wire[i];

    int shot;cin >>shot;
    int t1,t2;
    for(int i = 0;i < shot;i++){
        cin >>t1>>t2;
        int pl = wire[t1-1]-t2;
        int mi = wire[t1-1]-pl-1;
        if(t1 > 1){
            wire[t1-2] += mi;
        }if(t1 < n){
            wire[t1] += pl;
        }wire[t1-1] = 0;
    }

    for(int i = 0;i < n;i++){
        cout <<wire[i]<<endl;
    }

    return 0;
}
