#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a;
    cin >>a;
    bool alp[26] = {};
    for(int i = 0;i < a.size();i++){
        alp[a[i]-'a'] = 1;
    }
    int ans = 0;
    for(int i = 0;i < 26;i++){
        if(alp[i])ans++;
    }
    if(ans%2 == 0)cout <<"CHAT WITH HER!\n";
    else cout <<"IGNORE HIM!\n";
    return 0;
}
