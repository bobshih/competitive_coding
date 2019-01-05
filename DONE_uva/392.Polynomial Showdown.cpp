#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

void print(int a[]){
     int flag = 0;
     int count = 0;
     char sign[9];
     
     for(int i = 8;i >= 0;i--){
             if(a[i] > 0){sign[i] = '+';}
             else if(a[i] < 0){sign[i] = '-';a[i] *= -1;}
             else {sign[i] = 0;}
             }
     
     for(int i = 8;i > 0;i--){
             if(sign[i] == 0){continue;}
             else if(flag == 0 && i != 1){flag = 1;
                  if(sign[i] == '-'){
                             if(a[i] != 1){cout <<a[i]*-1<<"x^"<<i;}
                             else {cout <<"-x^"<<i;}}
                  else {
                       if(a[i] != 1){cout <<a[i]<<"x^"<<i;}
                       else {cout <<"x^"<<i;}
                       }
                  }
             else if(i != 1){//cout <<" "<<sign[i]<<" "<<a[i]<<"x^"<<i;
                  if(a[i] == 1 || a[i] ==-1){cout <<" "<<sign[i]<<" "<<"x^"<<i;}
                  else {cout <<" "<<sign[i]<<" "<<a[i]<<"x^"<<i;}
                  }
             else if(i == 1){
                  if(flag == 0){flag = 1;
                          if(sign[i] == '-'){
                                     if(a[i] != 1){cout <<a[i]*-1<<"x";}
                                     else {cout <<"-x";}}
                          else {
                               if(a[i] != 1){cout <<a[i]<<"x";}
                               else {cout <<"x";}
                               }
                          }
                  else {
                       if(a[i] == 1 || a[i] ==-1){cout <<" "<<sign[i]<<" "<<"x";}
                       else {cout <<" "<<sign[i]<<" "<<a[i]<<"x";}
                       }
                  
                  }
             
             }
     if(flag == 0 && sign[0] == '-'){cout <<sign[0]<<a[0]<<endl;}
     else if(flag == 0){cout <<a[0]<<endl;}
     else if(flag == 1 && sign[0] != 0){cout <<" "<<sign[0]<<" "<<a[0]<<endl;}
     else if(sign[0] == 0 && flag == 1){cout <<endl;}
     else if(sign[0] == 0){cout <<"0"<<endl;}
     }

int main(){
    int pol[9];
    
    while (scanf("%d %d %d %d %d %d %d %d %d",&pol[8],&pol[7],&pol[6],&pol[5],&pol[4],&pol[3],&pol[2],&pol[1],&pol[0]) != EOF){
          
          print(pol);
          
          } 
    
    return 0;
    }
