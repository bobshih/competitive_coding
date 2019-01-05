#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
#include <vector>

using namespace std;

int road,attraction;
int connect[1005][1005];
int index;
int poi[1005];
int low[1005];
int strong[1005];
stack<int> astack;
int part;
int degree[1005];
bool instack[1005];

void strongconnect(int p,int parent){
    poi[p] = index;
    low[p] = index;
    index++;
    astack.push(p);
    instack[p] = 1;

    for(int i = 1;i <= attraction;i++){
        //cout <<"conect["<<i<<"]["<<p<<"] = "<<connect[i][p]<<endl;
        if(connect[i][p] == 1){
            //connect[i][p] = -1;
            //connect[p][i] = -1;
            if(i == parent)continue;
            if(poi[i] == -1){


                strongconnect(i,p);
                //cout <<"new point p = "<<p<<" i = "<<i<<endl;
                //cout <<low[p]<<"\t"<<low[i]<<endl;
                low[p] = min(low[p],low[i]);
                //cout <<low[p]<<endl;
            }else if(instack[i]){
                //cout <<"the old one p = "<<p<<" i = "<<i<<endl;
                //cout <<low[p]<<"\t"<<low[i]<<endl;
                low[p] = min(low[p],low[i]);
                //low[i] = low[p];
                //cout <<low[p]<<endl;
            }
        }
    }

    //if(low[p] > low[low[p]]){low[p] = low[low[p]];}

    if(poi[p] == low[p]){
        //cout <<p<<"\t"<<poi[p]<<"\t"<<low[p]<<endl;
        while(astack.top() != p){
            //cout <<"part = "<<part<<endl;
            int t = astack.top();
            strong[t] = part;
            astack.pop();
            instack[t] = 0;
        }
        strong[p] = part;
        part++;
        astack.pop();
        instack[p] = 0;
    }
}

void tarjan(){
    index = 0;

    for(int i = 1;i <= attraction;i++){
        //cout <<"i = "<<i<<endl;
        if(poi[i] == -1){
            strongconnect(i,-1);
        }
    }

    //for(int i = 1;i <= attraction;i++){
    //    cout <<poi[i]<<"\t"<<low[i]<<endl;
    //}

    //for(int i = 1;i <= attraction;i++){
    //    cout <<strong[i]<<endl;
    //}

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    char s1[20],s2[20];
    int test;
    int t = 0;

    //while(){
        scanf("%d %d",&attraction,&road);
        memset(connect,0,sizeof(connect));
        memset(poi,-1,sizeof(poi));
        memset(degree,0,sizeof(degree));
        memset(instack,0,sizeof(instack));

        int t1,t2;
        for(int i = 0;i < road;i++){
            scanf("%d %d",&t1,&t2);
            //degree[t1]++;
            //degree[t2]++;
            connect[t1][t2] = 1;
            connect[t2][t1] = 1;
        }

        part = 1;
        tarjan();

        for(int i = 1;i <= attraction;i++){
            for(int j = 1;j <= attraction;j++){
                if(connect[i][j]){
                    if(low[i] != low[j]){
                        degree[low[i]]++;
                    }
                }
            }
        }

        //for(int i = 1;i <= attraction;i++){
        //    cout <<low[i]<<endl;
        //}cout <<endl;

        int count = 0;
        for(int i = 1;i <= attraction;i++){
            if(degree[i] == 1){count++;}
            //cout <<"degree "<<i<<" = "<<degree[i]<<endl;
        }

        //if(t++)printf("\n");
        //printf("Output for Sample Input %d\n",test);
        printf("%d\n",(count+1)>>1);
    //}

    return 0;
}
