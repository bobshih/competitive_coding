#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;


int main(){
    string s;
    int add;

    getline(cin,s);
    scanf("%d",&add);

    int answer;
    bool success = false;
    int i,k;

    for(i = (add+s.length())>>1;i != 0 ;i--){
            for(int j = 0;j < s.length()+add;j++){

                    for(k = j;k < j+i;k++){
                          //printf("i = %d j = %d k = %d\n",i,j,k);
                            if(k+i < s.length() && s[k] == s[i+k]){continue;}
                            else if(k+i >= s.length() && k+i<(add+s.length())){continue;}
                            else {break;}
                            }
                    if(k == i+j)success = 1;
                    if(success){break;}
                    }
            if(success){break;}
            }

    printf("%d\n",i*2);

    //system("pause");
    return 0;
    }
