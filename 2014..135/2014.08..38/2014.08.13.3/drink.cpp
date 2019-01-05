#include <iostream>
#include <cstdio>
using namespace std;

int n;
int drink;
int ans;
int buy;
int ticket;

int main()
{
    scanf("%d",&n);

    for(int i = 0;i < n;i++){
        scanf("%d",&drink);
        ans = buy = ticket = 0;

        while(ans != drink){
            //cout <<"buy = "<<buy<<" ticket = "<<ticket<<" ans = "<<ans<<endl;
            buy++;
            ticket++;
            ans++;
            if(ans == drink)break;
            if(ticket == 3){
                ticket = 1;
                ans++;
            }
        }
        printf("%d\n",buy);
    }

    return 0;
}
