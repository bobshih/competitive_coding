#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int gcd(int a,int b){//cout <<a<<"\n"<<b<<endl;
    if(!(a%b)){return b;}
    else {return (gcd(b,a%b));}
}

int main(){
    int nums;
    int all;
    int over;
    double pi;

    while (scanf("%d",&nums) == 1){
        if(nums == 0){break;}

        int* da = new int[nums];
        for(int i = 0;i < nums;i++){scanf("%d",&da[i]);}
        all = 0;
        over = 0;

        for(int i = 0;i < nums;i++){
            for(int j = i+1;j < nums;j++){
                all++;
                if(da[i] > da[j]){if(gcd(da[i],da[j]) == 1){over++;}}
                else {if(gcd(da[j],da[i]) == 1){over++;}}
            }
        }

        if(over == 0){printf("No estimate for this data set.\n");continue;}
        pi = sqrt(6.0*all/over);

        printf("%lf\n",pi);
    }



    return 0;
}
