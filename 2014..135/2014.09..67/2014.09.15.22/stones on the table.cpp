#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    int n,ans = 0;
    cin >>n>>a;

    bool flag;
    do{
        flag = 0;
        char temp = a[0];
        for(int i = 1;i < n;i++){
            if(a[i] == 0)continue;
            else if(a[i] == temp){
                a[i] = 0;
                flag = 1;
                ans++;
                break;
            }else {
                temp = a[i];
            }
        }
    }while(flag);

    cout <<ans<<endl;
    return 0;
}
