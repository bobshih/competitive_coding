#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    const char name[8][10] = {
        "vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"
    };
    int n;
    char tt[10];
    cin >>n>>tt;
    if(n == 8){
        cout <<name[0]<<endl;
        return 0;
    }
    if(n == 6){
        cout <<name[3]<<endl;
        return 0;
    }

    int ans[8];
    memset(ans,0,sizeof(ans));
    for(int i = 0;i < n;i++){
        if(tt[i] == '.')continue;
        for(int j = 0;j < 8;j++){
            if(tt[i] == name[j][i])ans[j]++;
        }
    }

    int max = 0;
    for(int i = 1;i < 8;i++){
        if(ans[i] > ans[max])max = i;
    }
    cout <<name[max]<<endl;

    return 0;
}
