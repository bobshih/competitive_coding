#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 10010;

//1.
//�Ӥ����N�ȨӨM�w�n�h���֤@�����A�q�j�ƨ�p�A��n�i�H�������H�A�����N�Ȭ��s
//2.
//�̫�A����index�ӱƧǥX���T�����G

struct mem{
    int index;
    int money;
    int p;
    double fair;
}robber[maxn];
int n, m, y;

bool cmp1(const mem& a,const mem& b){
    return a.fair > b.fair;
}
bool cmp2(const mem& a,const mem& b){
    return a.money < b.money;
}
bool cmp3(const mem& a,const mem& b){
    return a.index < b.index;
}

int main()
{
    int t;scanf("%d",&t);

    while(t--){
        scanf("%d %d %d",&n,&m,&y);
        int sum = 0;

        for(int i = 0;i < n;i++){
            scanf("%d",&robber[i].p);
            robber[i].index = i+1;
            robber[i].money = robber[i].p*m/y;
            robber[i].fair = robber[i].p/(double)y - robber[i].money/(double)m;
            sum += robber[i].money;
        }sort(robber,robber+n,cmp1);

        int j = 0;
        for(int i = sum+1;i <= m;i++){
            robber[j++].money++;
        }sort(robber,robber+n,cmp3);

        for(int i = 0;i < n-1;i++){
            printf("%d ",robber[i].money);
        }printf("%d\n",robber[n-1].money);

        if(t)puts("");
    }

    return 0;
}
