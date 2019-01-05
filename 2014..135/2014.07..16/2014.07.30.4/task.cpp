#include <iostream>
#include <cstdio>
#include <vector>
#define stop system("pause");
using namespace std;

1.
���ƥѤj�ƨ�p�A�M�����ϥΪ������ɡA��Ҧ��i�H�Ϊ��������]���@�A���ۦA�D��̤p��(>=task.level)�A�o�˨�Llevel�󰪪������̵M
�i�H�Q�᭱��task�ϥΡA�̲ŦXgreedy�����C


struct machine{
    int level;
    int time;
    bool operator < (const machine& a)const{
        if(time == a.time){return level > a.level;}
        return time > a.time;
    }
};
struct task{
    int level;
    int time;
    bool operator < (const task& a)const{
        if(time == a.time){return level > a.level;}
        return time > a.time;
    }
};
machine mm[100005];
task tt[100005];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int m,t;
    machine temp;

    while(scanf("%d %d",&m,&t) != EOF){
        memset(tt,0,sizeof(tt));
        memset(mm,0,sizeof(mm));

        for(int i = 0;i < m;i++){
            scanf("%d %d",&mm[i].time,&mm[i].level);
        }sort(mm,mm+m);
        for(int i = 0;i < t;i++){
            scanf("%d %d",&tt[i].time,&tt[i].level);
        }sort(tt,tt+t);

        int num = 0;
        int ll[101];memset(ll,0,sizeof(ll));
        long long sum = 0;

        for(int i = 0,j = 0;i < t;i++){
            while(j < m && mm[j].time >= tt[i].time){
                ll[mm[j].level]++;
                j++;
            }

            for(int a = tt[i].level;a <= 100;a++){
                if(ll[a]){
                    num++;
                    ll[a]--;
                    sum += (tt[i].time*500 + tt[i].level*2);
                    break;
                }
            }
        }

        printf("%d %I64d\n",num,sum);

    }

    return 0;
}
