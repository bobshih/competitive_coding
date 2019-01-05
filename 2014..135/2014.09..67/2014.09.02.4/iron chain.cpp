#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;
#define g 9.80665

int main()
{
    int test;
    scanf("%d",&test);

    double a,b,h;
    for(int i = 1;i <= test;i++){
        scanf("%lf %lf %lf",&a,&b,&h);
        if(fabs(a-b) < 1e-5){
            printf("Case %d: The iron chain will not reach the floor at all!\n",i);
            continue;
        }
        if(a < b)swap(a,b);

        double d = 0.0005;
        double v1 = 0,v2 = 0;
        double ans = 0.0;

        bool flag = 0;
        if(h-a < b){flag = 1;b = h-a;}

        double tmp = 2*g/(a+b);
        for(double j = d;j <= b;j+=d){
            v2 = sqrt(tmp * j * (a - b + j));
            double v = (v1 + v2) / 2;
            ans += d / v;
            v1 = v2;
        }
        //printf("first stage ans = %lf\n",ans);
        if(flag){
            printf("Case %d: The iron chain will reach the floor after %.3lf seconds.\n",i,ans);
        }else {
            ans += ((v1*-1 + sqrt(v1*v1 + 2*(h-a-b)*g))/g);
            printf("Case %d: The iron chain will reach the floor after %.3lf seconds.\n",i,ans);
        }
    }

    return 0;
}
