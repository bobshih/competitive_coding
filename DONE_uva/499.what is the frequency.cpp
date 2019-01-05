#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>

using namespace std;

int main(){
    int alp[52],max = 0;
    string te;

    while (getline(cin,te)){
        for(int i = 0;i < 52;i++){alp[i] = 0;}

        for(int i = 0;i < te.size();i++){
                if(te[i] == '\n')break;
                else if(te[i] < 91 && te[i] > 64){alp[te[i]-65]++;}
                else if(te[i] > 96 && te[i] < 123){alp[te[i]-71]++;}
                else continue;}

        for(int i = 0;i < 52;i++){if(alp[i] > max)max = alp[i];}
        for(int i = 0;i < 52;i++){
                if(alp[i] == max){
                    if(i < 26){printf("%c",i+65);}
                    else {printf("%c",i+71);}
                    }
        }printf(" %d\n",max);

        max = 0;

    }

    return 0;
}
