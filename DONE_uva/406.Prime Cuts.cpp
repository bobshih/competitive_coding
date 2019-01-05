#include <iostream>
#include <cstdio>

using namespace std;

void find_p(int a[]);
void print(int n,int c,int a[]);

int main(){
    int c,n;
    int prime[200];

    find_p(prime);
    //for(int i = 0;i < 200;i++){printf("%d\t%d\n",i,prime[i]);}
    while (scanf("%d %d",&n,&c) == 2){

          print(n,c,prime);

          }

    return 0;
    }

void print (int n,int c,int a[]){
     printf("%d %d:",n,c);

     if(n == 0 || c == 0){printf("\n\n");return;}

     int center,flag = 0;
     int l;
     for(int i = 0;i < 200;i++){
             if(a[i] > n){l = i;break;}}

     if(l%2 == 1){flag = 1;}
     center = l/2;
     //cout <<center<<endl;
     for(int i = center-c+flag;i < center+c;i++){
        if(i < 0){i = 0;}
        if(i == l){break;}
        printf(" %d",a[i]);
     }


     printf("\n\n");
     }

void find_p(int a[]){
     int i = 2;
     int count = 3;
     int flag = 0;

     a[0] = 1;
     a[1] = 2;

     while (i < 200 && count < 1501){
           for(int j = 2;j <= count/2;j++){
                   if(count%j == 0){flag = 1;break;}
                   }

           if(flag == 1){flag = 0;count++;}
           else {flag = 0;a[i] = count;count++;i++;}
           }
     for(;i < 200;i++){a[i] = 0;}
     }
