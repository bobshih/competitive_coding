#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[26];
long long n,k;

int main(){
    memset(a,0,sizeof(a));
    scanf("%I64d %I64d",&n,&k);
    //scanf("%s",lis);
    //printf("%I64d\n",2500000000);

    char tt;
    //a[0] = 50000;
    //a[1] = 50000;
    for(int i = 0;i < n;i++){
        scanf(" %c",&tt);
        a[tt-'A']++;
    }
    sort(a,a+26);

    long long ans = 0;
    int pp = 25;
    if(n == k){
        for(int i = 0;i < 26;i++){
            ans += a[i]*a[i];
        }
        printf("%I64d\n",ans);
        return 0;
    }

    while(k > 0){
        //cout <<"k = "<<k<<" ans = "<<ans<<endl;
        if(a[pp] < k){ans += a[pp]*a[pp];k-=a[pp];pp--;}
        else {ans += k*k;k-=a[pp];pp--;}
        //cout <<"after k = "<<k<<" ans = "<<ans<<endl;
    }
    printf("%I64d\n",ans);
    return 0;
}
