#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

bool prime[100001];
char lis[260];

int main()
{
    memset(prime,1,sizeof(prime));
    prime[1] = 0;
    prime[2] = 1;
    for(int i = 2;i < 320;i++){
        if(prime[i] != 0){
            for(int a = i+1;a < 100001;a++){
                if(a%i == 0)prime[a] = 0;
            }
        }
    }
    //for(int i = 1;i < 100001;i++){
    //    if(prime[i])printf("%d ",i);
    //}cout <<endl;

    while(scanf("%s",lis) != EOF){
        if(strlen(lis) == 1 && lis[0] == '0')break;
        int p = 0,pos[260];
        int maxmum = 0;
        for(int i = 0;i < strlen(lis);i++){
            int a = lis[i]-'0';
            if(prime[a] && a > maxmum)maxmum = a;
            if(a%2 == 1){
                pos[p] = i;p++;
            }
        }

        for(int a = 0;a < p;a++){
            int temp = lis[pos[a]]-'0';
            for(int i = 1;i < 5;i++){
                if(pos[a]-i >= 0){
                    temp += (lis[pos[a]-i]-'0')*pow(10.0,i);
                    //cout <<"temp = "<<temp<<endl;
                    if(prime[temp] && temp > maxmum)maxmum = temp;
                }
            }
        }
        printf("%d\n",maxmum);
    }
    return 0;
}
