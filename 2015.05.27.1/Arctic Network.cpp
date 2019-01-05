#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

struct edge{
	double dis;
	int p1, p2;
	
	bool operator < (const edge &rhs)const{
		return dis < rhs.dis;
	}
};
int s, n;
edge e[300000];
int post[505][2];
int pos_e;

void make_edge(int p1, int p2){
	double d = (post[p1][0] - post[p2][0])*(post[p1][0] - post[p2][0]) + (post[p1][1] - post[p2][1])*(post[p1][1] - post[p2][1]);
	e[pos_e].dis = sqrt(d);
	e[pos_e].p1 = p1;
	e[pos_e].p2 = p2;
	pos_e++;
}

bool vis[505];

int main(){
	int tests;
	scanf("%d", &tests);
	
	while(tests--){
		scanf("%d %d", &s, &n);
		for(int i = 0;i < n;i++){
			scanf("%d %d", &post[i][0], &post[i][1]);
		}
		
		pos_e = 0;
		for(int i = 0;i < n;i++){
			for(int j = i+1;j < n;j++){
				make_edge(i, j);	
			}
		}
		//cout <<"pos_e = "<<pos_e<<endl;
		sort(e, e+pos_e);
		//for(int i = 0;i < pos_e;i++){
		//	cout <<"i = "<<i<<" dis = "<<e[i].dis<<endl;
		//} 
		
		vector<edge> ans;
		ans.clear();
		int dsu[505];
		memset(dsu, -1, sizeof(dsu));
		for(int i = 0;i < pos_e;i++){
			int temp1, temp2;
			temp1 = e[i].p1, temp2 = e[i].p2;
			
			if(dsu[temp1] == -1 && dsu[temp2] == -1){
				dsu[temp1] = dsu[temp2] = temp1;
				ans.push_back(e[i]);
			}else if(dsu[temp1] == -1){
				dsu[temp1] = dsu[temp2];
				ans.push_back(e[i]);
			}else if(dsu[temp2] == -1){
				dsu[temp2] = dsu[temp1];
				ans.push_back(e[i]);
			}else {
				if(dsu[temp1] != dsu[temp2]){
					int k = dsu[temp1];
					for(int j = 0;j < n;j++){
						if(dsu[j] == k){
							dsu[j] = dsu[temp2];
						}
					}
					ans.push_back(e[i]);
				}
			}
		}
		
		//cout <<"size of ans = "<<ans.size()<<endl;
		int pos_ans = n-2-s+1;
		
		printf("%.2f\n", ans[pos_ans].dis);
	}
	
	return 0;
} 
