#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;
#define pi 3.1415926

int main()
{
    int test;
    scanf("%d",&test);
    double x,y;

    for(int i = 1;i <= test;i++){
        scanf("%lf %lf",&x,&y);

        double area = pi*(x*x + y*y);
        double t = area/100;

        printf("Property %d: This property will begin eroding in year %d.\n",i,(int)ceil(t));
    }
    printf("END OF OUTPUT.\n");

    return 0;
}
