#include <iostream>
#include <cstdio>

using namespace std;

bool f(long long n,long long k,long long d1,long long d2){
    long long re = n-k;

    if((k-d1-d2)%3 != 0)return false;
    long long b = (k-d1-d2)/3;if(b > n/3 || b < 0)return false;
    long long a = b+d1;if(a > n/3 || a < 0)return false;
    long long c = b+d2;if(c > n/3 || c < 0)return false;

    return true;
}

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int t;
    scanf("%d",&t);
    long long n,k,d1,d2;

    while(t--){
        scanf("%I64d %I64d %I64d %I64d",&n,&k,&d1,&d2);

        if(n%3 != 0){printf("no\n");continue;}
        //if(d1+d2 > k){printf("no\n");continue;}

        if(f(n,k,d1,d2)){
            //cout <<"case 1\n";
            printf("yes\n");continue;}
        if(f(n,k,-1*d1,d2)){
            //cout <<"case 2\n";
            printf("yes\n");continue;}
        if(f(n,k,d1,-1*d2)){
            //cout <<"case 3\n";
            printf("yes\n");continue;}
        if(f(n,k,-1*d1,-1*d2)){
            //cout <<"case 4\n";
            printf("yes\n");continue;}

        printf("no\n");
    }


    return 0;
}
