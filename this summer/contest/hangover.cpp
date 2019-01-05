#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double test;
    double temp[500];
    temp[0] = 0;

    for(int i = 1;i < 500;i++){
        temp[i] = temp[i-1]+1.0/(i+1);
        //cout <<temp[i]<<endl;
    }

    while(scanf("%lf",&test) == 1){
        if(test == 0){break;}

        for(int i = 0;i < 500;i++){
            if(temp[i] >= test){
                printf("%d card(s)\n",i);
                break;
            }
        }
    }


    return 0;
}
