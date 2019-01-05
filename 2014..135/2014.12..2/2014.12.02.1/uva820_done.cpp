#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int cap[101][101];
int flow[101][101];
int n, s, t, c;
int f[101];
int p[101];
//pair<int, int> path[101];
//vector<pair<int, int> > path;
//int flow[102];
//bool visit[102];

int BFS(int source, int sink){
	int result = 0;
	
	while(1){
	    memset(f, 0, sizeof(f));
	    //memset(flow, 0, sizeof(flow));
	    queue<int> Q;
	    Q.push(source);
	    //visit[source] = 1;
	    p[source] = source;
	    f[source] = 1e9;
	    //path[source] = make_pair(1, (int)1e9);
	    
	    //for(int i = 1;i <= n;i++){
		//	for(int j = 1;j <= n;j++){
		//		if(cap[i][j] != 0)
		//			cout <<"i = "<<i<<" j = "<<j<<" f = "<<flow[i][j]<<endl;
		//	}
		//}
	    while (Q.size() != 0 && f[sink] == 0){
			int start = Q.front();Q.pop();
			for (int i = 0;i <= n;i++){
				if (f[i] == 0 && flow[start][i] + flow[i][start] < cap[start][i]){
					Q.push(i);
					//visit[i] = 1;
					f[i] = min(f[start], cap[start][i] - flow[i][start]);
					p[i] = start;
					//cout <<"start = "<<start<<" i = "<<i<<" f = "<<f<<endl;
					//if(i == sink){
						//cout <<"return is "<<f<<endl;
					//	break;
					//}
				}
			}
	    }
	    if(f[sink] == 0)break;
	    
	    int temp;
	    result += f[sink];
	    for(int i = p[sink], j = sink; i != j;i = p[i], j = temp){
	    	temp = i;
	    	flow[j][i] += f[sink];
	    }
	    
	}
	return result;
}
/*
int MAX_FLOW(int source, int sink){
    int f, df;
    
    int temp;
    for (f = 0; df = BFS(source, sink); f += df){
        for(int i = path[sink].first, j = sink; i != j;i = path[i].first, j = temp){
        	//cout <<"i = "<<i<<" j = "<<j<<endl;
			temp = i;
			//flow[i][j] += df;
			flow[j][i] += df;
		}
    }
    return f;
}*/ 

int main(){
    int test = 0;
    
    while (scanf("%d", &n)){
		if(n == 0)break;
		scanf("%d %d %d", &s, &t, &c);              
		memset(cap, 0, sizeof(cap));
		memset(flow, 0, sizeof(flow));
		for (int i = 0;i < c;i++){
			int node1, node2, ca;
			scanf("%d %d %d", &node1, &node2, &ca);
			cap[node1][node2] = (cap[node2][node1] += ca);       
		}
		
		printf("Network %d\n", ++test);
		printf("The bandwidth is %d.\n\n", BFS(s, t));
		//cout <<"flow is\n";
		//for(int i = 1;i <= n;i++){
		//	for(int j = 1;j <= n;j++){
		//		if(cap[i][j] != 0)
		//			cout <<"i = "<<i<<" j = "<<j<<" f = "<<flow[i][j]<<endl;
		//	}
		//}
    }
    
    //system("PAUSE");
    return 0;    
}
