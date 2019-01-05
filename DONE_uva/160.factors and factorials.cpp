#include <iostream>
#define N 100

using namespace std;

bool prime(int a){
     if(a == 2)return 1;
     for(int i = 2;i <= a/2;i++){
             if(a%i == 0){return 0;}
             }
     return 1;
     }

//void cle(int a[]){for(int i = 0;i < N;i++){a[i] = 0;}}

void factors(int a,int a_a[]){
     int temp = a;
     //cout <<temp<<"\tin\n";

     for(int i = 2;i < N;i++){
             if(a_a[i-1] != 0){
                       if(temp % i == 0){a_a[i-1]++;temp = temp/i;i--;}
                       }
             if(temp == 1){break;}
             }
     //cout <<temp<<"\tout\n";
     }

void print(int a,int a_a[]){
     int count = 0;
     //for(int i = 0;i < N;i++){cout <<a_a[i]<<"\t";}cout <<endl;system("pause");
     if(a < 10){cout <<"  ";}
     else if(a != 100){cout <<" ";}
     cout <<a<<"! =";
     for(int i = 0;i < N;i++){
             if(a_a[i] != 0){count++;if(count == 16){cout <<"\n      ";}
                       if(a_a[i] < 10){cout <<"  "<<a_a[i];}
                       else {cout <<" "<<a_a[i];}}
             }
     cout <<endl;
     }

int main(){
    int a;
    int pri[N];for(int i = 0;i < N;i++){pri[i] = 0;}
    //for(int i = 0;i < N;i++){cout <<pri[i]<<"\t";}cout <<endl;system("pause");
    
    while (scanf("%d",&a)){//print(a,pri);
          if(a == 0)break;
          for(int i = 2;i <= a;i++){
                  //cout <<"!\t";
                  if(prime(i)){pri[i-1]++;}
                  else {factors(i,pri);}
                  }
          print(a,pri);
          for(int i = 0;i < N;i++){pri[i] = 0;}
          }
    
    return 0;
    }
