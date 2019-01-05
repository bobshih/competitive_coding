#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int len;
int cut_size;
int cuts[105];
int ans[105][105];

int FindSmall(int start, int end, int c[], int cs){
	if(ans[start][end] != 0){
		return ans[start][end];
	}
	if(cs == 0){
		return ans[start][end];
	}
	
	
	int temp = 1e9;
	
	for(int i = 0;i < cs;i++){
		int left, right;
		left = FindSmall(start, c[i], c, i);
		right = FindSmall(c[i], end, c+i+1, cs-i-1);
		if(left+right < temp){
			temp = left+right;
		}
	}
	
	ans[start][end] = temp + end-start;
	return ans[start][end];
}

int main(){
	int test;
	scanf("%d", &test);
	
	while(test--){
		scanf("%d", &len);
		cut_size = 0;
		while(true){
			int temp;
			scanf("%d", &temp);
			if(temp == 0){
				break;
			}
			cuts[cut_size++] = temp;
		}
		
		memset(ans, 0 , sizeof(ans));
		FindSmall(0, len, cuts, cut_size);
		printf("%d\n", ans[0][len]);
	}
	
	return 0;
} 
