#include <iostream>
#include <cstdio>
#include <algorithm>

1.
�M����ꤤ���W�ߡA�H�o�D���ҡA�]���e�ᶶ�ǽմ��|���ܪ��u���������@���A�ҥH�M��C�@�Ѫ����@���̤j�ȡA�N�O�n�̥��������u�@

2.
�`�N��X���榡�A�o�D�n�C�ӮרҤ�����X�@�ӪŦ�

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
