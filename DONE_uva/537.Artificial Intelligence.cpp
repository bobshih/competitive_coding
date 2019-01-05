#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <cmath>

using namespace std;

void data_pro(string d,int pos,double &data){
    double t = 0;
    int i = pos;
    int flag = 0;

    while(1){
        if(d[i] == 'A' || d[i] == 'V' || d[i] == 'W'){break;}

        if(d[i] == 'M'){t *= 1000000;i++;continue;}
        else if(d[i] == 'm'){t *= 0.001;i++;continue;}
        else if(d[i] == 'k'){t*=1000;i++;continue;}
        else {}

        if(d[i] == '.'){flag = 1;}
        else if(flag == 0){t *= 10;t+=(d[i]-48);}
        else if(flag != 0){t*=pow(10.0,flag); t+=(d[i]-48);t/=pow(10.0,flag);flag++;}
        i++;//cout <<t<<endl;

    }data = t;
}

int main(){
    string pr;
    int flag = 0;
    int a = 0;
    double u = 0,p = 0,i = 0;
    int cases = 0;
    int A;

    scanf("%d",&A);getchar();
    for(int j = 0;j < A;j++){cases++;
        getline(cin,pr);
        while(1){
            if(pr[a] == 'P' && pr[a+1] == '='){flag++;data_pro(pr,a+2,p);}
            else if(pr[a] == 'U' && pr[a+1] == '='){flag++;data_pro(pr,a+2,u);}
            else if(pr[a] == 'I' && pr[a+1] == '='){flag++;data_pro(pr,a+2,i);}
            if(flag == 2){break;}
            a++;
        }

        //cout <<p<<"\t"<<u<<"\t"<<i<<endl;

        printf("Problem #%d\n",cases);

        if(p == 0){p = u*i;printf("P=%.2lfW\n",p);}
        else if(u == 0){u = p/i;printf("U=%.2lfV\n",u);}
        else if(i == 0){i = p/u;printf("I=%.2lfA\n",i);}

        p = 0;u = 0;i = 0;a = 0;flag = 0;
        printf("\n");
    }

    return 0;
}
