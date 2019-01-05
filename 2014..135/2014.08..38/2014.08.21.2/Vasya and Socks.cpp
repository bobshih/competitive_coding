#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);

    int ans = 0;
    int temp = 0;
    while(true){
        ans++;
        temp++;
        n--;
        if(temp == m){
            n++;
            temp = 0;
        }
        if(n == 0)break;
        //cout <<"ans = "<<ans<<" temp = "<<temp<<" n = "<<n<<endl;
    }
    cout <<ans<<endl;

    return 0;
}
