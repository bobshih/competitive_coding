#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int pri[5000005];
int ans[5000005];

int main(){
	int test;
	scanf("%d", &test);

	//pri = (bool*)malloc(5000005*sizeof(bool*));
	memset(pri, 0, sizeof(pri));
	pri[0] = 1;
	pri[1] = 1;
	pri[2] = 0;
	
	for(int i = 2;i < 5000005;i++){
		if(pri[i] != 0)
			continue;
		for(int a = 2;a <= 5000005/i;a++){
			//if(i == 43)
			//	cout <<"a = "<<a<<" product = "<<a*i<<endl;
			pri[a*i] = i;
		}
		//if(i > 4999994)
		//	cout <<"i = "<<i<<" pri = "<<pri[i]<<endl;
	}
	for(int i = 2;i < 5000005;i++){
		if(pri[i] == 0){
			ans[i] = 1;
		}else{
			int temp = pri[i];
			ans[i] = ans[temp]+ans[i/temp];
		}
		//if(i > 4999994)
		//	cout <<"i = "<<i<<" ans = "<<ans[i]<<endl;
	}
	for(int i = 3;i < 5000005;i++){
		ans[i] += ans[i-1]; 
		//if(i > 4999994)
		//	cout <<"i = "<<i<<" ans = "<<ans[i]<<endl;
	}
	
	int a, b;
	while(test--){
		scanf("%d %d", &a, &b);
		int fin = ans[a] - ans[b];
		//for(int i = b+1;i <= a;i++){
		//	fin+=ans[i];
		//}
		printf("%d\n", fin);
	}
	
	return 0;
} 
