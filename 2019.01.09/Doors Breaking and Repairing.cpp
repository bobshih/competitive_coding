#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int n, x, y, temp;
	scanf("%d %d %d", &n, &x, &y);
	vector<int> doors;
	for(int i = 0;i < n;i++){
		scanf("%d", &temp);
		doors.push_back(temp);
	}
	
	if(x > y){
		printf("%d", n);
	}else{
		int count = 0;
		for(int i = 0;i < doors.size();i++){
			if(doors[i] <= x){
				count ++;
			}
		}
		if(count%2){
			printf("%d", count/2+1);
		}else{
			printf("%d", count/2);
		}
	}
	
	return 0;
}
