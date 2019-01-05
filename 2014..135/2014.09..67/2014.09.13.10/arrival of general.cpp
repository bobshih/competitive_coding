#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;scanf("%d",&n);
    int num[103],MAx = 0,MIN = 100000,IM,im;
    for(int i = 0;i < n;i++){
        scanf("%d",&num[i]);
        if(num[i] > MAx){MAx = num[i];IM = i;}
        if(num[i] <= MIN){MIN = num[i];im = i;}
    }

    int ans = IM;
    if(IM > im)ans+=(n-1-im-1);
    else ans+=(n-1-im);
    printf("%d\n",ans);
    return 0;
}
