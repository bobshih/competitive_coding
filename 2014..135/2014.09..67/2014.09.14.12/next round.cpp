#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n,k;
    cin >>n>>k;
    vector<int> con;
    for(int i = 0;i < n;i++){
        int t;cin >>t;
        con.push_back(t);
    }sort(con.begin(),con.end());
    int s = con[n-k],ans = 0;
    for(int i = 0;i < n;i++){
        if(con[i] >= s && con[i] != 0)ans++;
    }
    cout <<ans<<endl;
    return 0;
}
