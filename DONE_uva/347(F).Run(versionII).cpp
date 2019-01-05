#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void plus_1(char a[],int& end);
bool del(char b[],int a);
bool repeat(char a[],int e){
     if(a[0] == '\n'){return 0;}

     //char t = a[0];
     for(int i = 1;i < e;i++){
             if(a[0] == a[i]){/*cout <<a[0]<<"重複了\t";*/return 1;}
             }

     return repeat(a+1,e);
     }
bool stop(char a[]){
     if(a[0]=='9' && a[1]=='9' && a[2]=='9' && a[3]=='9' && a[4]=='9' && a[5]=='9' && a[6]=='9'){return 0;}
     return 1;
     }
int run(char a[],int& end){
    char temp;
    char b[9];
    int i,ag = 0;
    again:

    if(repeat(a,end)){/*for(int i = 0;i < end;i++){printf("%c",a[i]);};cout <<"\t";*/goto Plus_One;}

    temp = a[0];
    strcpy(b,a);del(b,temp);
    i = 0;
    if(!stop(a)){return -1;}
    /*cout <<"data\n";
    for(int i = 0;i < end;i++){cout <<a[i];}
     cout <<endl;
    cout <<"end = "<<end<<endl;*/
    while (1){
          //for(int i = 0;i < end;i++){printf("%c",a[i]);};cout <<endl;system("pause");
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
          }ag = 0;

    for(i = 0;a[i] != '\n';i++){
          ag *= 10;
          ag += (a[i]-48);
          }
    //cout <<ag;system("pause");
    return ag;
    Plus_One:
    //printf("加一囉\n");
    plus_1(a,end);
    if(!stop(a)){return -1;}
    goto again;
    }

int main(){
    int all[450];
    char t[8] = {'1','2','\n',0,0,0,0,0};
    int end = 2;
    int i = 0;
    int j,cases = 0;

    for(;stop(t);plus_1(t,end)){//
                                all[i] = run(t,end);//cout <<i<<"\t在一次了"<<all[i]<<endl;
                                if(all[i] == -1){break;}
                                //if(i == 747){break;}
                                i++;
                                }
    //for(int i = 0;i < 448;i++){cout <<all[i]<<endl;}
    //cout <<t[i];system("pause");
    //cout <<i;
    //for(j = 0;j < 10;j++){cout <<all[j];system("pause");}

    while (scanf("%d",&j) == 1){cases++;
          if(j == 0){break;}
          if(j > 9682415){break;}
          printf("Case %d: ",cases);

          for(int a = 0;a<i;a++){//cout <<all[a]<<endl;
                  if(all[a] >= j){printf("%d\n",all[a]);break;}
                  }

          }

    return 0;
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
     if(!stop(a)){return;}
     if(repeat(a,end)){/*for(int i = 0;i < end;i++){printf("%c",a[i]);};cout <<"\t";*/goto plus;}
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
