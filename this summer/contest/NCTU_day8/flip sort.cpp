#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    int nums[1010];
    bool flip = 0;
    int turn = 0;
    int temp;

    while(scanf("%d",&n) != EOF){
        for(int i = 0;i < n;i++){
            scanf("%d",&nums[i]);
        }

        do{
            flip = 0;
            for(int i = 0;i < n-1;i++){
                if(nums[i] > nums[i+1]){
                    flip = 1;
                    turn++;
                    temp = nums[i];
                    nums[i] = nums[i+1];
                    nums[i+1] = temp;
                }
            }
        }while(flip == 1);

        printf("Minimum exchange operations : %d\n",turn);
        turn = 0;
    }



    return 0;
}
