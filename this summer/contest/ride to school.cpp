#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int test;
    double temp;
    int t1,t2;

    while(scanf("%d",&test)){
        if(test == 0)break;

        double m = 16200;
        for(int i = 0;i < test;i++){
            scanf("%d %d",&t1,&t2);

            if(t2 < 0)continue;
            temp = 4.5/t1*3600 + t2;
            if(temp < m){m = temp;}
            //cout <<"m is "<<m<<endl;
        }
        if(m-(int)m > 0){m++;}
        printf("%d\n",(int)m);
    }


    return 0;
}
