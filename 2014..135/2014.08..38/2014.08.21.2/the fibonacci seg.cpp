#include <iostream>
#include <cstdio>
using namespace std;

int n;
int seg[1000005];

int main()
{
    scanf("%d",&n);

    seg[0] = 0;
    int ans = 0;
    int temp = 0;

    for(int i = 1;i <= n;i++)scanf("%d",&seg[i]);

    for(int i = 1;i <= n;i++){
        //cout <<seg[i]<<" i = "<<i<<" temp = "<<temp<<endl;
        if(temp == 0){temp++;}
        else if(temp == 1){
            temp++;
            //if(seg[i] < seg[i-1]){ans = max(ans,temp);temp = 0;i--;}
            //else temp++;
        }
        else {
            if(seg[i] == seg[i-1] + seg[i-2]){temp++;}
            else {ans = max(ans,temp);temp = 0;i-=2;}
        }
    }cout <<max(ans,temp)<<endl;
    return 0;
}
