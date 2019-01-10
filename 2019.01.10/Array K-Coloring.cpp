#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
	int n, k, t;
	vector<int> arr;
	unordered_map<int, int> map;
	unordered_map<int, vector<int>> color_arr;
	
	scanf("%d %d ", &n, &k);
	for(int i = 0;i < n;i++){
		scanf("%d", &t);
		arr.push_back(t);
		if(map.find(t) == map.end()){
			map[t] = 1;
			color_arr[t] = vector<int>();
		}else{
			map[t] += 1;
		}
	}
	bool flag = false;
	for(auto v :  map){
//		printf("%d %d\n", v.first, v.second);
		if(v.second > k){
			flag = true;
			break;
		}
	}
	
	if(flag){
		printf("NO\n");
	}else{
		printf("YES\n");
		int used_color = 1;
		for(int a : arr){
//			for(auto temp : color_arr){
//				printf("ele: %d,", temp.first);
//				for(int te : temp.second){
//					printf(" %d", te);
//				}cout<<endl;
//			}
			if(used_color <= k){
				printf("%d ", used_color);
				color_arr[a].push_back(used_color);
				used_color++;
			}else{
				while(true){
					if(find(color_arr[a].begin(), color_arr[a].end(), map[a]) != color_arr[a].end()){
						map[a]--;
					}else{
						color_arr[a].push_back(map[a]);
						printf("%d ", map[a]);
						map[a]--;
						break;
					}
				}
			}
//			printf("%d %d\n", a, map[a]);
//			color_arr.push_back(map[a]);
//			map[a] -= 1;
		}
	}
	
	return 0;
} 
