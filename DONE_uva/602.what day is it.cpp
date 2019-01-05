#include <iostream>
#include <cstdio>

using namespace std;

int new_c[4] = {5,15,10,1582};
int mounth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int old_c[4] = {4,1,1,0};

int day_o(int a[]){
    int t = 1;
    if(a[3] == 0){t = -1;}
    
    for(int i = 1;i < a[3];i++){
            t+=365;
            if(i%4 == 0){t++;/*cout <<"舊閏年"<<i;*/}}
    t+=a[1];
    
    for(int i = 0;i < a[2]-1;i++){
            t+=mounth[i];}
    if(a[3]%4 == 0 && a[2] > 2){t++;}
    
    return t;
    }

int day_n(int a[]){
    int t = 16+30+31;;
    
    if(a[3] < 1752){return -1;}
    else if(a[3] == 1752){
         if(a[2] < 9){return -1;}
         else if(a[2] == 9){
              if(a[1] <= 13){return -1;}
              }
         }
    //cout <<"新曆\n";
    for(int i = 1583;i < a[3];i++){
            t+=365;
            if(i%4 == 0){t++;}
            if(i%100 == 0 && i%400 != 0){t--;}}
    t+=a[1];
    
    for(int i = 0;i < a[2]-1;i++){
            t+=mounth[i];}
    
    if(a[2] > 2){
    if(a[3]%4 == 0){t++;}
    if(a[3]%100 == 0 && a[3]%400 != 0){t--;}}
    
    return t;
    }
void print(int all[4],bool t);
bool exist(int a[4],int days){
     if(a[3] == 1752 && a[2] == 9 && a[1] > 2 && a[1] < 14){return 0;}
     
     switch (a[2]){
            case 1 :if(a[1] > 31 || a[1] <= 0){return 0;}break;
            case 2 :
                 if(days != -1){
                 if(a[3]%400 == 0 || (a[3]%4 == 0 && a[3]%100 != 0)){
                             if(a[1] > 29 || a[1] <= 0){return 0;}}
                 else {if(a[1] > 28 || a[1] <= 0){return 0;}}}
                 else {
                      if(a[3]%4 == 0){if(a[1] > 29 || a[1] <= 0){return 0;}}
                      else {if(a[1] > 28 || a[1] <= 0){return 0;}}
                      } break;
            case 3 :if(a[1] > 31 || a[1] <= 0){return 0;}break;
            case 4 :if(a[1] > 30 || a[1] <= 0){return 0;}break;
            case 5 :if(a[1] > 31 || a[1] <= 0){return 0;}break;
            case 6 :if(a[1] > 30 || a[1] <= 0){return 0;}break;
            case 7 :if(a[1] > 31 || a[1] <= 0){return 0;}break;
            case 8 :if(a[1] > 31 || a[1] <= 0){return 0;}break;
            case 9 :if(a[1] > 30 || a[1] <= 0){return 0;}break;
            case 10:if(a[1] > 31 || a[1] <= 0){return 0;}break;
            case 11:if(a[1] > 30 || a[1] <= 0){return 0;}break;
            case 12:if(a[1] > 31 || a[1] <= 0){return 0;}break;
            default:return 0;
            }
     return 1;
     }

int main(){
    int da[4];//月份是在2，日期是在1，年份是在3，星期則是在0 
    int days;
    int weekday;
    
    while (scanf("%d %d %d",&da[2],&da[1],&da[3]) == 3){
          if(da[2] == 0 && da[1] == 0 && da[3] == 0){break;}
          
          days = day_n(da);
          if(!exist(da,days)){print(da,0);continue;}
          
          if(days == -1){
                  days = day_o(da);
                  weekday = days%7+old_c[0];
                  if(weekday > 7){weekday -= 7;}
                  da[0] = weekday;
                  print(da,1);
                  continue;
                  }
          weekday = days%7+new_c[0];
          if(weekday > 7){weekday -= 7;}
          da[0] = weekday;
          print(da,1);
          }
    
    return 0;
    }

void print(int all[4],bool t){
     if(!t){cout <<all[2]<<"/"<<all[1]<<"/"<<all[3]<<" is an invalid date.\n";return;}
     
     switch (all[2]){
            case 1:cout <<"January ";break;
            case 2:cout <<"February ";break;
            case 3:cout <<"March ";break;
            case 4:cout <<"April ";break;
            case 5:cout <<"May ";break;
            case 6:cout <<"June ";break;
            case 7:cout <<"July ";break;
            case 8:cout <<"August ";break;
            case 9:cout <<"September ";break;
            case 10:cout <<"October ";break;
            case 11:cout <<"November ";break;
            case 12:cout <<"December ";break;}
     
     cout <<all[1]<<", ";
     cout <<all[3]<<" is ";
     
     cout <<"a ";
     switch (all[0]){
            case 1:cout <<"Monday";break;
            case 2:cout <<"Tuesday";break;
            case 3:cout <<"Wednesday";break;
            case 4:cout <<"Thursday";break;
            case 5:cout <<"Friday";break;
            case 6:cout <<"Saturday";break;
            case 7:cout <<"Sunday";break;}
     cout <<endl;
     }
