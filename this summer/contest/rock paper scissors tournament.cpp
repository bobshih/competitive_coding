#include <iostream>
#include <cstdio>

using namespace std;

int player[101][2];
double win_rate[101];

int main()
{
    int play;
    int games;
    bool first_game = 1;

    while(scanf("%d",&play)){
        if(play == 0)break;
        scanf("%d",&games);

        for(int i = 1;i <= play;i++){
            player[i][0] = 0;
            player[i][1] = 0;
        }

        char m1[20],m2[20];
        int t1,t2;
        for(int i = 0;i < games * play * (play-1)/2;i++){
            scanf("%d %s %d %s",&t1,m1,&t2,m2);
            player[t1][0]++;
            player[t2][0]++;

            if((m1[0] == 'r' && m2[0] == 's')||(m1[0] == 'p' && m2[0] == 'r')||(m1[0] == 's' && m2[0] == 'p')){
                player[t1][1]++;//cout <<t1<<" wins\n";
            }else if(m1[0] != m2[0]){
                player[t2][1]++;//cout <<t2<<" wins\n";
            }else {
                player[t1][0]--;
                player[t2][0]--;
            }
        }
        if(!first_game){printf("\n");}
        for(int i = 1;i <= play;i++){
            if(player[i][0] == 0){printf("-\n");continue;}
            printf("%.3f\n",(float)player[i][1]/player[i][0]);
        }
        if(first_game)first_game = 0;
    }


    return 0;
}
