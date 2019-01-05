#include <iostream>
#include <cstdio>
#include <algorithm>

1.
尋找測資中的規律，以這題為例，因為前後順序調換會改變的只有彼此的罰金，所以尋找每一天的單位罰金最大值，就是要最先完成的工作

2.
注意輸出的格式，這題要每個案例之間輸出一個空行

using namespace std;
int w;
int fine[1010];
int ti[1010];
//double persent[1010];
struct pp{
    double persent;
    int index;

    bool operator <(const pp& a)const{
        return persent > a.persent;
    }
};
pp all[1010];


int main()
{
    int test;
    scanf("%d",&test);

    while(test--){
        scanf("%d",&w);
        for(int i = 0;i < w;i++){
            scanf("%d %d",&ti[i],&fine[i]);
            all[i].persent = (double)fine[i]/(double)ti[i];
            all[i].index = i+1;
        }
        sort(&all[0],&all[w]);

        for(int i = 0;i < w-1;i++){
            printf("%d ",all[i].index);
        }printf("%d\n",all[w-1].index);
        if(test){printf("\n");}
    }

    return 0;
}
