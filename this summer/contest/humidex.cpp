#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
#define ex 2.718281828

double find_H(double t,double d){
    return t + 0.5555*(6.11*exp((5417.7530*(1/273.16 - 1/(d+273.16)))) - 10.0);
}

double find_T(double d,double h){
    return h - 0.5555*(6.11*exp((5417.7530*(1/273.16 - 1/(d+273.16)))) - 10.0);
}

double find_D(double t,double h){
    double temp = h-t;
    temp /= 0.5555;
    temp += 10.0;
    temp /= 6.11;
    double tt = log(temp);
    tt /= 5417.753;
    tt = 1/273.16 -tt;
    return 1/tt - 273.16;
}

int main()
{
    char c1,c2;
    double d1,d2;
    double T,D,H;

    while(scanf("%c",&c1)){
        if(c1 =='E'){break;}
        else {scanf("%lf %c %lf",&d1,&c2,&d2);}
        getchar();

        switch(c1){
            case 'T':
                T = d1;
                if(c2 == 'D'){D = d2;H = find_H(T,D);}
                else {H = d2;D = find_D(T,H);}
                break;
            case 'D':
                D = d1;
                if(c2 == 'T'){T = d2;H = find_H(T,D);}
                else {H = d2;T = find_T(D,H);}
                break;
            case 'H':
                H = d1;
                if(c2 == 'D'){D = d2;T = find_T(D,H);}
                else {T = d2;D = find_D(T,H);}
                break;
        }

        printf("T %.1f D %.1f H %.1f\n",T,D,H);
    }

    return 0;
}
