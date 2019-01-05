#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int doller;
int max_v = 0;
int ans[10000][5];
const int cent[5] = {1, 5, 10, 25, 50}; 

int main(){
	memset(ans, 0, sizeof(ans));
	for(int i = 0;i < 5;i++){
		ans[0][i] = 1;
	}
	for(int i = 0;i < 10000;i++){
		ans[i][0] = 1;
	}
	//ans[1][0] = 1;
	ans[5][1] = 1;
	ans[10][2] = 1;
	ans[25][3] = 1;
	ans[50][4] = 1;
	
	while(scanf("%d", &doller) == 1){
		if(doller > max_v){
			for(int i = max_v+1;i <= doller;i++){
				//ans[i][0] += ans[i-cent[0]][0];
				for(int j = 1;j < 5;j++){
					ans[i][j] = ans[i][j-1];
					if(i - cent[j] >= 0)
						ans[i][j] += ans[i-cent[j]][j];
					//else ans[i][j] += ans[0][j];
				}
			}
			
			/*for(int i = 0;i <= doller;i++){
				for(int j = 0;j < 5;j++){
					cout <<ans[i][j]<<"\t";
				}cout <<endl;
			}*/
			max_v = doller;
			printf("%d\n", ans[doller][4]);
		}
		else {
			printf("%d\n", ans[doller][4]);
		}
	}
	
	return 0;
} 
