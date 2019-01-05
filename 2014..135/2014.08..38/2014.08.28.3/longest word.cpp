#include <iostream>
#include <cstdio>
#include <cstring>

#define test(i) (a[i] >= 'a' && a[i] <= 'z')||a[i] == '-'
using namespace std;

char a[500];
char ans[500];
int end,start;
int pos;

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    ans[0] = '\0';
    while(scanf("%s",a) != EOF){
        if(a[0] == 'E' && a[1] == '-' && a[2] == 'N' && a[3] == '-' && a[4] == 'D')break;

        start = end = -1;
        for(int i = 0;i < strlen(a);i++){
            //cout <<"initially start = "<<start<<" end = "<<end<<endl;
            if(a[i] >= 'A' && a[i] <= 'Z')a[i]+=32;

            if((test(i)) && start == -1){start = i;}
            if((!(test(i)) && start != -1 && end == -1) || (i == strlen(a)-1 && start != -1)){
                if(i == strlen(a)-1)end = i+1;
                else end = i;
                //cout <<"start = "<<start<<" end = "<<end<<endl;
                if(end-start > strlen(ans)){
                    for(int pos = start;pos < end;pos++){
                        ans[pos-start] = a[pos];
                    }ans[end] = '\0';
                    //printf("ans = %s\n",ans);
                }
                end = start = -1;
            }
        }

    }
    printf("%s\n",ans);
    return 0;
}
