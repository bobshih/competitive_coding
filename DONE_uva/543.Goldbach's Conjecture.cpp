#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int pr[200];

bool ispr(int a){
     for(int i = 0;pr[i] <= pow(a,0.5);i++){
             if(a%pr[i] == 0){return 0;}
             }
     return 1;
     }
void find_p(int a[]){
     int i = 1;
     int count = 3;
     int flag = 0;

     a[0] = 2;

     while (i < 200){
           for(int j = 2;j <= pow(count,0.5);j++){
                   if(count%j == 0){flag = 1;break;}
                   }

           if(flag == 1){flag = 0;count++;}
           else {flag = 0;a[i] = count;count++;i++;}

           }
     //for(i = 0;i < 200;i++){printf("%d",a[i]);}
     }
int conjecture(int a){
    for(int i = 0;i < 100;i++){
            if(a < pr[i]){break;}
            if(ispr(a-pr[i])){return a-pr[i];}
            }
        return -1;
    }

int main(){
    int a;
    int b;
    find_p(pr);//for(int i = 0;i< 200;i++){printf("%d\n",pr[i]);}

    while (scanf("%d",&a) == 1){
          if(a == 0){break;}

          b = conjecture(a);
          if(b == -1){printf("Goldbach's conjecture is wrong.\n");continue;}
          printf("%d = %d + %d\n",a,a-b,b);
          }

    return 0;
    }
