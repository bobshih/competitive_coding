#include <iostream>

using namespace std;

int main()
{
    int n;cin >>n;
    int mail[1005];mail[0] = 0;
    bool test = 0;
    int mails = 0;

    for(int i = 1;i <= n;i++){
        cin >>mail[i];mails+=mail[i];
        if(test == 0 && mail[i] != 0)test = 1;
    }
    if(test == 0){
        cout <<0<<endl;
        return 0;
    }
    int sum = 0;
    bool tag = 0;
    for(int i = 1;i <= n;i++){
        if(mail[i] == 1 && mail[i-1] == 0){
            sum++;mails--;
        }else if(mail[i] == 1 && mail[i-1] == 1){
            sum++;mails--;
        }else if(mail[i] == 0 && mail[i-1] == 1 && mails != 0){
            sum++;
        }
    }cout <<sum<<endl;

    return 0;
}
