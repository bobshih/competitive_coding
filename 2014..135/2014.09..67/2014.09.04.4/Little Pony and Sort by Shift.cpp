#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;cin >>n;

    int lis[100005];lis[0] = 0;
    int flag = 0;
    for(int i = 1;i <= n;i++){
        cin >>lis[i];
        //cout <<"lis["<<i<<"] = "<<lis[i]<<" lis["<<i-1<<"] = "<<lis[i-1]<<endl;
        if(lis[i] < lis[i-1] && flag == 0){
            flag = i;
            //cout <<"i = "<<i<<endl;
        }
    }

    int aaaa[100005];
    int i,j;
    for(i = flag,j = 0;i <= n;i++,j++){
        aaaa[j] = lis[i];
    }
    for(i = 1;i <= flag-1;i++,j++){
        aaaa[j] = lis[i];
    }
    //cout <<"flag = "<<flag<<endl;
    //for(int i = 0;i < n;i++){
    //    cout <<aaaa[i]<<endl;
    //}

    for(int i = 0;i < n-1;i++){
        if(aaaa[i] > aaaa[i+1]){
            printf("-1\n");
            return 0;
        }
    }
    if(flag == 0)printf("0\n");
    else printf("%d\n",n-flag+1);


    return 0;
}
