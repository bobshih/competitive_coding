#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

int pos;

void turn_into_bin(int a,int b[]);
void convert_eg(long long a,bool e,int n);
void mulit(int a,int b,int bin[]){
     for(int i = 0;bin[i] != -1;i++){
             pos = 0;
             convert_eg((int)pow(2.0,i),0,0);
             if(bin[i] == 1){printf(" *");pos+=2;}//printf("%d",pos);system("pause");
             convert_eg(pow(2.0,i)*a,1,34-pos);printf("\n");
             }
     printf("The solution is: ");convert_eg((long long)a*b%100000,0,0);
     printf("\n");
     }

int main(){
    int A = 0,B = 0;
    char t;
    int binary[18];
    
    while (t=getchar()){
          do{
             if(t == '|'){A+=1;}
             else if(t == 'n'){A+=10;}
             else if(t == '9'){A+=100;}
             else if(t == '8'){A+=1000;}
             else if(t == 'r'){A+=10000;}
             else if(t == '\n'){break;}
             //else if(t == ' '){continue;}
             }while (t=getchar());
          if(A == 0 && t == '\n'){break;}
          
          t = getchar();
          do{
             if(t == '|'){B+=1;}
             else if(t == 'n'){B+=10;}
             else if(t == '9'){B+=100;}
             else if(t == '8'){B+=1000;}
             else if(t == 'r'){B+=10000;}
             else if(t == '\n'){break;}
             else if(t == ' '){continue;}
             }while (t=getchar());
          //cout <<A<<"\t"<<B<<endl;
          
          turn_into_bin(B,binary);
          //for(int i = 0;binary[i] != -1;i++){printf("%d",binary[i]);}
          //convert_eg(A,1);
          mulit(A,B,binary);
          A = 0;B = 0;
          
          }
    
    return 0;
    }
void turn_into_bin(int a,int b[]){
     int temp = a;
     for(int i = 0;temp != 0;i++){
             b[i] = temp%2;
             temp = temp/2;
             b[i+1] = -1;
             }
     }
void convert_eg(long long a,bool e,int n){
     long long t = a;//cout <<t<<endl;
     for(int j = 0;t != 0;j++){
             if(!(t%10)){t = t/10;continue;}
            for(int i = 0;i < t%10;i++){
                    if (e){e = 0;for(int l = 0;l < n;l++){printf(" ");}
                       if(j == 0){printf("%c",'|');}
                       else if(j == 1){printf("%c",'n');}
                       else if(j == 2){printf("%c",'9');}
                       else if(j == 3){printf("%c",'8');}
                       else if(j == 4){printf("%c",'r');}}
                    else {pos++;
                         if(j == 0){printf("%c",'|');}
                         else if(j == 1){printf("%c",'n');}
                         else if(j == 2){printf("%c",'9');}
                         else if(j == 3){printf("%c",'8');}
                         else if(j == 4){printf("%c",'r');}}
                    }
            t = t/10;if(!t){break;}
            if(j == 4){break;}
            printf(" ");pos++;
            }
     }
