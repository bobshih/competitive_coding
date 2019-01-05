#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

注意的是，小小小小的細節，這題我錯過了最後一個月(五天)的部分

using namespace std;

char INDEX[19][50] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin",
"mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu","uayet"};

char INDEX_day[20][50] =  { "imix", "ik", "akbal", "kan", "chicchan",
"cimi", "manik", "lamat", "muluk", "ok",
"chuen", "eb", "ben", "ix", "mem",
"cib", "caban", "eznab", "canac", "ahau" };

int deter(char m[]){
    /*if( s == "pop" ) return 0;
    if( s == "no" ) return 1;
    if( s == "zip" ) return 2;
    if( s == "zotz" ) return 3;
    if( s == "tzec" ) return 4;

    if( s == "xul" ) return 5;
    if( s == "yoxkin" ) return 6;
    if( s == "mol" ) return 7;
    if( s == "chen" ) return 8;
    if( s == "yax" ) return 9;

    if( s == "zac" ) return 10;
    if( s == "ceh" ) return 11;
    if( s == "mac" ) return 12;
    if( s == "kankin" ) return 13;
    if( s == "muan" ) return 14;

    if( s == "pax" ) return 15;
    if( s == "koyab" ) return 16;
    if( s == "cumhu" ) return 17;
    if( s == "uayet" ) return 18;*/

    for(int i = 0;i < 19;i++){
        if(strcmp(m,INDEX[i]) == 0){return i;}
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    int test;
    scanf("%d",&test);
    printf("%d\n",test);

    int day,year,month;
    char m[40];
    int day_t,year_t,day_name;
    int all;
    string mon;

    for(int tttt = 0;tttt < test;tttt++){
        scanf("%d. %s %d",&day,m,&year);
        //cin >>mon;
        //scanf("%d",&year);
        month = deter(m);
        //cout <<"day = "<<day<<" month = "<<month<<" year = "<<year<<endl;
        all = year*365 + day + month*20;
        //cout <<"all = "<<all<<endl;
        //year_t = all/260;
        //day_name = all%20;
        //all = (all - year_t*260);
        //day_t = all%13 +1;

        printf("%d %s %d\n",(all%260)%13+1,INDEX_day[(all%260)%20],all/260);
    }


    return 0;
}
