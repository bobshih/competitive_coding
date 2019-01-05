#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

struct coord{
    int x1,x2;
    int len;

    bool operator <(const coord &a) const{
        if(x1 == a.x1)return len < a.len;
        return x1 < a.x1;
    }
};
coord w[101];
int co;
bool cmp(int a,int b){
    int temp1,temp2;
    temp1 = w[a].x2 - co;
    temp2 = w[b].x2 - co;
    return temp1 > temp2;
}

void setx(int a){
    //cout <<a<<" is going to be set -1\n";
    w[a].x2 = -1;
}

int main()
{
    int test;
    scanf("%d",&test);
    int wall,k;
    int ans;

    int temp_y1,temp_y2;

    for(int i = 0;i < test;i++){
        ans = 0;
        scanf("%d %d",&wall,&k);
        for(int i = 0;i < wall;i++){
            scanf("%d %d %d %d",&w[i].x1,&temp_y1,&w[i].x2,&temp_y2);
            if(w[i].x1 > w[i].x2){
                int t = w[i].x1;
                w[i].x1 = w[i].x2;
                w[i].x2 = t;
            }
            w[i].len = w[i].x2-w[i].x1+1;
        }sort(&w[0],&w[wall]);

        //for(int i = 0;i < wall;i++){
        //    printf("%d %d %d\n",w[i].x1,w[i].x2,w[i].len);
        //}

        int x = w[wall-1].x2;
        int sum;
        int wall_num[101];

        for(co = 0;co <= x;co++){
            sum = 0;
            for(int a = 0;a < wall;a++){
                if(w[a].x1 <= co && w[a].x2 >= co){sum++;}
            }
            //cout <<"sum = "<<sum<<endl;
            if(sum > k){
                //system("pause");
                int temp = 0;
                for(int a = 0;a < wall;a++){
                    if(w[a].x1 <= co && w[a].x2 >= co){
                        wall_num[temp] = a;temp++;
                    }
                }sort(wall_num,wall_num+temp,cmp);

                //for(int a = 0;a < temp;a++){
                //    printf("%d %d\n",wall_num[a],w[wall_num[a]].len);
                //}

                for(int i = 0;i < sum-k;i++){
                    setx(wall_num[i]);ans++;
                }
            }
        }
        printf("%d\n",ans);

    }

    return 0;
}
