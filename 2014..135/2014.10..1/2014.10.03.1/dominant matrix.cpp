#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
    freopen("testdata.in","r",stdin);
    long long T;scanf("%lld",&T);

    for(int k = 0;k < T;k++){
        int a;scanf("%d",&a);

        double pp[10];memset(pp,0.0,sizeof(pp));
        double dig[10];
        for(int i = 0;i < a;i++){
            for(int j = 0;j < a;j++){
                if(i == j){
                    scanf("%lf",&dig[i]);
                    dig[i] = fabs(dig[i]);
                }
                else {
                    double temp;
                    scanf("%lf",&temp);
                    temp = fabs(temp);
                    pp[i] += temp;
                }
            }
        }

        bool flag = 0;
        for(int i = 0;i < a;i++){
            //printf("%lf %lf\n",pp[i],dig[i]);
            if(pp[i] >= dig[i]){

                flag = 1;break;
            }
        }
        if(flag){printf("N");}
        else printf("Y");
    }
    puts("");
    return 0;
}
