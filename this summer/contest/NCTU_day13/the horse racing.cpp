#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int horse[1001];
int king_horse[1001];

int main()
{
    int t;

    while(scanf("%d",&t)){
        if(t == 0)break;

        for(int i = 0;i < t;i++){
            scanf("%d",&horse[i]);
        }sort(horse,horse+t);
        for(int i = 0;i < t;i++){
            scanf("%d",&king_horse[i]);
        }sort(king_horse,king_horse+t);

        //for(int i = 0;i < t;i++){
        //    printf("%d\t%d\n",horse[i],king_horse[i]);
        //}
        int win = 0;
        int lose = 0;
        int even = 0;
        int slow = 0,slow_k = 0;
        int fast = t-1,fast_k = t-1;

        while(true){
            if(slow == t || slow_k == t || fast < slow || fast_k < slow_k)break;

            //cout <<"fast horse = "<<horse[fast]<<" slow horse = "<<horse[slow]<<" king side, fast horse = "<<king_horse[fast_k]<<" slow horse = "<<king_horse[slow]<<endl;
            if(horse[slow] > king_horse[slow_k]){
                win++;slow++;slow_k++;continue;
            }else if(horse[slow] < king_horse[slow_k]){
                lose++;slow++;fast_k--;continue;
            }else if(horse[slow] == king_horse[slow_k]){
                if(horse[fast] < king_horse[fast_k]){
                    lose++;slow++;fast_k--;continue;
                }else if(horse[fast] > king_horse[fast_k]){
                    win++;fast--;fast_k--;continue;
                }else if(horse[fast] == king_horse[fast_k]){
                    if(king_horse[fast_k] == horse[slow]){even++;slow++;slow_k++;continue;}
                    lose++;slow++;fast_k--;continue;
                }
            }
        }
        printf("%d\n",200*(win-lose));

    }

    return 0;
}
