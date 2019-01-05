#include <cstdio>

using namespace std;

int main()
{
    int n;scanf("%d",&n);
    int mat[105][105];
    int sum = 0,temp;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            scanf("%d",&temp);
            if(i == n/2){sum += temp;temp = 0;}
            if(i == j){sum += temp;temp = 0;}
            if(j == n/2){sum += temp;temp = 0;}
            if(i+j == n-1){sum += temp;temp = 0;}
        }
    }
    printf("%d\n",sum);

    return 0;
}
