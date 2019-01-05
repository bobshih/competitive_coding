#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main(){
    int num_0;
    int num_1;
    int temp;
    int flag = 0;

    while(scanf("%d %d",&num_0,&num_1) == 2){
        if((num_0+1)*2 < num_1){printf("%d\n",-1);continue;}

        if(num_0 - num_1 == 1){goto another_step;}
        else if(num_0 - num_1 > 1){printf("%d\n",-1);continue;}

        temp = num_1 - (num_0+1);
        if(temp >= 0){flag = 1;}

        for(int i = 0;i < num_0;i++){
            if(temp > 0){printf("%d%d%d",1,1,0);temp--;}
            else {printf("%d%d",1,0);}
        }
        if(flag == 1 && temp == 1){printf("%d%d",1,1);}
        else if(flag == 1){printf("%d",1);}
        printf("\n");flag =  0;
        continue;

        another_step:
        for(int i = 0;i < num_0-1;i++){
            printf("%d%d",0,1);
        }

        printf("%d\n",0);flag =  0;
    }

    return 0;
}
