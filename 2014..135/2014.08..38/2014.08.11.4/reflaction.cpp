#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
long long n;
bool ans[101];

class rec{
public:
    long long num;
    long long left,down;
    long long right,top;
} Rec[101];

void merg(long long a,long long i){
    int tt = 2;
    if(Rec[i].left > Rec[a].right || Rec[i].right < Rec[a].left)tt--;
    if(Rec[i].top < Rec[a].down || Rec[i].down > Rec[a].top)tt--;

    if(tt != 2){
        //cout <<"a = "<<a<<" i = "<<i<<" num = "<<Rec[a].num<<endl;
        return;}

    for(int j = 0;j < i;j++){
        //cout <<"in merge a = "<<a<<" i = "<<i<<" j = "<<j<<" num[a] = "<<Rec[a].num<<" num[j] = "<<Rec[j].num<<endl;
        if(Rec[j].num == Rec[a].num && j != a){
            Rec[j].num = i;
        }
    }
    Rec[a].num = i;
}

int main()
{
    long long x1,x2;
    long long y1,y2;
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    while(scanf("%I64d",&n) != EOF){
        for(int i = 0;i < n;i++){
            Rec[i].num = i;
            scanf("%I64d %I64d %I64d %I64d",&x1,&y1,&x2,&y2);
            if(x1 > x2){Rec[i].left = x2;Rec[i].right = x1;}
            else {Rec[i].left = x1;Rec[i].right = x2;}
            if(y1 > y2){Rec[i].top = y1;Rec[i].down = y2;}
            else {Rec[i].top = y2;Rec[i].down = y1;}

            for(int a = 0;a < i;a++){
                if(Rec[a].num != Rec[i].num){
                    merg(a,i);
                }
            }
        }

        //for(int i = 0;i < n;i++){
        //    for(int a = 0;a < i;a++){
        //        if(Rec[a].num != Rec[i].num){
        //            merg(a,i);
        //        }
        //    }
        //}

        //for(int i = 0;i < n;i++){
        //    cout <<"num = "<<Rec[i].num<<endl;
        //}

        memset(ans,0,sizeof(ans));
        for(int i = 0;i < n;i++){
            ans[Rec[i].num] = 1;
        }
        long long temp = 0;
        for(int i = 0;i < 101;i++){
            if(ans[i]){
                //cout <<"i = "<<i<<endl;
                temp++;}
        }
        printf("%I64d\n",temp);

    }

    return 0;
}
