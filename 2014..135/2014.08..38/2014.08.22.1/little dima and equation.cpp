#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);

    int ans = 0;
    int lis[500000];
    int temp = 0;
    int tt = 100,sum;
    while(true){
        tt = pow((double)temp,a)*b + c;
        //cout <<"tt = "<<tt<<" temp = "<<temp<<endl;
        if(tt > 1e9 || temp > 100)break;
        if(tt < 0 || tt == 0){temp++;continue;}

        sum = 0;
        while(tt){
            sum += tt%10;
            tt /= 10;
        }
        if(sum == temp){
            lis[ans] = (int)pow((double)temp,a)*b + c;
            ans++;
        }temp++;
    }

    printf("%d\n",ans);
    if(ans == 0)return 0;
    for(int i = 0;i < ans-1;i++){
        printf("%d ",lis[i]);
    }printf("%d\n",lis[ans-1]);

    return 0;
}
