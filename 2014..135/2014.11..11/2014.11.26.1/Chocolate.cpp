#include <cstdio>
#include <iostream>

using namespace std;

struct rect{
    long long l, h;
    long long two;
    long long three;
    long long  base;
    long long step;

    rect(long long lan, long long high){
        two = three = 0;
        l = lan;
        h = high;
        step = 0;

        long long temp_l = lan, temp_h = high;
        bool flag;
        int i = 0;
        do{
            //cout <<temp_h<<" "<<temp_l<<endl;
            flag = 0;
            if(temp_l%2 == 0){
                flag = 1;
                temp_l/=2;
                two++;
            }
            if(temp_l%3 == 0){
                flag = 1;
                temp_l = temp_l/3;
                three++;
            }
            if(temp_h%3 == 0){
                flag = 1;
                temp_h = temp_h/3;
                three++;
            }
            if(temp_h%2 == 0){
                flag = 1;
                temp_h/=2;
                two++;
            }
        }while(flag);
        //cout <<"END "<<temp_h<<" "<<temp_l<<endl;
        base = temp_h*temp_l;
    }

    void solve(long long ans_two, long long ans_three){
        if(three > ans_three){
            while(l%3 == 0 && three > ans_three){
                l = l/3*2;
                three--;
                two++;
                step++;
            }
            while(h%3 == 0 && three > ans_three){
                h = h/3*2;
                three--;
                two++;
                step++;
            }
        }
        if(two > ans_two){
            while(l%2 == 0 && two > ans_two){
                l /= 2;
                two--;
                step++;
            }
            while(h%2 == 0 && two > ans_two){
                h /= 2;
                two--;
                step++;
            }
        }
    }
};

int main(){
    long long l1, l2, h1, h2;
    scanf("%I64d %I64d %I64d %I64d", &l1, &h1, &l2, &h2);
    rect a(l1, h1), b(l2, h2);
    if(a.base != b.base){
        printf("-1\n");
        return 0;
    }

    long long ans_three = min(a.three, b.three);
    rect aa = a;
    rect bb = b;

    aa.two += aa.three - ans_three;
    bb.two += bb.three - ans_three;
    long long ans_two = min(aa.two, bb.two);

    a.solve(ans_two, ans_three);
    b.solve(ans_two, ans_three);

    printf("%I64d\n",a.step + b.step);
    printf("%I64d %I64d\n%I64d %I64d\n", a.l, a.h, b.l, b.h);

    return 0;
}
