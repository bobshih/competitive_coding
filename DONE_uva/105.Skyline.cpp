#include <iostream>
#include <cstdio>

using namespace std;

void make_skyline(int sky[],int left,int high,int right){
     for(int i = left*2;i <= right*2;i++){
             if(sky[i] < high){sky[i] = high;}
             }
     
     }

void print(int sky[],int f,int c){
     int temp = 0;
     
     for(int i = 0;i <= f;i++){
             if(sky[i] != temp){printf("%d %d ",i/2,sky[i]);temp = sky[i];}
             }
     if(sky[f+1] != temp){printf("%d %d",(f+1)/2,sky[f+1]);temp = sky[f+1];}
     printf("\n");
     //printf("%d %d",f,0);
     }

int main(){
    int left,right,high;
    int skyline[20002];for(int i = 0;i < 20002;i++){skyline[i] = 0;}
    int far = 0,close = 20001;
    
    
    while (scanf("%d %d %d",&left,&high,&right) == 3){
          
          //if(high == 0){break;}
          
          if(left*2 < close){close = left*2;}
          if(right*2 > far){far = right*2;}
          make_skyline(skyline,left,high,right);
          
          }
    
    //for(int i = 0;i < 20002;i++){printf("%d %d\n",i,skyline[i]);}
    //cout <<endl;system("pause");
    print(skyline,far,close);
    
    //system("pause");
    return 0;
    }
