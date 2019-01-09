#include <iostream> 
#include <cstdio>

using namespace std;

int main(){
	long long k;
	scanf("%d", &k);
	
	long long total = k*(k+1)/2;
	if(total%2){
		printf("1");
	}else{
		printf("0");
	}
}
