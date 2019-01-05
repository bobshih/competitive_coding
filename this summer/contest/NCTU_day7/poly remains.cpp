#include <iostream>
#include <cstdio>

using namespace std;

int poly[10010];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    int n,k;

    while(scanf("%d %d",&n,&k) == 2){
        if(n == -1 && k == -1){
            break;
        }

        for(int i = 0;i <= n;i++){
            scanf("%d",&poly[i]);
        }
        while(n >= k){
            //for(int i = 0;i < n;i++){
            //    printf("%d ",poly[i]);
            //}printf("%d\n",poly[n]);

            //cout <<"n = "<<n<<" k = "<<k<<endl;
            int temp = poly[n];
            poly[n] = 0;
            if(k != 0)poly[n-k] -= temp;
            for(int i = n;i >= 0;i--){
                //cout <<"poly["<<i<<"] = "<<poly[i]<<endl;
                if(poly[i] != 0){n = i;break;}
            }
            if(poly[k] == 0)break;
        }
        //system("pause");
        for(int i = 0;i < n;i++){
            printf("%d ",poly[i]);
        }printf("%d\n",poly[n]);

    }


    return 0;
}
