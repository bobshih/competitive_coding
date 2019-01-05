#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int n,x;
int m[2005],h[2005],type[2005],eat[2005];
int ans;

void eating(bool flag,int t,int j){
    int E = -1,mx = 0;

    for(int i = 0;i < n;i++){
        if(eat[i] == 0 && h[i] <= j && type[i] == flag){
            if(m[i] > mx){
                mx = m[i];E = i;
            }
        }
    }
    if(E != -1){
        eat[E] = 1;
        eating(!flag,t+1,j+m[E]);
        eat[E] = 0;
    }else {
        ans = max(t,ans);
        return ;
    }
}

int main()
{
    scanf("%d %d",&n,&x);
    memset(eat,0,sizeof(eat));
    ans = 0;
    for(int i = 0;i < n;i++){
        scanf("%d %d %d",&type[i],&h[i],&m[i]);
    }

    eating(1,0,x);
    eating(0,0,x);
    printf("%d\n",ans);

    return 0;
}
