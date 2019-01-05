#include <iostream>
#include <cstdio>

using namespace std;

int n;
int a[100005];
int pri[30000];

bool test_p(int num, int s){
	for(int i = 0;i < s;i++){
		//cout <<pri[i]<<endl;
		if(num%pri[i] == 0)return false;
	}
	return true;
}

int main(){
	pri[0] = 2;
	pri[1] = 3;
	int t = 4;
	int d;
	for(d = 2;d < 30000;d++){
		//cout <<"t = "<<t<<endl;
		if(t > 100000)break;
		if(test_p(t, d)){
			pri[d] = t;//i++;
			//cout <<"pri = "<<t<<" d = "<<d<<endl;
			t++;
		}else{
			d--;
			t++;
		}
	}pri[0] = 4;
	//return 0;
	scanf("%d", &n);
	int temp = 0;
	for(int i = 0;i < n;i++){
		scanf("%d", &a[i]);
		if(a[i] == 1)temp++;
	}
	
	if(temp == n){
		puts("YES");
		return 0;
	}
	
	bool flag = false;
	for(int i = 0;i < d;i++){
		if(flag)break;
		if(pri[i] > n)break;
		if(n%pri[i] == 0){
			int t = n/pri[i];
			for(int j = 0;j < n/pri[i];j++){
				bool flag2 = false;
				for(int k = j;k < n;){
					if(a[k] == 0){
						flag2 = true;
						break;
					}k+=(n/pri[i]);
				}
				if(!flag2){
					flag = true;
					break;
				}
			}
		}
	}
	
	if(flag){
		puts("YES");
	}else{
		puts("NO");
	}
	return 0;
} 
