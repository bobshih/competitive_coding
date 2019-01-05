#include <iostream>

using namespace std;

int main()
{
    int k,l,m,n,d;
    cin >>k>>l>>m>>n>>d;
    bool dra[100005];
    int ans = 0;
    for(int i = 1;i <= d;i++){
        dra[i] = 1;
        if(i%k == 0)dra[i] = 0;
        if(i%l == 0)dra[i] = 0;
        if(i%m == 0)dra[i] = 0;
        if(i%n == 0)dra[i] = 0;
        if(dra[i])ans++;
    }
    cout <<d-ans<<endl;
    return 0;
}
