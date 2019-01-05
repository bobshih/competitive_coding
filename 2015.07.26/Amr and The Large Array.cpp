#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct data{
	int index;
	int start, end;
	int c;
	
	
};
int size;
int arr[100005];

bool cmp (data d1, data d2){
	if(d1.c != d2.c)
		return d1.c < d2.c;
	return d1.end - d1.start > d2.end-d2.start;
}

int main(){
	scanf("%d", &size);
	data *count = new data[1000005];
	for(int i = 0;i < 1000005;i++){
		count[i].c = 0;
		count[i].index = i;
		count[i].start = -1;
	}
	//for(int i = 0;i < 100;i++){
	//	cout <<count[i]<<endl;
	//}
	int ans, max = -1;
	for(int i = 0;i < size;i++){
		scanf("%d", &arr[i]);
		//cout <<arr[i]<<endl;
		count[arr[i]].c++;
		if(count[arr[i]].start == -1){
			count[arr[i]].start = i;
		}
		if(count[arr[i]].start != -1){
			count[arr[i]].end = i;
		}
	}sort(count, count+1000005, cmp);
	//for(int i = 0;i < 20;i++){
	//	cout <<count[i].c<<" "<<count[i].start<<" "<<count[i].end<<endl;
	//}
	
	printf("%d %d\n", count[1000004].start+1, count[1000004].end+1);
	
	return 0;
}
