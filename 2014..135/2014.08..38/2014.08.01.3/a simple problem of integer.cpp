#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

//線段樹之區域更新
//1.
//build函式沒有大差異
//2.
//update函式，先向下更新，再向上更新
//3.
//query函式，直接回傳sum的值，如果更新值不等於零，向下傳遞

const int maxn = 100100 << 2;
long long n ,m;
long long value[maxn],sum[maxn],up[maxn],member[maxn];
long long tot;

void build(long long index,long long l,long long r){
    //cout <<"index = "<<index<<" r = "<<r<<" l = "<<l<<endl;
    member[index] = r-l+1;
    if(tot < index){tot = index;}
    if(r == l){
        sum[index] = value[r];
    }else {
        long long index_l = index<<1,index_r = index_l+1,mid = (r+l)>>1;
        build(index_l,l,mid);
        build(index_r,mid+1,r);

        sum[index] = sum[index_l]+sum[index_r];
    }
}
long long query(long long index,long long l,long long r,long long startp,long long endp){
    if(startp <= l && endp >= r){
        //cout <<"index = "<<index<<" l = "<<l<<" r = "<<r<<endl;
        return sum[index];
        /*if(l == r){sum[index] += up[index];up[index] = 0;return sum[index];}
        else {
            long long ans = sum[index] + member[index]*up[index];
            long long index_l = index<<1,index_r = index|1;
            up[index_l] += up[index];
            up[index_r] += up[index];
            //cout <<"get answer push "<<"up["<<index<<"] = "<<up[index]<<" into "<<"up["<<index_l<<"] = "<<up[index_l]<<" up["<<index_r<<"] = "<<up[index_r]<<endl;
            up[index] = 0;
            return ans;
        }*/
    }else {
        long long index_l = index<<1,index_r = index_l|1,mid = (l+r)>>1;
        if(up[index] != 0){                     //向下更新
            //sum[index] += member[index]*up[index];
            up[index_l] += up[index];
            up[index_r] += up[index];
            sum[index_l] += member[index_l]*up[index];
            sum[index_r] += member[index_r]*up[index];
            up[index] = 0;
        }
        //cout <<"push "<<"up["<<index<<"] = "<<up[index]<<" into "<<"up["<<index_l<<"] = "<<up[index_l]<<" up["<<index_r<<"] = "<<up[index_r]<<endl;

        if(endp <= mid){return query(index_l,l,mid,startp,endp);}
        if(startp > mid){return query(index_r,mid+1,r,startp,endp);}
        return query(index_l,l,mid,startp,mid) + query(index_r,mid+1,r,mid+1,endp);
    }
}
void update(long long index,long long l,long long r,long long update_l,long long update_r,long long val){
    if(update_l <= l && update_r >= r){
        up[index] += val;
        sum[index] += member[index]*val;
        //cout <<"updating l = "<<l<<" r = "<<r<<" up["<<index<<"] = "<<up[index]<<endl;
        return;
    }else {
        long long index_l = index<<1,index_r = index_l|1,mid = (l+r)>>1;
        if(up[index] != 0){                         //向下更新
            up[index_l] += up[index];
            up[index_r] += up[index];
            sum[index_l] += member[index_l]*up[index];
            sum[index_r] += member[index_r]*up[index];
            up[index] = 0;
        }

        //sum[index] += ((update_r-update_l+1)*val);

        if(update_r <= mid){update(index_l,l,mid,update_l,update_r,val);}
        else if(update_l > mid){update(index_r,mid+1,r,update_l,update_r,val);}
        else {
            update(index_l,l,mid,update_l,mid,val);
            update(index_r,mid+1,r,mid+1,update_r,val);}
        sum[index] = sum[index_l]+sum[index_r];     //向上更新
        return;
    }
}
int main()
{
    char temp;
    long long t1,t2,t3;

    while(scanf("%I64d %I64d",&n,&m) != EOF){
        memset(sum,0,sizeof(sum));
        memset(up,0,sizeof(up));
        memset(member,0,sizeof(member));
        tot = 0;
        for(int i = 0;i < n;i++){
            scanf("%I64d",&value[i]);
        }build(1,0,n-1);

        //for(int i = 0;i < tot;i++){
        //    cout <<"i = "<<i<<"member = "<<member[i]<<endl;
        //}

        for(int i = 0;i < m;i++){
            scanf(" %c",&temp);
            if(temp == 'Q'){
                scanf("%I64d %I64d",&t1,&t2);
                printf("%I64d\n",query(1,0,n-1,t1-1,t2-1));
            }else if(temp == 'C'){
                scanf("%I64d %I64d %I64d",&t1,&t2,&t3);
                update(1,0,n-1,t1-1,t2-1,t3);
            }else if(temp == 'O'){
                for(int i = 1;i < tot;i++){
                    printf("i = %d sum = %I64d\n",i,sum[i]);
                }
            }
        }
    }

    return 0;
}
