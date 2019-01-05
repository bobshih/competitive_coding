// Om Nom and Dark Park.cpp: 主要專案檔。

//#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int h;
int edge[5000];
int extend[5000];
int maximum;
int v[5000];
bool flag = 0;

void dfs_m(int p, int value){
	v[p] = value;
	if (edge[p * 2] != 0)
		dfs_m(p * 2 + 0, value + edge[p * 2]);
	else {
		if (maximum < value)
			maximum = value;
	}
	if (edge[p * 2 + 1] != 0)
		dfs_m(p * 2 + 1, value + edge[p * 2 + 1]);
	else {
		if (maximum < value)
			maximum = value;
	}
}

void dfs(int p, int value){
	//std::cout << "p = " << p << " value = " << value << std::endl;
	if (edge[p * 2] != 0){
		dfs(p * 2, value + edge[p * 2] + extend[p * 2]);
	}
	else{

		if (value < maximum){
			//std::cout <<"asf = "<< maximum - value << std::endl;
			extend[p] += (maximum - value);
		}
	}
	if (edge[p * 2 + 1] != 0){
		dfs(p * 2 + 1, value + edge[p * 2 + 1] + extend[p * 2 + 1]);
	}
	else{
		if (value < maximum){
			extend[p] += (maximum - value);
		}
	}
}

int min(int a, int b){
	if (a == b)return -1;
	if (a < b){
		return a;
	}
	return b;
}

void merge(int n){
	//std::cout << "n = " << n << std::endl;
	if (extend[n * 2] != 0 && extend[n * 2 + 1] != 0){
		int m = min(extend[n * 2 + 1], extend[n * 2]);
		//std::cout << "m = " << m << std::endl;
		flag = false;
		if (m == -1){
			extend[n] += extend[n * 2 + 1];
			extend[n * 2] = extend[n * 2 + 1] = 0;
			merge(n / 2);
		}
		else {
			extend[n] += m;
			extend[n * 2] -= m;
			extend[n * 2 + 1] -= m;
			merge(n / 2);
		}
	}
}

int main(/*array<System::String ^> ^args*/)
{
	scanf("%d", &h);
	int e = pow(2, h + 1) - 2;
	memset(edge, 0, sizeof(edge));
	memset(extend, 0, sizeof(extend));
	memset(v, 0, sizeof(v));
	for (int i = 2; i <= e + 1; i++){
		scanf("%d", &edge[i]);
		//std::cout << "i = " << i << " edge[] = " << edge[i] << std::endl;
	}
	maximum = 0;
	dfs_m(1, 0);
	dfs(1, 0);
	int node = pow(2, h + 1);
	for (int i = 2; i <= e + 1; i++){
		extend[i] /= 2;
		//std::cout << extend[i] << std::endl;
	}
	//std::cout << "max = " << maximum << std::endl;
	while (true){
		flag = true;
		for (int i = 0; i < node; i++){
			merge(i);
		}
		for (int i = 2; i <= e + 1; i++){
			//extend[i] /= 2;
			//std::cout << extend[i] << std::endl;
		}
		if (flag){
			break;
		}
	}
	int ans = 0;
	for (int i = 0; i <= e + 1; i++){
		ans += extend[i];
	}
	printf("%d", ans);
	//system("pause");

	return 0;
}
