#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>

using namespace std;
bool pri[10010];

int find_seq(int a,int start){
    int sum = 0;

    if(start > 10001 )return 0;
    if(!pri[start])return find_seq(a,start+1);

    for(int i = start;i < 10010;i++){
        if(pri[i] == 1)sum+=i;
        if(sum == a){//system("pause");
            return 1+find_seq(a,start+1);
        }else if(sum > a)return find_seq(a,start+1);
    }
}

int main()
{
    int in;
    memset(pri,true,10010);

    for(int i = 2;i < 101;i++){
        for(int j = 2;j < 10010;j++){
            if(j%i == 0 && j > i)pri[j] = false;
        }
    }

    pri[0] = false;
    pri[1] = false;

    int sum;
    while(scanf("%d",&in) != EOF){
        if(in == 0)break;

        sum = find_seq(in,1);
        printf("%d\n",sum);
    }




    return 0;
}
