#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct instr{
	int d;
	int index;
	bool operator < (const instr &rhs)const{
		return d < rhs.d;
	}
}a[102];

int main(){
	int n, k;
	scanf("%d %d", &n, &k);
	for(int i = 0;i < n;i++){
		scanf("%d", &a[i].d);
		a[i].index = i+1;
	}
	sort(a, a+n);
	int ans = 0, ddd[101];
	for(int i = 0;i < n;i++){
		if(k >= a[i].d){
			ddd[i] = a[i].index;
			k-=a[i].d;
			ans++;
		}else break;
	}sort(ddd, ddd+ans);
	printf("%d\n", ans);
	if(ans == 0)return 0;
	for(int i = 0;i < ans-1;i++){
		printf("%d ", ddd[i]);
	}printf("%d\n", ddd[ans-1]);
	
	return 0;
} 
