#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>

using namespace std;

bool check(char da[],int a,int m){
    int syllables = 0;

    for(int i = 0;i < a;i++){
        if(da[i] == 'a' || da[i] == 'e' || da[i] == 'i' ||da[i] == 'o' || da[i] == 'u' ||da[i] == 'y'){syllables++;
        if(da[i+1] == 'a' || da[i+1] == 'e' || da[i+1] == 'i' ||da[i+1] == 'o' || da[i+1] == 'u' ||da[i+1] == 'y'){syllables--;}}
    }

    switch (m){
        case 1:if(syllables == 5){return 0;}return 1;
        case 2:if(syllables == 7){return 0;}return 1;
        case 3:if(syllables == 5){return 0;}return 1;
    }
}

int main(){
    char part[200];
    int flag1 = 0,flag2 = 0;
    int i;
    string tt;

    while (1){
        for(i = 0;i < 200;i++){
            part[i] = getchar();
            if(part[i] == '/'){break;}
        }
        if(part[0] == 'e' && part[1] == '/'){
                for(int i = 2;i < 6;i++){part[i] = getchar();}
                if(part[2] == 'o' && part[3] == '/' && part[4] == 'i' && part[5] == '\n'){break;}
        }
        if(check(part,i,1)){printf("1\n");getline(cin,tt);continue;}

        for(i = 0;i < 200;i++){
            part[i] = getchar();
            if(part[i] == '/'){break;}
        }
        if(check(part,i,2)){printf("2\n");getline(cin,tt);continue;}

        for(i = 0;i < 200;i++){
            part[i] = getchar();
            if(part[i] == '\n'){break;}
        }
        if(check(part,i,3)){printf("3\n");continue;}
        else {printf("Y\n");}

        }



    return 0;
}
