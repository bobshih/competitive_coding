#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int child[100];
    int left[100];
    for(int i = 0;i < n;i++){
        scanf("%d",&child[i]);
    }
    bool flag;
    int pos = n-1;
    while(flag == 0){
        flag = 1;
        for(int i = 0;i < n;i++){
            child[i] -= m;
            if(child[i] > 0){flag = 0;pos = i;}
        }

    }

    printf("%d\n",pos+1);

    return 0;
}
