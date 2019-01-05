#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n;cin >>n;

    bool flag;
    int dig[11];
    do{
        n++;flag = 0;
        memset(dig,0,sizeof(dig));
        int temp = n;
        while(temp){
            dig[temp%10]++;
            if(dig[temp%10] == 2){
                flag = 1;
                break;
            }temp /= 10;
        }

    }while(flag == 1);
    cout <<n<<endl;

    return 0;
}
