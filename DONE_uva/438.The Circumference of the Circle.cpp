#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#define pi 3.141592653589793

using namespace std;

double count_c(double x1,double y1,double x2,double y2,double x3,double y3){
    double a = sqrt(pow(x2-x3,2)+pow(y2-y3,2));
    double b = sqrt(pow(x1-x3,2)+pow(y1-y3,2));
    double c = sqrt(pow(x2-x1,2)+pow(y2-y1,2));
    double ang = acos((a*a + b*b - c*c)/(2*a*b));

    //cout <<a<<endl<<b<<endl<<c<<endl<<ang<<endl;
    return (pi*c/sin(ang));
}

int main(){
    double x1,x2,x3;
    double y1,y2,y3;
    double r;

    while (scanf("%lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3) == 6){
        //cout <<"counting\n";
        printf("%.2lf\n",count_c(x1,y1,x2,y2,x3,y3));
    }

    return 0;
}
