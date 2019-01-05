#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct member{
    int index,s,b;
    //member(int i,int s,int b):index(i+1),s(s),b(b){}
    bool operator < (const member a)const{
        if(s == a.s)return b > a.b;
        return s < a.s;
    }
};

member peo[100010];
int lis[100010];       //纗ヘ玡程皚いΘ
int pos[100010];       //纗peolisい纯筁竚
int sta[100010];       //纗程程皚いΘ秈
int flag;              //纗程皚程环竚
int ans;
int num;               //赣掸代戈い羆计

bool cmp(int a,int b){
    member temp1 = peo[a],temp2 = peo[b];
    return temp1.s < temp2.s && temp1.b < temp2.b;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("in_1.txt","r",stdin);
    #endif // ONLINE_JUDGE

    int tt;
    scanf("%d",&tt);

    while(tt--){
        scanf("%d",&num);

        for(int i = 0;i < num;i++){
            scanf("%d %d",&peo[i].s,&peo[i].b);
            peo[i].index = i+1;
        }sort(peo,peo+num);

        //for(int i = 0;i < num;i++){
        //    printf("%d\t%d\n",peo[i].s,peo[i].b);
        //}

        flag = 0;
        for(int i = 0;i < num;i++){
            pos[i] = lower_bound(lis,lis+flag,i,cmp) - lis;

            //cout <<"pos["<<i<<"] = "<<pos[i]<<" flag = "<<flag<<endl;
            if(pos[i] == flag)flag++;          //т糤程皚计
            lis[pos[i]] = i;
            //cout <<"after process lis["<<pos[i]<<"] = "<<lis[pos[i]]<<" flag = "<<flag<<endl;
        }

        ans = 0;
        flag--;
        for(int i = num-1;i >= 0;i--){
            if(pos[i] == flag){sta[ans++] = i;flag--;}
        }

        if(ans > 0)printf("%d\n",ans);
        for(int i = ans-1;i > 0;i--){
            printf("%d ",peo[sta[i]].index);
        }printf("%d\n",peo[sta[0]].index);

        if(tt)puts("");
    }
    return 0;
}
