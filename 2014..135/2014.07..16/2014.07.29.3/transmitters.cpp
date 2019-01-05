#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cmath>

#define PI 3.14159265

1.
利用外積檢查是否在半圓內
2.
初始化時，設為0，否則會WA

using namespace std;

int tx,ty;
double tr;
vector<pair<int,int> > point;

double cross_product(int a,int b){
    int x1,x2,y1,y2;
    x1 = point[a].first-tx;
    x2 = point[b].first-tx;
    y1 = point[a].second-ty;
    y2 = point[b].second-ty;

    return x1*y2 - x2*y1;
}

int main()
{
    pair<int,int> temp;

    while(scanf("%d %d %lf",&tx,&ty,&tr) == 3){
        if(tr < 0)break;
        //cout <<tr<<endl;
        point.clear();
        int p;scanf("%d",&p);

        int t1,t2;
        for(int i = 0;i < p;i++){
            scanf("%d %d",&t1,&t2);
            if((t1-tx)*(t1-tx) + (t2-ty)*(t2-ty) - tr*tr > 1e-10)continue;
            else {
                temp = make_pair(t1,t2);
                point.push_back(temp);
            }
        }
        //cout <<"contain:\n";
        //for(int i = 0;i < point.size();i++){
        //    cout <<point[i].first<<"\t"<<point[i].second;
        //    cout <<"\t"<<degree[i]<<endl;
        //}

        int m = 0;
        for(int i = 0;i < point.size();i++){
            int a = 0,b = 0;                           //a代表是由該點順時針，180度以內的點，b則是該點逆時針180度以內的點
            for(int j = 0;j < point.size();j++){
                double tt = cross_product(i,j);
                if(tt > 0){a++;}
                else if(tt < 0){b++;}
                else {a++;b++;}
            }
            //cout <<"i = "<<i<<" a = "<<a<<" b = "<<b<<endl;
            if(a > m){m = a;}
            if(b > m){m = b;}
        }
        printf("%d\n",m);
    }

    return 0;
}
