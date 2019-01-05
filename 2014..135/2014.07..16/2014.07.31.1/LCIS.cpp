#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
/*
1.
線段樹，空間複雜度是O(nlogn)，建立的時間複雜度是O(nlogn)，單點查詢的時間複雜度是O(1)，單點更新的時間複雜度是O(logn)
2.
建立線段樹由下而上的建立，另外，index的數字越小，表示越接近root，而1就是root
*/
const int maxn = 400040;
int n,m;
int lmax[maxn],rmax[maxn],mmax[maxn];
int value[maxn];

void built(int index,int l,int r){
    if(l == r){
        lmax[index] = rmax[index] = mmax[index] = 1;
    }else{
        int index_l = index<<1,index_r = index_l|1;
        int mid = (l+r)>>1;
        built(index_l,l,mid);
        built(index_r,mid+1,r);

        if(value[mid] < value[mid+1]){
            lmax[index] = lmax[index_l] + (lmax[index_l] == mid-l+1)*lmax[index_r];
            rmax[index] = rmax[index_r] + (rmax[index_r] == r-mid)*rmax[index_l];
            mmax[index] = max(lmax[index_r] + rmax[index_l],max(mmax[index_r],mmax[index_l]));
        }else {
            lmax[index] = lmax[index_l];
            rmax[index] = rmax[index_r];
            mmax[index] = max(mmax[index_l],mmax[index_r]);
        }
    }
}
void update(int index,int l,int r,int pos,int val){
    if(pos <= l && r <= pos){
        value[pos] = val;
    }else {
        int index_l = index<<1,index_r = index_l|1;
        int mid = (l+r)>>1;

        if(pos <= mid){update(index_l,l,mid,pos,val);}
        if(mid < pos){update(index_r,mid+1,r,pos,val);}

        if(value[mid] < value[mid+1]){
            lmax[index] = lmax[index_l] + (lmax[index_l] == mid-l+1)*lmax[index_r];
            rmax[index] = rmax[index_r] + (rmax[index_r] == r-mid)*rmax[index_l];
            mmax[index] = max(lmax[index_r] + rmax[index_l],max(mmax[index_r],mmax[index_l]));
        }else {
            lmax[index] = lmax[index_l];
            rmax[index] = rmax[index_r];
            mmax[index] = max(mmax[index_l],mmax[index_r]);
        }
    }
}
int quary(int index,int l,int r,int startp,int endp){
    if(startp <= l && r <= endp){
        return mmax[index];
    }else {
        int index_l = index<<1,index_r = index_l|1;
        int mid = (l+r)>>1;
        int ans = 0;

        if(startp <= mid){
            ans = max(ans,quary(index_l,l,mid,startp,endp));
            //cout <<ans<<endl;
        }
        if(mid < endp){
            ans = max(ans,quary(index_r,mid+1,r,startp,endp));
            //cout <<ans<<endl;
        }
        if(value[mid] < value[mid+1]){
            ans = max(ans,min(rmax[index_l],mid-startp+1)+min(lmax[index_r],endp-mid));
            //ans = max(ans, min(rmax[ll], mid - aa + 1) + min(lmax[rr], bb - mid));
            //cout <<ans<<endl;
        }
        //cout <<"ll = "<<index_l<<" rr = "<<index_r<<" mid = "<<mid<<" ans = "<<ans<<endl;
        return ans;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    int t,t1,t2;
    scanf("%d",&t);
    char temp;

    while(t--){
        //memset(tree,-1,sizeof(tree));
        //memset(value,-1,sizeof(value));

        scanf("%d %d",&n,&m);
        for(int i = 0;i < n;i++){
            scanf("%d",&value[i]);
        }
        built(1,0,n-1);

        for(int i = 0;i < m;i++){
            scanf(" %c %d %d",&temp,&t1,&t2);
            //cout <<"temp = "<<(int)temp<<endl;
            if(temp == 'U'){
                update(1,0,n-1,t1,t2);
            }
            else {
                printf("%d\n",quary(1,0,n-1,t1,t2));
            }
        }
    }

    return 0;
}
