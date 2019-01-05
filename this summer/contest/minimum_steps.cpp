#include <iostream>

using namespace std;

long long find_step(int i,long long a[1001]){
    if(i == 1){return 0;}
    else {
        if(i%2 == 0){return 1+a[i/2];}
        else {
            a[i+1] = find_step(i+1,a);

            if(a[i+1] < a[i-1]){return 1+a[i+1];}
            else {return 1+a[i-1];}
        }
    }
}

int main()
{
    int ca;
    int num;
    long long ans[1001];
    for(int i = 0;i < 1001;i++){
        ans[i] = 0;
    }

    for(int i = 1;i < 1001;i++){
        if(ans[i] != 0)continue;
        ans[i] = find_step(i,ans);
    }

    scanf("%d",&ca);

    for(int i = 0;i < ca;i++){
        scanf("%d",&num);
        printf("%ld\n",ans[num]);
    }
    //for(int i = 900;i < 1001;i++){
    //    printf("%d is %ld\n",i,ans[i]);
    //}

    return 0;
}
