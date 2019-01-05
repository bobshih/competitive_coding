#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

這題和shoemaker problem一樣，前後順序的交換會造成影響的只有彼此的cost而已，所以就用cmp比較一下，排序囉

struct pro{
    long long t;
    long long enlarge;
};
pro problem[100005];

bool cmp(const pro& a,const pro& b){
    return a.t*b.enlarge < b.t*a.enlarge;
}

int main()
{
    int t;

    while(scanf("%d",&t) != EOF){
        for(int i = 0;i < t;i++){
            scanf("%I64d",&problem[i].t);
        }
        for(int i = 0;i < t;i++){
            scanf("%I64d",&problem[i].enlarge);
        }
        sort(problem,problem+t,cmp);

        long long ti = 0;
        long long sum = 0;
        for(int i = 0;i < t;i++){
            //cout <<"t = "<<problem[i].t<<" enlarge = "<<problem[i].enlarge<<endl;
            ti += problem[i].t;
            sum += ti*problem[i].enlarge;
        }
        printf("%I64d\n",sum);
    }



    return 0;
}
