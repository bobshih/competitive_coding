#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <functional>
#include <cstring>
using namespace std;
const int maxn = 500050;

1.
利用priority queue的heap結構，來取得極值(這題是取得最小值)，爾且push進去的時候會再進行heapify的動作
2.
因為是heap的構造，所以時間是O(nlogn)

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
