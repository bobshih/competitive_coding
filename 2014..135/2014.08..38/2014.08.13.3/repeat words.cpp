#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int alp[26];
int re;
char temp;
int tt;
int M;


int main()
{
    n = 0;
    memset(alp,0,sizeof(alp));
    M = 0;
    re = 0;
    tt = 0;
    while(scanf("%c",&temp) != EOF){
        if(temp == '\n' && n == 0){
            //cout <<"bye\n";
            continue;
        }else if(temp == '\n'){
            //cout <<"solve\n";
            for(int i = 0;i < 26;i++){
                if(alp[i] > M)M = alp[i];
                tt += alp[i]/2;
                if(alp[i]%2 == 1)re = 1;
            }
            if(tt*2 >= M && re){
                printf("%d\n",tt*2+1);
            }else if(tt*2 > M){
                printf("%d\n",tt*2);
            }else {
                printf("%d\n",M);
            }

            tt = 0;
            re = 0;
            M = 0;
            n = 0;
            memset(alp,0,sizeof(alp));
        }else {
            n++;
            //cout <<"count\n";
            alp[temp-97]++;
        }

    }


    return 0;
}
