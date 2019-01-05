#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
struct circle{
    double center;
    int rad;
}sun;

#define cut 10005
#define half cut*30
int shadow[half*2];
int n,maximum;

int main()
{

    //freopen("1194-in1.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d %d",&sun.rad,&n) != EOF && (n != 0 || sun.rad != 0)){
        //cout <<"rad = "<<sun.rad<<" n = "<<n<<endl;
        //if(n == 0){
        //    printf("%.4lf\n",(double)0);
        //    continue;
        //}
        maximum = 0;
        memset(shadow,0,sizeof(shadow));
        for(int i = 0;i < n;i++){
            int xl,xr,height;
            scanf("%d %d %d",&xl,&xr,&height);

            if(height > maximum)maximum = height;
            for(int i = xl*cut+half;i <= half+cut*xr;i++){
                if(shadow[i] < height)shadow[i] = height;
            }
        }
        //for(int i = 0;i < 120;i++){
        //    if(i%2 == 0 && shadow[i+1] > 0 && shadow[i-1] > 0){
        //        shadow[i] = min(shadow[i+1],shadow[i-1]);
        //    }
        //}

        //double t0 = 0,t1 = maximum;
        double t = 0,s = 1;
        sun.center = t-sun.rad;

        //for(double x = 0;x < half*2;x++){
        //    if(shadow[(int)x] == 0)continue;
        //    cout <<"x = "<<(x-half)/cut<<" height = "<<shadow[(int)x]<<endl;


        while(s > 1e-5){
            //cout <<"t0 = "<<t0<<" t1 = "<<t1 <<" center = "<<sun.center<<endl;
            //if(t1 < 1e-6){t1 = 0;sun.center = t1-sun.rad;}
            //if(t0 < 1e-6)t0 = 0;
            //cout <<"t = "<<t<<" center = "<<sun.center<<" s = "<<s<<endl;
            bool flag = 0;
            for(int x = sun.rad*-cut + half;x <= half+cut*sun.rad;x++){
                if(sun.center > shadow[x]){flag = 1;break;}
            }
            if(flag){
                t -= s;
                s /= 10;
                //cout <<"first\n";
                //t -= 0.0001;
                //break;
                sun.center = t-sun.rad;
                continue;
            }
            for(double x = sun.rad*-cut;x <= cut*sun.rad;x++){
                double temp = sqrt((double)(sun.rad*sun.rad - x*x/(cut*cut)));

                if(shadow[(int)x+half] < temp+sun.center){
                    flag = 1;break;
                }
            }
            if(flag){
                //cout <<"second\n";
                t -= s;
                s /= 10;
                //break;
                //t1 = (t1+sun.center)/2;
                //t0 = sun.center;
                sun.center = t-sun.rad;
                continue;
            }

            //cout <<"finally\n";
            //t += 0.0001;
            //sun.center = t-sun.rad;
            t += s;
            sun.center = t-sun.rad;
            //if(t1-t0 < 1e-6){
            //  break;
            //}else {
            //    t0 = (t1+t0)/2;
            //    t1 += t0;
            //    sun.center = t1-sun.rad;
            //}
        }

        printf("%.4lf\n",t);
    }


    return 0;
}
