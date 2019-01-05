#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct T{
	int n;
	int index;
	
	bool operator < (const T &rhs)const{
		if(rhs.n == n){
			return index < rhs.index;
		}
		return n < rhs.n;
	}
}arr[100005];

int main(){
	int n;
	scanf("%d", &n);
	
	for(int i = 0;i < n;i++){
		scanf("%d", &arr[i].n);
		arr[i].index = i;
	}sort(arr, arr+n);
	
	int ans = 0;
	int max = arr[0].index;
	for(int i = 0;i < n;i++){
		max = (arr[i].index >= max)?arr[i].index:max;
		//printf("%d %d %d\n", arr[i].index, arr[i].n, max);
		if(max <= i){
			ans++;
		}
	}
	cout <<ans<<endl;
}
