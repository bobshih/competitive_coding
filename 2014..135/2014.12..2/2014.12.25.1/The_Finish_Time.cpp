#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring> 
#include <vector>
using namespace std;

int test;
int n;
int t[105];
int p;
vector<int> priority[10005];
int ans[105];

void DFS(int node){
	//cout <<"node = "<<node<<" size = "<<priority[node].size()<<endl;
	if(ans[node] != -1){
		//cout <<"has counted\n";
		return;
	}
	if(priority[node].size() == 0){
		ans[node] = t[node];
		//cout <<"no parents\n";
		return;
	}
	
	int max = -1;
	for(int i = 0;i < priority[node].size();i++){
		int temp = priority[node][i];
		DFS(temp);
		//cout <<"temp = "<<temp<<" ans[temp] = "<<ans[temp]<<endl;
		if(ans[temp] > max)max = ans[temp];
	}
	
	//cout <<"node = "<<node<<" max = "<<max<<endl;
	ans[node] = max+t[node];
}

int main(){
	freopen("testdata.in", "r", stdin);
	
	scanf("%d", &test);
	while(test--){
		memset(t, 0, sizeof(t));
		scanf("%d", &n);
		for(int i = 1;i <= n;i++){
			scanf("%d", &t[i]);
		}
		scanf("%d", &p);
		//cout <<"p = "<<p<<endl;
		for(int i = 1;i < n;i++){
			priority[i].clear();
		} 
		for(int i = 0;i < p;i++){
			int t1, t2;
			scanf("%d %d", &t1, &t2);
			priority[t2].push_back(t1);
		}
		/*for(int i = 1;i <= n;i++){
			cout <<"i = "<<i<<endl;
			for(int j = 0;j < priority[i].size();j++){
				cout <<priority[i][j]<<" ";
			}cout <<endl;
		}*/
		memset(ans, -1, sizeof(ans));
		for(int i = 1;i <= n;i++){
			DFS(i);
		}
		int max = -1;
		for(int i = 1;i <= n;i++){
			//printf("ans[%d] = %d\n", i, ans[i]);
			if(ans[i] > max)max = ans[i];
		}
		printf("%d\n", max);
	}
} 
