#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

void sum_c(char an[],int &l,char a[],char b[]){
     int carry = 0;
     for(int i = 0;i < l;i++){
             if(a[i] == '\0' && b[i] == '\0'){
                     if(carry == 1){an[i] = '1';l++;an[i+1] = '\0';break;}
                     an[i] = '\0';
                     //cout <<i<<"­n²×¤î¤F"<<an[i]<<endl;
                             break;}
             else if(b[i] == '\0'){an[i] = a[i] + carry;an[i+1] = '\0';break;}
             
             an[i] = a[i] + (b[i]-48) + carry;
             if(an[i] > 57){an[i] -= 10;carry = 1;}
             else {carry = 0;}
             //cout <<an[i]<<" = "<<a[i]<<" + "<<b[i]<<endl;
             }
     }
void p(char a[],int l){
     bool pr = 0;//cout <<"print out\n";
     for(int i = l;i >= 0;i--){//cout <<pr<<endl;;
             if(pr){printf("%c",a[i]);}
             if(a[i] == 0){pr = 1;}
             }
     printf("\n");
     }
char *t[5000];
int main(){
    
    int a;
    int l1 = 2,l2 = 2;
    char temp[1100];
    int l = 2;
    
    t[0] = "1";
    t[1] = "1";
    
    //cout <<t[0][0]<<"\t"<<(int)t[0][1]<<"\t"<<t[1][0]<<"\t"<<(int)t[1][1]; 
    for(int i = 2;i < 5000;i++){
            sum_c(temp,l,t[i-1],t[i-2]);
            
            t[i] = new char[l];
            strcpy(t[i],temp);
            }
    
    while (scanf("%d",&a) == 1){
          printf("The Fibonacci number for %d is ",a);
          if(a == 0){printf("%d\n",0);continue;}
          p(t[a-1],strlen(t[a-1]));
          }
    
    //sum_c(t,20,a90,a91);
    //p(t,20);
    
    //system("pause");
    return 0;
    }
