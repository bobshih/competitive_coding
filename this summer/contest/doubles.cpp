#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a[16];
    int s;

    while(true){
        for(int i = 0;i < 16;i++){
            scanf("%d",&a[i]);
            if(a[i] == 0){s = i;break;}
            if(a[i] == -1)goto endp;
        }

        int ans = 0;
        for(int i = 0;i < s;i++){
            for(int j = 0;j < s;j++){
                if(a[i]*2 == a[j])ans++;
            }
        }
        cout <<ans<<endl;
    }
    endp:

    return 0;
}
