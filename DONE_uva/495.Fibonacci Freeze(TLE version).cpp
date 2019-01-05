#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

char a90[20] = {'0','2','1','6','1','8','0','7','3','4','9','1','7','6','0','0','8','8','2','\0'};
char a91[20] = {'9','0','3','0','3','5','5','7','3','0','1','6','6','4','0','0','6','6','4','\0'};

void sum_c(char a[],char b[]){
     int carry = 0;
     for(int i = 0;i < 2000;i++){
             if(a[i] == '\0' && b[i] != '\0'){
                     a[i] = b[i]+carry;a[i+1] = '\0';
                     //if(a[i] > 57){a[i]-=10;a[i+1] = '1';a[i+2] = '\0';}
                             break;}
             else if(a[i] == '\0'){
                  if(carry == 1){a[i] = '1';a[i+1] = '\0';}break;}
             //cout <<a[i]<<" + "<<b[i];
             a[i] += (b[i]-48);a[i]+=carry;
             if(a[i] > 57){a[i] -= 10;carry = 1;}
             else {carry = 0;}
             //cout <<" = "<<a[i]<<endl;
             }
     }
void f_c(int a,char t1[],char t2[],char an[]){
     sum_c(t1,t2);
     if(a == 92){strcpy(an,t1);return;}
     else {f_c(a-1,t2,t1,an);}
     }
void p(char a[]){
     bool pr = 0;//cout <<"print out\n";
     for(int i = 1999;i >= 0;i--){//cout <<pr<<endl;;
             if(pr){printf("%c",a[i]);}
             if(a[i] == 0){pr = 1;}
             }
     printf("\n");
     }

int main(){
    int a;
    char a90_t[2000];for(int i = 0;i < 2000;i++){if(i < 20){a90_t[i] = a90[i];}else {a90_t[i] = 1;}}
    char a91_t[2000];strncpy(a91_t,a91,20);for(int i = 20;i < 2000;i++){a91_t[i] = 1;}
    char an[2000];for(int i = 0;i < 2000;i++){an[i] = 1;}
    long long tp[91];
    
    tp[0] = 1;tp[1] = 1;
    for(int i = 2;i < 91;i++){tp[i] = tp[i-1]+tp[i-2];}
    
    while (scanf("%d",&a) == 1){
            //for(a = 1;a<5000;a++){
          printf("The Fibonacci number for %d is ",a);
          
          if(a <= 91){printf("%lld\n",tp[a-1]);}
          else {
               f_c(a,a90_t,a91_t,an);p(an);
               strcpy(a90_t,a90);strcpy(a91_t,a91);for(int i = 0;i < 2000;i++){an[i] = 1;}}
          //cout <<asd<<"total\n";
          }
    
    return 0;
    }
