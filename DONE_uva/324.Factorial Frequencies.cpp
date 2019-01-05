#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

void muilt(char a[],char b[],int& l,int m){
     int flag = l;

     int t,carry = 0;
     for(int i = 0;;i++){
             if(flag > 0){t = b[i]-48;}
             else {t = 0;l++;}
             t = t*m+carry;
             carry = t/10;
             a[i] = t%10+48;
             flag--;
             if(flag <= 0 && carry == 0){break;}
             }
     a[l] = '\0';
     }

char* all[366];
char te[1000];

int main(){


    all[0] = new char[2];
    all[0][0] = '1';
    all[0][1] = '\0';
    int l = 1;
    int a;
    int num[10];for(int i = 0;i < 10;i++){num[i] = 0;}

    for(int i = 1;i < 366;i++){
            muilt(te,all[i-1],l,i+1);
            //cout <<"wait";//system("pause");
            all[i] = new char[l+1];
            strcpy(all[i],te);//cout <<i+1<<"\t"<<l<<endl;
            //for(int a = 0;a <= l;a++){printf("%c",all[i][a]);}//
            }

    while(scanf("%d",&a) == 1){
        if(a == 0){break;}

        for(int i = 0;i < strlen(all[a-1]);i++){
            num[(all[(a-1)][i] - 48)]++;
        }
        //for(int b = 0;b <= strlen(all[a-1]);b++){printf("%c",all[a-1][b]);}//
        printf("%d! --\n",a);
        printf("   (0)%4d    (1)%4d    (2)%4d    (3)%4d    (4)%4d\n",num[0],num[1],num[2],num[3],num[4]);
        printf("   (5)%4d    (6)%4d    (7)%4d    (8)%4d    (9)%4d\n",num[5],num[6],num[7],num[8],num[9]);

        for(int i = 0;i < 10;i++){num[i] = 0;}
    }
    for(int i = i;i < 366;i++){delete all[i];}
    return 0;
    }
