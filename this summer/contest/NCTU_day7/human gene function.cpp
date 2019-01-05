#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int m[150][150];
int dp[150][150];

int Max(int a,int b,int c)
{
	if(a>=b && a>=c) return a;
	else if(b>=a && b>=c) return b;
	else return c;
}

int main(){
	m['A']['A']=5;m['A']['C']=-1;m['A']['G']=-2;m['A']['T']=-1;m['A']['-']=-3;
	m['C']['A']=-1;m['C']['C']=5;m['C']['G']=-3;m['C']['T']=-2;m['C']['-']=-4;
	m['G']['A']=-2;m['G']['C']=-3;m['G']['G']=5;m['G']['T']=-2;m['G']['-']=-2;
	m['T']['A']=-1;m['T']['C']=-2;m['T']['G']=-2;m['T']['T']=5;m['T']['-']=-1;
	m['-']['A']=-3;m['-']['C']=-4;m['-']['G']=-2;m['-']['T']=-1;m['-']['-']=0;

	int i,j,N;
	scanf("%d",&N);
	while(N--)
	{
		char s1[101]={0},s2[101]={0};
		int n1,n2;
		scanf("%d %s",&n1,s1+1);
		scanf("%d %s",&n2,s2+1);

		dp[0][0]=0;
		for(i=1;i<=n2;i++)
			dp[0][i]=dp[0][i-1]+m['-'][s2[i]];
		for(i=1;i<=n1;i++)
			dp[i][0]=dp[i-1][0]+m[s1[i]]['-'];
		for(i=1;i<=n1;i++){
			for(j=1;j<=n2;j++){

				dp[i][j]=Max(dp[i-1][j-1]+m[s1[i]][s2[j]],dp[i-1][j]+m[s1[i]]['-'],dp[i][j-1]+m['-'][s2[j]]);}//cout <<dp[i][j]<<"\t";
            //cout <<endl;
	}
		printf("%d\n",dp[n1][n2]);
	}
	return 0;
}
