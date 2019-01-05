#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct HH{
    int light;
    int index;

    bool operator < (const HH &rhs)const{
        if(light != rhs.light)return light > rhs.light;
        return index > rhs.index;
    }

};
bool cmp(const HH &a,const HH &b){
        return a.index < b.index;
    }

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int n,k;cin >>n>>k;
    HH hours[1005];
    for(int i = 0;i < n;i++){
        cin >>hours[i].light;
        hours[i].index = i;
    }
    sort(hours,hours+n);

    cout <<hours[k-1].light<<endl;
    sort(hours,hours+k,cmp);
    cout <<hours[0].index+1;
    for(int i = 1;i < k;i++){
        cout <<" "<<hours[i].index+1;
    }

    return 0;
}
