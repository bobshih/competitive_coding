#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

vector<int> conn[30005];
vector<int> branch[30005];
int in[30005];
int out[30005];
bool vis[30005];
int bb[30005];
int n;
int tim;

void DFS(int v){
    vis[v] = 1;
    in[v] = tim++;

    for(int i = 0;i < conn[v].size();i++){
        int t = conn[v][i];
        if(vis[t] == 1)continue;
        DFS(t);
    }
    out[v] = tim++;
}

int main(){
    for(int i = 0;i < 30005;i++){
        conn[i].clear();
        branch[i].clear();
    }

    scanf("%d",&n);
    int t1,t2;
    for(int i = 0;i < n-1;i++){
        scanf("%d %d",&t1,&t2);
        conn[t1].push_back(t2);
        conn[t2].push_back(t1);
    }
    memset(vis,0,sizeof(vis));
    tim = 1;
    DFS(1);

    for(int i = 1;i <= n;i++){
        bb[i] = (out[i]-in[i]+1)/2;
    //    cout <<bb[i]<<endl;
    }

    long long ans = 0;
    long long temp;
    for(int i = 1;i <= n;i++){
        temp = 0;
        for(int a = 0;a < conn[i].size();a++){
            for(int j = a+1;j < conn[i].size();j++){
                int p1 = conn[i][a];
                int p2 = conn[i][j];
                //cout <<"bb["<<i<<"] = "<<bb[i]<<" bb["<<p1<<"] = "<<bb[p1]<<" bb["<<p2<<"] = "<<bb[p2]<<endl;
                if(bb[p1] > bb[i]){t1 = n-bb[i];}
                else {t1 = bb[p1];}
                if(bb[p2] > bb[i]){t2 = n-bb[i];}
                else {t2 = bb[p2];}
                temp += t1*t2;
            }
        }
        ans = max(ans,temp);
    }
    cout <<ans<<endl;
//    for(int i = 1;i <= n;i++){
//        cout <<in[i]<<"\t"<<out[i]<<endl;
//    }


    return 0;
}
