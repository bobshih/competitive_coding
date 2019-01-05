#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
    int a;
    int n,m;
    char chess;
    char da[100];
    int j;

    scanf("%d",&a);
    get:
    chess = getchar();if(chess != '\n')goto get;
    //cout <<a<<endl;
    for(int i = 0;i < a;i++){
        for(j = 0;j < 100;j++){scanf("%c",&da[j]);
            if(da[j] == '\n'){break;}
        }
        for(j = 0;j < 100;j++){
            if(da[j] != ' '){chess = da[j];j++;break;}
        }
        for(;j < 100;j++){
            if(da[j] != ' '){
                if(da[j+1] == ' '){n = da[j]-48;}
                else {n = (da[j]-48)*10 + da[j+1]-48;}
                j+=2;break;
            }
        }
        for(;j < 100;j++){
            if(da[j] != ' '){
                if(da[j+1] == ' ' || da[j+1] == '\n'){m = da[j]-48;}
                else {m = (da[j]-48)*10 + da[j+1]-48;}
                break;
            }
        }

    //cout <<chess<<"\t"<<n<<"\t"<<m<<endl;

    switch (chess){
        case 'Q':
            if(n < m){printf("%d",n);}
            else printf("%d",m);
            break;
        case 'k':
            if(n*m%2 != 0){printf("%d",n*m/2+1);}
            else printf("%d",n*m/2);
            break;
        case 'r':
            if(n < m){printf("%d",n);}
            else printf("%d",m);
            break;
        case 'K':
            if(n%2 != 0 && m%2 != 0){printf("%d",(n/2+1)*(m/2+1));}
            else if(n%2 != 0){printf("%d",(n/2+1)*m/2);}
            else if(m%2 != 0){printf("%d",(m/2+1)*n/2);}
            else {printf("%d",n/2*m/2);}break;
    }printf("\n");
    }

    return 0;
}
