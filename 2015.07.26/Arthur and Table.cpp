#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int a[6];
	int max = -1, index;
	for(int i = 0;i < 6;i++){
		scanf("%d", &a[i]);
		if(max < a[i]){
			max = a[i];
			index = i;
		}
	}
	
	int temp = 0;
	//if(index == 0 || index == 2 || index == 4){
		a[0] += a[1] + a[5];
		a[2] += a[1] + a[3];
		a[4] += a[5] + a[3];
		temp += (a[1]*a[1]) + (a[5]*a[5]) + (a[3]*a[3]);
	//}
	
	printf("%d\n", a[0]*a[0]-temp);
	return 0;
} 
