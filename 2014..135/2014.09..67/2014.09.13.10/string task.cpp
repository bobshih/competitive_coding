#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
    string a;
    cin >>a;
    for(int i = 0;i < a.size();i++){
        if(a[i] >= 'A' && a[i] <= 'Z')a[i] += 32;
        if(a[i] == 'a' || a[i] == 'o' || a[i] == 'y' || a[i] == 'e' || a[i] == 'u' || a[i] == 'i')a[i] = 0;
    }

    for(int i = 0;i < a.size();i++){
        if(a[i] == 0)continue;
        else printf(".%c",a[i]);
    }cout <<endl;

    return 0;
}
