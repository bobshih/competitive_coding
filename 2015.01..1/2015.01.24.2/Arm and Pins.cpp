#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main(){
	long long r, x0, y0, x1, y1;
	scanf("%I64d %I64d %I64d %I64d %I64d", &r, &x0, &y0, &x1, &y1);
	long long dis = (x0-x1)*(x0-x1) + (y0-y1)*(y0-y1);
	//cout <<"dis = "<<dis<<endl;
	double ans = sqrt(dis/(4*r*r));
	//cout <<"ans = "<<ans<<" floor(ans) = "<<floor(ans)<<endl;
	if(((long long)floor(ans)*2*r)*((long long)floor(ans)*2*r) < dis){
		printf("%d\n", (int)floor(ans)+1);
	}else printf("%d\n", (int)floor(ans));
	
	return 0;
} 
