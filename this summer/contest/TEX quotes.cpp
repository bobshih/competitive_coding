#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    string s;
    char st[1000];
    bool a;
    bool b;
    bool out = 0;
    int i;
    a = 0;
    while(!cin.eof()){
        getline(cin,s);


        for(int i = 0;i < s.size();i++){
            if(s[i] == '"' && !a){a = 1;printf("``");}
            else if(s[i] == '"'){a = 0;printf("''");}
            else {printf("%c",s[i]);}
        }cout <<endl;
    }


    return 0;
}
