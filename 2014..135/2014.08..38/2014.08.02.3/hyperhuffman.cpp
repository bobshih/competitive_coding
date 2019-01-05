#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;
const int maxn = 500050;

1.
�Q��priority queue��heap���c�A�Ө��o����(�o�D�O���o�̤p��)�A���Bpush�i�h���ɭԷ|�A�i��heapify���ʧ@
2.
�]���Oheap���c�y�A�ҥH�ɶ��OO(nlogn)

long long p;
long long sum;
priority_queue<long long, vector<long long> ,greater<long long> > pq;
int num;

int main()
{
    int t;scanf("%d",&t);

    //printf("%I64d\n",499750000000000);
    while(t--){
        scanf("%d",&num);
        sum = 0;

        for(int i = 0;i < num;i++){
            scanf("%lld",&p);
            //cout <<"i = "<<i<<" p = "<<p[i]<<endl;
            pq.push(p);
        }

        while(pq.size() != 1){
            //cout <<"size = "<<avector.size()<<" sum = "<<sum<<endl;
            long long a = pq.top();pq.pop();
            long long b = pq.top();pq.pop();
            sum += a+b;
            pq.push(a+b);
        }
        printf("%lld\n",sum);
        pq.pop();

        if(t)puts("");
    }

    return 0;
}
