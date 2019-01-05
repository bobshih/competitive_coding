#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

�o�D�Mshoemaker problem�@�ˡA�e�ᶶ�Ǫ��洫�|�y���v�T���u��������cost�Ӥw�A�ҥH�N��cmp����@�U�A�Ƨ��o

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
