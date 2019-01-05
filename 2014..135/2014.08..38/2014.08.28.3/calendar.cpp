#include <iostream>
#include <cstdio>
using namespace std;

int y,m,d;
int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
int month_leap[12] = {31,29,31,30,31,30,31,31,30,31,30,31};

void go(int day){
    d = day;
    if(y%4 != 0 || (y%100 == 0 && y%400 != 0)){
        for(int i = 0;i < 12;i++){
            d-=month[i];
            if(d <= 0){
                m = i+1;
                d += month[i];
                return ;
            }
        }
        y++;m = 1;
    }else {
        for(int i = 0;i < 12;i++){
            d-=month_leap[i];
            if(d <= 0){
                m = i+1;
                d+=month_leap[i];
                return ;
            }
        }
        y++;m = 1;
    }
}

int main()
{
    int day;

    while(scanf("%d",&day)){
        if(day == -1)break;
        int weekday = day - day/7*7 + 6;
        if(weekday > 7)weekday -= 7;
        day++;

        for(int i = 2000;i < 10000;i++){
            //cout <<"year is "<<i<<" days is ";
            //printf("%4d\n",day);
            if(day < 367){y = i;break;}
            if(i%4 == 0 && !(i%100 == 0)){
                day -= 366;
            }else if(i%100 == 0){
                if(i%400 == 0){day -= 366;}
                else day -= 365;
            }else {day -= 365;}
        }

        go(day);
        printf("%d-%02d-%02d ",y,m,d);
        switch(weekday){
            case 1:
                printf("Monday\n");
                break;
            case 2:
                printf("Tuesday\n");
                break;
            case 3:
                printf("Wednesday\n");
                break;
            case 4:
                printf("Thursday\n");
                break;
            case 5:
                printf("Friday\n");
                break;
            case 6:
                printf("Saturday\n");
                break;
            case 7:
                printf("Sunday\n");
                break;
        }
    }



    return 0;
}
