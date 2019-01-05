#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n,sum = -1;scanf("%d",&n);getchar();
    char temp[105];memset(temp,0,sizeof(temp));
    for(int i = 0;i < n;i++){
        scanf("%c",&temp[i]);
        if(temp[i] == '0' && sum == -1)sum = i;
    }

    if(sum != -1)printf("%d\n",sum+1);
    else printf("%d\n",n);

    return 0;
}
