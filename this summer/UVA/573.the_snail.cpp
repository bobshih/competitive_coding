#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long climb(int height,double position,double lazy,double distan,int drop,bool &suc){
    if(position+distan > height){suc = 1;return 1;}
    else if(position+distan-drop < 0){suc = 0;return 1;}
    else {
        if(distan-lazy > 0){return 1+ climb(height,position+distan-drop,lazy,distan-lazy,drop,suc);}
        else {
            suc = 0;
            return 1+ climb(height,position+distan-drop,lazy,0,drop,suc);}
        }
}

int main()
{
    int h,u,d,f;
    double pos,dis,lazy;
    bool success;
    long long day;

    while(scanf("%d %d %d %d",&h,&u,&d,&f) == 4){
        if(h == 0){break;}

        lazy = u*f;
        lazy /= 100;
        pos = 0;
        dis = u;

        day = climb(h,pos,lazy,dis,d,success);

        if(success){printf("success on day %ld\n",day);}
        else {printf("failure on day %ld\n",day);}
    }

    return 0;
}
