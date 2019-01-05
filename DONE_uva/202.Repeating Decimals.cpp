#include <iostream>
#include <cstdio>
#include <cstring>

#define max 100000

void divide_num(int a,int b,char c[]){
     int t = a;
     for(int i = 0;i < max;i++){
             c[i] = (10*t)/b+48;
             t = (10*t)%b;
             }
     }

class fraction{
      int integer;
      int numer;
      int denum;
      char div[max];
      char rep[4000];
      int cy;
      int move;
      
      public:
      fraction(int a,int b){integer = a/b;numer = a%b;denum = b;divide_num(numer,denum,div);}
      
      void find_rep();
      void print();
      };

int main(){
    int a,b;
    
    
    while (scanf("%d %d",&a,&b) == 2){
          fraction f(a,b);
          
          f.find_rep();
          f.print();
          }
    
    return 0;
    }
void fraction::print(){
     printf("%d/%d = %d.",numer+integer*denum,denum,integer);
     
     for(int i = 0;i < move;i++){
             printf("%c",div[i]);
             }
     printf("(");
     
     for(int i = 0;i < cy;i++){
             if(i == 50){printf("...");break;}
             printf("%c",rep[i]);}
     
     printf(")\n");
     
     printf("   %d = number of digits in repeating cycle\n\n",cy);
     }

void fraction::find_rep(){
     cy = 1;
     move = 0;
     int pro = 0;
     
     again:
     pro = 0;
     for(int i = 0;i < cy;i++){
             rep[i] = div[i+move];}
     for(int i = 0;i < 5;i++){
             if(strncmp(rep,div+i*cy+move,cy) != 0){pro = 1;move++;break;}
             }
     
     if(pro != 1){return;}
     if(move == 6){move = 0;cy++;}
     if(cy == 4000){printf("¦³°ÝÃD\n");}
     goto again;
     }
