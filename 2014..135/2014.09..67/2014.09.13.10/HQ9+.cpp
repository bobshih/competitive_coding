#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string a;
    cin >>a;

    for(int i = 0;i < a.size();i++){
        if(a[i] == 'H' || a[i] == 'Q' || a[i] == '9'){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
