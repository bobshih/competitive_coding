#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

int main()
{
    string s;

    getline(cin,s);

    int al = 0;
    bool alp[26];
    for(int i = 0;i < 26;i++){alp[i] = 0;}

    for(int i = 0;s[i] != '\0';i++){
        if(s[i] >= 'a' && s[i] <= 'z'){alp[s[i]-97] = 1;}
    }

    for(int i = 0;i <26;i++){
        if(alp[i] != 0)al++;
    }
    cout <<al;
    return 0;
}
