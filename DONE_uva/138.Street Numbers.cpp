#include <iostream>
#include <cstdio>

using namespace std;

long long sum (long long st,long long en){
     return ((st+en)*(en-st+1)/2);
     }

int main(){
    long long left=0,right=0;
    int count = 0;
    
    /*
    for(long long i = 1;i < 2147483647;i++){
             if(count == 10){break;}
             left = sum(1,i-1);
             for(long long j = i+2;j < 2147483647;j++){
                      right = sum(i+1,j);
                      if(left == right){cout <<i<<"\t"<<j<<endl;count++;i = 5*i;}
                      else if(right > left){break;}
                      }
             right = 0;
             }*/
    
    cout <<"         6         8\n"
         <<"        35        49\n"
         <<"       204       288\n"
         <<"      1189      1681\n"
         <<"      6930      9800\n"
         <<"     40391     57121\n"
         <<"    235416    332928\n"
         <<"   1372105   1940449\n"
         <<"   7997214  11309768\n"
         <<"  46611179  65918161";
    
    //system("pause");
    return 0;
    }
