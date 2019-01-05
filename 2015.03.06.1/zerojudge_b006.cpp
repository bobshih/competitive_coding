#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Rect{
	int w,l;
	
	bool operator < (const Rect &rhs)const{
		if(w == rhs.w)return l <= rhs.l;
		return w <= rhs.w;
	}
};
vector<Rect> rr;
int n;
int DP[30005][2];

int main(){
	while(scanf("%d", &n) != EOF){
		rr.clear();
		int a, b;
		for(int i = 0;i < n;i++){
			scanf("%d %d", &a, &b);
			Rect temp;
			if(a == b){
				temp.w = temp.l = a;
				rr.push_back(temp);
			}else {
				temp.w = a, temp.l = b;
				rr.push_back(temp);
				temp.l = a, temp.w = b;
				rr.push_back(temp);
			}
		}sort(rr.begin(), rr.end());
		//for(int i = 0;i < rr.size();i++){
		//	cout <<rr[i].w<<" "<<rr[i].l<<endl;
		//}
		
		int t[30005];
		memset(t, 0, sizeof(t));
		//for(int i = 0;i < rr.size();i++)cout <<t[i]<<endl;
		
		for(int i = 0;i < rr.size();i++){
			for(int j = i+1;j < rr.size();j++){
				//cout <<"rr[i].w = "<<rr[i].w<<" rr[i].l = "<<rr[i].l<<" rr[j].w = "<<rr[j].w<<" rr[j].l = "<<rr[j].l<<endl;
				if(rr[i].w <= rr[j].w && rr[i].l <= rr[j].l){
					//cout <<"!\n";
					t[j] = max(t[i]+1, t[j]);
					//cout <<"t["<<j<<"] = "<<t[j]<<endl;
				}
			}
		}
		
		int maximum = 0;
		for(int i = 0;i < rr.size();i++){
			//cout <<"t["<<i<<"] = "<<t[i]<<endl;
			if(maximum < t[i])maximum = t[i];
		}
		
		cout <<maximum+1<<endl;
	}
	
	return 0;
}
