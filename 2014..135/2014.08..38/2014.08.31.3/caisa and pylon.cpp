#include <cstdio>

using namespace std;

int main()
{
    int n,lis[100005],temp,M = 0;
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%d",&temp);
        if(temp > M)M = temp;
    }printf("%d\n",M);

    return 0;
}
