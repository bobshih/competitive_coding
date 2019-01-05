#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

struct woodens{
    int l;
    int w;

    bool operator < (const woodens a) const{
        if(l == a.l)return w < a.w;
        return l < a.l;
    }
};

woodens sti[5010];
bool used[5010];
int sticks;

bool test(){
    for(int i = 0;i < sticks;i++){
        if(used[i] == 0)return 1;
    }return 0;
}

int main()
{
    int te;
    scanf("%d",&te);


    while(te--){
        memset(used,0,sizeof(used));

        scanf("%d",&sticks);
        for(int i = 0;i < sticks;i++){
            scanf("%d %d",&sti[i].l,&sti[i].w);
        }
        sort(&sti[0],&sti[sticks]);
        //for(int i = 0;i < sticks;i++){
        //   printf("%d %d\n",sti[i].l,sti[i].w);
        //}

        int j = 0;
        int ans = 0;
        while(test()){
            //cout <<"w = "<<sti[j].w<<" l = "<<sti[j].l<<endl;
            used[j] = true;
            int temp = j;
            for(int i = j+1;i < sticks;i++){
                //cout <<"w = "<<sti[i].w<<" l = "<<sti[i].l<<endl;
                //system("pause");
                if(sti[i].l >= sti[j].l && sti[i].w >= sti[j].w && used[i] == 0){
                    temp = i;break;
                }
            }
            if(temp == j){
                ans++;
                //cout <<"temp = "<<temp<<" j = "<<j<<endl;
                for(int i = 0;i < sticks;i++){
                    if(used[i] == 0){j = i;break;}
                }
            }else j = temp;

        }printf("%d\n",ans);

    }

    return 0;
}
