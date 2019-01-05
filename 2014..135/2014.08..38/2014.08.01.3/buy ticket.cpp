#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int maxn = 200020 << 4;

int n,tot;
int sum[maxn],pos[maxn],value[maxn],ans[maxn];

void constrcut(int index,int l,int r){
    //cout <<"index = "<<index<<" l = "<<l<<" r = "<<r<<endl;

    if(tot < index){tot = index;}
    if(l == r){
        sum[index] = 1;
    }else {
        int index_l = index<<1,index_r = index_l|1,mid = (l+r)>>1;

        constrcut(index_l,l,mid);
        constrcut(index_r,mid+1,r);
        sum[index] = sum[index_l] + sum[index_r];
    }
}
int query(int index,int l,int r,int v){
    sum[index]--;                    //每問一次，總量少一
    if(l == r){
        return l;
    }else {
        int index_l = index<<1,index_r = index_l|1,mid = (l+r)>>1;
        //cout <<"querying index = "<<index<<" l = "<<l<<" r = "<<r<<" sum[mid] = "<<sum[mid]<<endl;

        if(v <= sum[index_l]){return query(index_l,l,mid,v);}                      //如果左邊的空位足夠的話，就尋找左邊的空位
        else {return query(index_r,mid+1,r,v-sum[index_l]);}                       //要不然就是把總算減掉左邊的量，在看向右邊
    }
}
int main()
{
    int t1,t2;

    while(scanf("%d",&n) != EOF){
        constrcut(1,1,n);
        for(int i = 0;i < n;i++){
            scanf("%d %d",&pos[i],&value[i]);
        }

        //for(int i = 0;i <= tot;i++){
        //    cout <<"i = "<<i<<" sum = "<<sum[i]<<endl;
        //}

        for(int i = n-1;i >= 0;i--){
            int a = query(1,1,n,pos[i]+1);
            //cout <<"a = "<<a<<" pos = "<<pos[i]<<endl;
            ans[a] = value[i];
        }

        for(int i = 1;i < n;i++){
            printf("%d ",ans[i]);
        }printf("%d\n",ans[n]);
    }


    return 0;
}
