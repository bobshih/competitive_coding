#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int test,book,clearT;

const int y[5] = {365, 365, 365, 366};
const int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const int m_leap[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct date{
    int year;
    int month;
    int day;
    int hour;
    int minute;
    bool check;

    void add(int m){
        minute += m;

        int carry = 0;
        if(minute >= 60){
            carry = minute/60;
            minute %= 60;
        }

        if(carry != 0){
            hour += carry;
            carry = 0;
            if(hour > 23){
                carry = 1;
                hour -= 24;
            }
        }

        if(carry != 0){
            day++;
            carry = 0;
            if(year == 2016){
                if(day > m_leap[month-1]){
                    day = 1;
                    carry = 1;
                }
            }else {
                if(day > mon[month-1]){
                    day = 1;
                    carry = 1;
                }
            }
        }

        if(carry == 1){
            month++;
            carry = 0;
            if(month > 12){
                month = 1;
                carry = 1;
            }
        }

        if(carry == 1){
            year++;
        }
    }
}Date[200010];

bool cmp(date a, date b){
    if(a.year != b.year){
        return a.year < b.year;
    }else if(a.month != b.month){
        return a.month < b.month;
    }else if(a.day != b.day){
        return a.day < b.day;
    }else if(a.hour != b.hour){
        return a.hour < b.hour;
    }else if(a.minute != b.minute){
        return a.minute < b.minute;
    }else {//if(a.check != b.check){
        return (int)a.check < (int)b.check;
    }
    //return false;
}

int main()
{
    freopen("months.in", "r", stdin);
    scanf("%d", &test);

    char t[100];
    while(test--){
        scanf("%d %d", &book, &clearT);
        for(int i = 0;i < book;i++){
            date in,out;
            in.check = 1;
            out.check = 0;
            scanf("%s %d-%d-%d %d:%d %d-%d-%d %d:%d", t, &in.year, &in.month, &in.day, &in.hour, &in.minute, &out.year, &out.month, &out.day, &out.hour, &out.minute);

            //printf("check in is %d-%d-%d %d:%d\n", in.year, in.month, in.day, in.hour, in.minute);
            //printf("check out is %d-%d-%d %d:%d\n", out.year, out.month, out.day, out.hour, out.minute);
            out.add(clearT);
            Date[i*2] = in;
            Date[i*2+1] = out;
        }
        //cout <<"book = "<<book<<endl;
        sort(Date, Date+book*2, cmp);
        //cout <<"haha"<<endl;
        int all = 0, emp = 0;
        for(int i = 0;i < book*2;i++){
            if(Date[i].check == 1){
                if(emp == 0){
                    all++;
                }else {
                    emp--;
                }
            }else {
                emp++;
            }
            //printf("%d-%d-%d %d:%d check = %d\n", Date[i].year, Date[i].month, Date[i].day, Date[i].hour, Date[i].minute, Date[i].check);
        }

        printf("%d\n", all);
    }


    return 0;
}
