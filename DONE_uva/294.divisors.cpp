#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
    long long l,h;
    long long n;
    long long max = 0;
    long long pos,count = 0;
    int t;

    scanf("%lld",&n);
    for(int a = 0;a < n;a++){
            scanf("%lld %lld",&l,&h);
            if(h == 0){pos = 0;max = -1;goto p;}
            for(long long i = l;i <= h;i++){
                     t = (int)sqrt(i);//cout <<t<<endl;
                     for(int j = 1;j <= t;j++){
                             if(!(i%j)){count+=2;}
                             };
                     if(t*t == i){count--;}
                     //cout <<i<<"\t"<<t<<"\t"<<count<<"\n";
                     if(max < count){max = count;pos = i;};count = 0;
                     };
            p:
            printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",l,h,pos,max);
            max = 0;
            };
    //system("pause");
    return 0;
    }
