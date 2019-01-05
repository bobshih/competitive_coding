#include <iostream>
#include <cstdio>

using namespace std;

bool fit(int &a,int &b,int &c,int &d,int &e,int &f){
    int t;

    //存在相等的情況
    if(a*c == e && b*d <= f)return true;
    if(a*d == e && b*c <= f){
        t = c;c = d;d = t;
        return true;}
    if(a*c == f && b*d <= e){
        t = e;e = f;f = t;
        return true;}
    if(a*d == f && b*c <= e){
        t = e;e = f;f = t;
        t = c;c = d;d = t;
        return true;}

    if(b*d == f && a*c <= e)return true;
    if(b*c == f && a*d <= e){
        t = c;c = d;d = t;
        return true;}
    if(b*d == e && a*c <= f){
        t = e;e = f;f = t;
        return true;}
    if(b*c == e && a*d <= f){
        t = e;e = f;f = t;
        t = c;c = d;d = t;
        return true;}

    //不存在相等的情況
    if(a*c < e && b*d < f)return true;
    if(a*d < e && b*c < f){
        t = c;c = d;d = t;
        return true;
    }
    if(a*c < f && b*d < e){
        t = a;a = b;b = t;
        t = c;c = d;d = t;
        return true;
    }
    if(a*d < f && b*c < e){
        t = a;a = b;b = t;
        return true;
    }
    return false;
}

int cut(int a,int b){
    if(a != 1){return 1+(b-1)+cut(a-1,b);}
    else {return b-1;}
}

int main()
{
    int a,b,c,d,e,f;

    while(scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f) == 6){
        if(a+b+c+d+e+f == 0)break;

        int minimum = 0;
        if(!fit(a,b,c,d,e,f)){
            printf("The paper is too small.\n");continue;
        }
        //printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);
        if(a*c != e){minimum++;e = a*c;}
        if(b*d != f){minimum++;f = b*d;}

        minimum += cut(a,b);
        printf("The minimum number of cuts is %d.\n",minimum);
    }
    return 0;
}
