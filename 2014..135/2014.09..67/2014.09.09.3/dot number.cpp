#include <cstdio>

using namespace std;
long long n1,n2;
long long x1,x2,y1,y2;

void convert(long long a,bool flag){
    long long t1,t2,temp;
    for(long long i = 1;i <= a;i++){
        if(i*(i+1)/2 >= a){
            //printf("i = %I64d\n",i);
            temp = i*(i+1)/2-a;
            t1 = i-temp;
            t2 = 1+temp;
            break;
        }
    }

    if(flag){
        x1 = t1;y1 = t2;
    }else {
        x2 = t1;y2 = t2;
    }
}

int main()
{
    //freopen("in.txt","r",stdin);

    int T;scanf("%d",&T);
    while(T--){
        scanf("%lld %lld",&n1,&n2);
        convert(n1,1);
        convert(n2,0);
        //printf("x1 = %I64d y1 = %I64d\n",x1,y1);
        //printf("x2 = %I64d y2 = %I64d\n",x2,y2);

        long long x = x1+x2;
        long long y = y1+y2;
        long long ttt = y-1+x;
        long long dot = ttt*(ttt+1)/2-y+1;
        printf("%lld\n",dot);
        //if(T)printf("\n");
    }

    return 0;
}
