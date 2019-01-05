#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
using namespace std;

struct node{
    double x;
    double y;
    int index;
};

int num;
vector<pair<node,node> > sticks;

double cross(node a,node b,node c){
    double x1,x2,y1,y2;
    x1 = b.x-a.x;
    y1 = b.y-a.y;
    x2 = c.x-a.x;
    y2 = c.y-a.y;
    return x1*y2 - x2*y1;
}
bool check_dot(pair<node,node> t,node n){
    double x1,x2,y1,y2;
    x1 = t.first.x-n.x;
    x2 = t.second.x-n.x;
    y1 = t.first.y-n.y;
    y2 = t.second.y-n.y;

    double num = x1*x2 + y1*y2;
    if(num >= 0)return true;
    else return false;
}

bool check(int i,pair<node,node> t){
    bool s = 0;

    double a = cross(sticks[i].first,sticks[i].second,t.first);
    double b = cross(sticks[i].first,sticks[i].second,t.second);
    if(a == 0 && b == 0){
        //cout <<"a = 0,b = 0 i = "<<i<<endl;
        if(check_dot(sticks[i],t.first) && check_dot(sticks[i],t.second) && check_dot(t,sticks[i].first) && check_dot(t,sticks[i].second)){return false;}
        return true;
    }
    if(a*b >= 0)return false;

    a = cross(t.first,t.second,sticks[i].first);
    b = cross(t.first,t.second,sticks[i].second);
    if(a*b < 0)return true;
    return false;
}

void push(pair<node,node> temp){
    for(int i = 0;i < sticks.size();i++){
        if(check(i,temp)){
            //cout <<"erase "<<sticks[i].first.index<<endl;
            sticks.erase(sticks.begin()+i);
            i--;
        }
    }
    sticks.push_back(temp);
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    node t1,t2;
    pair<node,node> temp;

    while(scanf("%d",&num)){
        if(num == 0)break;
        sticks.clear();

        int i = 0;
        for(int i = 0;i < num;i++){
            scanf("%lf %lf %lf %lf",&t1.x,&t1.y,&t2.x,&t2.y);
            t1.index = i+1;t2.index = i+1;
            //if(t1.x > t2.x){temp = make_pair(t1,t2);}
            //else
            temp = make_pair(t2,t1);
            push(temp);
        }

        printf("Top sticks:");
        for(int i = 0;i < sticks.size()-1;i++){
            printf(" %d,",sticks[i].first.index);
        }printf(" %d.\n",sticks.back().first.index);
    }

    return 0;
}
