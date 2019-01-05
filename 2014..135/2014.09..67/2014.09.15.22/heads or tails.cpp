#include <iostream>

using namespace std;

int main()
{
    int x,y,a,b;
    cin >>x>>y>>a>>b;

    int pp[100005][2],ans = 0;
    for(int i = a;i <= x;i++){
        if(i > b){
            for(int j = b;j <= y && i > j;j++){
                pp[ans][0] = i;
                pp[ans][1] = j;
                ans++;
            }
        }
    }

    cout <<ans<<endl;
    for(int i = 0;i < ans;i++){
        cout <<pp[i][0]<<" "<<pp[i][1]<<endl;
    }

    return 0;
}
