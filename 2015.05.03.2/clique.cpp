#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct circle{
	long long left, right;
	bool operator < (const circle &rhs)const{
		if(right != rhs.right)
			return right < rhs.right;
		return left < rhs.left;
	}
};

long long n;
circle input[200005];

int main(){
	scanf("%I64d", &n);
	long long x, w;
	for(int i = 0;i < n;i++){
		scanf("%I64d %I64d", &x, &w);
		input[i].left = x-w;
		input[i].right = x+w;
	}
	sort(input, input+n);
	//for(int i = 0;i < n;i++){
	//	cout <<input[i].left<<" "<<input[i].right<<endl;
	//}
	
	long long l = input[0].left;
	long long r = input[0].right;
	long long ans = 1;
	for(int i = 1;i < n;i++){
		if(input[i].left >= r){
			r = input[i].right;
			ans++;
		}
	}
	cout <<ans<<endl;
	return 0;
} 
