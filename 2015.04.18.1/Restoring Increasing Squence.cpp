#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char in[100005][10];
int len[100005];

void SetZero(char t[], int i){
	for(int j = 0;j < len[i];j++){
		if(t[j] == '?'){
			if(j == 0)
				t[j] = '1';
			else 
		  		t[j] = '0';
		}
	}
}

bool cmp(char a[], char b[], int len){
	for(int i = 0;i < len;i++){
		if(a[i] > b[i])
			return true;
		else if(a[i] < b[i])
			return false;
	}
	return false;
}

int main(){
	//freopen("in.txt", "r", stdin);
	
	int n;
	scanf("%d", &n);
	
	for(int i = 0;i < n;i++){
		scanf("%s", in[i]);
		len[i] = strlen(in[i]);
	}
	
	SetZero(in[0], 0);
	
	bool flag = false;
	for(int i = 1;i < n;i++){
		if(flag)
			break;
		
		if(len[i] > len[i-1]){
			//直接補上最小數字 
			SetZero(in[i], i);
		}else if(len[i] < len[i-1]){
			flag = true;
			continue;
		}else {
			char temp[10];
			strcpy(temp, in[i]);
			
			bool ans = false;
			int q = 0;
			for(int j = 0;j < len[i];j++){
				if(in[i][j] == '?')
					q++;
			}
			for(int j = 0;j <= q;j++){
				int k = j;
				int pos = 0;
				strcpy(temp, in[i]);
				while(k--){
					for(;pos < len[i];pos++){
						if(temp[pos] == '?'){
							temp[pos] = in[i-1][pos];
							break;
						}
					}
				}
				SetZero(temp, i);
				if(cmp(temp, in[i-1], len[i])){
					strcpy(in[i], temp);
					ans = true;
					break;
				}
			}
			if(ans)
				continue;
			
			strcpy(temp, in[i]);
			int add = 0;
			int c;
			do {
		 		c = add;
				for (int j = len[i]-1;j >= 0;j--){
					if(in[i][j] == '?'){
						int t = in[i-1][j] - '0';
						t += c;
						c = t/10;
						t = t%10;
						temp[j] = t + '0';
					}
				}
				
				if(c != 0){
					flag = true;
					break;
				}else {
					if(cmp(temp, in[i-1], len[i])){
						strcpy(in[i], temp);
						break;
					}
				}
				add++;
			}while (true);
		}
	}
	
	if(flag){
		printf("NO\n");
	}else {
		printf("YES\n");
		for(int i = 0;i < n;i++){
			printf("%s\n", in[i]);
		}
	}
	
	return 0;
} 
