#include <iostream>
#include <algorithm>
using namespace std;

struct Time{
    int h;
    int m;

    bool operator < (const Time &rhs)const{
        if(h != rhs.h)return h < rhs.h;
        return m < rhs.m;
    }
}client[100005];

int main()
{
    int n;cin >>n;
    for(int i = 0;i < n;i++){
        cin >>client[i].h>>client[i].m;
    }sort(client,client+n);

    int max = 1,now = 1;
    Time current;
    current.h = client[0].h,current.m = client[0].m;
    for(int i = 1;i < n;i++){
        if(client[i].h == current.h && client[i].m == current.m){
            now++;
        }else {
            if(now > max)max = now;
            now = 1;
            current.h = client[i].h,current.m = client[i].m;
        }
    }
    if(now > max)max = now;
    cout <<max<<endl;

    return 0;
}
