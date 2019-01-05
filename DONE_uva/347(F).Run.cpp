#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void plus_1(char a[],int& end); 
bool del(char b[],int a);
bool repeat(char a[],int e);
int run(char a[],int& end){
    char temp;
    char b[9];
    int i,ag = 0;
    again:
    
    if(repeat(a,end)){/*for(int i = 0;i < end;i++){printf("%c",a[i]);};cout <<"\t";*/goto Plus_One;} 
    
    temp = a[0];
    strcpy(b,a);del(b,temp);
    i = 0;
    
    /*cout <<"data\n";
    for(int i = 0;i < end;i++){cout <<a[i];}
     cout <<endl;
    cout <<"end = "<<end<<endl;*/
    while (1){
          
          i += (temp-48);
          if(i >= end){/*cout <<"超過範圍";*/i -= end;/*cout <<"i = "<<i<<endl;*/}
          if(i >= end){i -= end;}
          if(i >= end){i -= end;}
          if(i >= end){i -= end;}
          if(i >= end){i -= end;}
          if(i >= end){i -= end;}
          if(i >= end){i -= end;}
          if(i >= end){i -= end;}
          if(i >= end){i -= end;}
          if(i >= end){i -= end;}
          temp = a[i];//cout <<"抓到"<<temp<<"了\n"; 
          if(!del(b,temp) && b[0] != '\n'){;goto Plus_One;}
          if(b[0] == '\n'){//cout <<"b 沒了 ag = "<<ag<<endl;
                  if(ag == 0 && temp != a[0]){/*cout <<"final\n";*/ag = 1;continue;}
                  else if(ag == 1 && temp == a[0]){break;}
                  else {ag = 0;goto Plus_One;}}
          }
    
    return temp;
    
    Plus_One:
    //printf("加一囉\n");
    plus_1(a,end);
    goto again;
    }
void zero_out(char a[],int& e){
     int j = 0,te = e;
     for(int i = 0;i < e;i++){
             if(a[j] == '0'){j++;continue;}
             else {break;}
             }
     e -= j;//cout <<j<<endl;
     for(int i = 0;j <= te;j++,i++){//cout <<a[i]<<"\t"<<a[j]<<endl;
             a[i] = a[j];}
     a[e] = '\n';
     }

int main(){
    char a[100];
    int end;
    int cases = 0;
    int answer;
    int al= 0;
    int temp;
    char t;
    int l;
    
    while (scanf("%ld",&temp) == 1){
          /*for(int i = 0;i < 100;i++){
                  scanf("%c",&a[i]);
                  if(a[i] == '\n'){end = i;cases++;break;}}
          
          if(a[0] == '0' && a[1] == '\n'){break;}
          
          if(a[0] == '0'){zero_out(a,end);}*/
          
          if(temp == 0){break;}//cout <<temp<<endl;system("pause");
          cases++;
          for(int i = 0;i < 10;i++){
                  a[i] = temp%10+48;//cout <<a[i];system("pause");
                  temp = temp/10;
                  if(temp == 0){end = i;break;}
                  }a[end+1] = '\n';
          //for(int i = 0;i <= end+1;i++){printf("%c",a[i]);};system("pause");
          
          for(int i = 0;i <= end/2;i++){
                  //printf("%c\t%c",t,a[0]);system("pause");
                  t = a[i];
                  a[i] = a[(end-i)];
                  a[(end-i)] = t;
                  }
          
          
          /*for(int i = 0;i <= end+1;i++){printf("%c",a[i]);};
          cout <<"end = "<<end<<endl;*/
         end++;
          run(a,end);
          printf("case %d: ",cases);
          for(int i = 0;i < end;i++){printf("%c",a[i]);};cout <<endl;
          //cout <<"case "<<cases<<": "<<answer;
          }
    
    //system("pause");
    return 0;
    }

bool repeat(char a[],int e){
     if(a[0] == '\n'){return 0;}
     
     //char t = a[0];
     for(int i = 1;i < e;i++){
             if(a[0] == a[i]){/*cout <<a[0]<<"重複了\t";*/return 1;}
             }
     
     return repeat(a+1,e);
     }
bool del(char b[],int a){int d=-1;
     for(int i = 0;b[i] != '\n';i++){
             if(b[i] == a){/*cout <<"success delete\n";*/d = i;break;}
             }
     if(d == -1){return 0;}
     for(int i = d;b[i] != '\n';i++){
             b[i] = b[i+1];
             }
     return 1;
     }
void plus_1(char a[],int& end){
     int carry = 0;
     plus:
     a[end-1]++;
     for(int i = end-1;i >= 1;i--){
             a[i] += carry;
             if(a[i] > 57){a[i] = '0';carry = 1;}
             else {carry = 0;}
             
             }
     
     a[0] += carry;
     if(a[0] == 58){end++;a[0] = 48;
             for(int i = end;i >= 1;i--){
                     a[i] = a[i-1];
                     }a[0] = '1';
             }
     if(repeat(a,end)){/*for(int i = 0;i < end;i++){printf("%c",a[i]);};cout <<"\t";*/goto plus;}
     }
