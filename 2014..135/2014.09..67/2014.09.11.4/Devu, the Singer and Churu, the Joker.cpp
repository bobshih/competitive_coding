#include <cstdio>

using namespace std;

int main()
{
    int n,d;
    scanf("%d %d",&n,&d);

    int song[103],sum = 0;;
    for(int i = 0;i < n;i++){
        scanf("%d",&song[i]);
        sum += song[i];
    }
    int pos = 0,j = 0;

    bool flag = 0;
    while(d > 0){
        d -= song[pos++];
        if(pos != n){
            d -= 10;
            j += 2;
        }
        if(d < 0){
            flag = 1;
            break;
        }else if(pos == n){
            j += (d/5);
            break;
        }
    }

    if(flag == 0)printf("%d\n",j);
    else printf("-1\n");
    return 0;
}
