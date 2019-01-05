#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int test;
    scanf("%d",&test);
    int nums;
    int t[101];
    int s[101];
    bool sta,que;

    for(int df = 0;df < test;df++){
        que = sta = 1;
        scanf("%d",&nums);
        for(int i = 0;i < nums;i++){
            scanf("%d",&t[i]);
        }
        int cou = 0;
        for(int i = 0;i < nums;i++){
            scanf("%d",&s[i]);
            if(s[i] != t[i]){que = 0;}
            if(s[i] != t[nums-i-1]){sta = 0;}
        }

        if(sta && que){printf("both\n");}
        else if(sta){printf("stack\n");}
        else if(que){printf("queue\n");}
        else {printf("neither\n");}
    }

    return 0;
}
