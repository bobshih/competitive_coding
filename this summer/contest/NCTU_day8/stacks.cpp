#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdio>
#include <cstring>

重點(陣列以降冪排列)
1.
用DFS搜尋，尋找所有可能組合，利用方式，從最大邊開始查找，依序與下一個長度進行組合，細節是，在組合的DFS當中，當你回朔到之前的的狀態
時，vis[i]的值要回到0，但是當進入DFS的過程中，要先將vis[i]設為1，如注一標示的地方，那如何判斷結束了呢？利用DFS外的bool變數來儲存就
可以了

2.
利用剪枝的技巧，大大減少重複的DFS，當前一個vis[i]為0時，且目前的值與前一個相同，代表以他為組合式拼湊不出來所要的長度的，所以以
continue跳過迴圈的這一項，如注二標示處

3.
關於當長度為0時的處理方式，在一開始的函式中舉列出這一可能選項，為什麼要這麼做？因為如果丟到下面的迴圈進行處理，會發生可能無法處理
vis[a-1]為0的問題，另一方面，在進行比較arr[a] == arr[a-1]的時候，也會發生錯誤，那麼解決辦法之一就是當作特例進行處理，如注三

using namespace std;
int arr[100];
bool vis[100];
int n;
bool flag;

bool cmp(int a,int b){
    return a > b;
}
bool all(){
    for(int i = 0;i < n;i++){
        if(vis[i] == 0)return 0;
    }return 1;
}
void dfs(int len,int now,int index){
    if(flag){return ;}
    //cout <<"now = "<<now<<" index = "<<index<<endl;
    if(now == len){
        if(all()){flag = true;}
        else dfs(len,0,0);
        return;
    }

    if(now == 0){                //注三
        int k = 0;               //注三
        while(vis[k] == 1){      //注三
            k++;                 //注三
        }                        //注三
        vis[k] = true;           //注三
        dfs(len,arr[k],k+1);     //注三
        vis[k] = false;          //注三
        return;
    }

    for(int a = index;a < n;a++){
        if(vis[a] != 1 && arr[a]+now <= len){
            if(vis[a-1] == 0 && arr[a] == arr[a-1])continue;    //注二
            vis[a] = true;                                      //注一
            dfs(len,now+arr[a],a+1);                            //注一
            vis[a] = false;                                     //注一
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int sum;

    while(scanf("%d",&n) != EOF){
        if(n == 0)break;
        sum = 0;

        for(int i = 0;i < n;i++){
            scanf("%d",&arr[i]);
            sum += arr[i];
        }sort(arr,arr+n,cmp);

         flag = 0;
         for(int i = arr[0];i <= sum;i++){
            //cout <<"i = "<<i<<endl;
            if(sum%i == 0){
                memset(vis,0,sizeof(vis));
                dfs(i,0,0);
                if(flag){printf("%d\n",i);break;}
            }
         }
    }

    return 0;
}
