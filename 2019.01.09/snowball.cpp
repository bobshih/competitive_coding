#include <iostream>
#include <cstdio> 

using namespace std;

int main(){
	int ball_height, ball_weight;
	int stone1_height, stone1_weight;
	int stone2_height, stone2_weight;
	
	scanf(" %d %d", &ball_weight, &ball_height);
	scanf(" %d %d", &stone1_weight, &stone1_height);
	scanf(" %d %d", &stone2_weight, &stone2_height);
	
	while(ball_height != 0){
//		printf("weight = %d height = %d\n", ball_weight, ball_height);
		ball_weight += ball_height;
		if(ball_height == stone1_height){
			ball_weight -= stone1_weight;
		}else if(ball_height == stone2_height){
			ball_weight -= stone2_weight;
		}
		
		if(ball_weight <= 0){
			ball_weight = 0;
		}
		ball_height --;
	}
	
	if(ball_weight <= 0){
		printf("0");
	}else{
		printf("%d", ball_weight);
	}
	return 0;
}
