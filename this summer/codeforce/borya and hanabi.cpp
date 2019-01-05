#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

bool check(int cards[5][5]){
    int temp[25];
    //for(int i = 0;i < 25;i++)temp[i] = 0;

    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
         //if(cards[i][j] >= 4096){
            temp[(5*i+j)] = cards[i][j];
            //printf("%d\n",cards[i][j]);
         //}
        }
    }

    for(int i = 0;i < 25;i++){
        if(temp[i] != 0){
            for(int j = i+1;j < 25;j++){
                if(temp[j] == temp[i]){return false;}
            }
        }
    }
    return true;
}

int main()
{
    int cards[5][5];
    int question = 0;
    int ca;
    char temp[2];

    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            cards[i][j] = 0;
        }
    }

    scanf("%d",&ca);
    getchar();

    for(int i = 0;i < ca;i++){
        temp[0] = getchar();
        temp[1] = getchar();
        //printf("%c\t%c\n",temp[0],temp[1]);
        switch(temp[0]){
            case 'R':
                if(temp[1] == '1'){cards[0][0] = 4096;}
                if(temp[1] == '2'){cards[0][1] = 4096;}
                if(temp[1] == '3'){cards[0][2] = 4096;}
                if(temp[1] == '4'){cards[0][3] = 4096;}
                if(temp[1] == '5'){cards[0][4] = 4096;}
                break;
            case 'Y':
                if(temp[1] == '1'){cards[1][0] = 4096;}
                if(temp[1] == '2'){cards[1][1] = 4096;}
                if(temp[1] == '3'){cards[1][2] = 4096;}
                if(temp[1] == '4'){cards[1][3] = 4096;}
                if(temp[1] == '5'){cards[1][4] = 4096;}
                break;
            case 'W':
                if(temp[1] == '1'){cards[2][0] = 4096;}
                if(temp[1] == '2'){cards[2][1] = 4096;}
                if(temp[1] == '3'){cards[2][2] = 4096;}
                if(temp[1] == '4'){cards[2][3] = 4096;}
                if(temp[1] == '5'){cards[2][4] = 4096;}
                break;
            case 'B':
                if(temp[1] == '1'){cards[3][0] = 4096;}
                if(temp[1] == '2'){cards[3][1] = 4096;}
                if(temp[1] == '3'){cards[3][2] = 4096;}
                if(temp[1] == '4'){cards[3][3] = 4096;}
                if(temp[1] == '5'){cards[3][4] = 4096;}
                break;
            case 'G':
                if(temp[1] == '1'){cards[4][0] = 4096;}
                if(temp[1] == '2'){cards[4][1] = 4096;}
                if(temp[1] == '3'){cards[4][2] = 4096;}
                if(temp[1] == '4'){cards[4][3] = 4096;}
                if(temp[1] == '5'){cards[4][4] = 4096;}
                break;
        }
        temp[0] = getchar();
    }

    int color = 0;
    int answer = 100;

    //for(int i = 0;i < 5;i++){
    //    for(int j = 0;j < 5;j++){
    //        printf("cards[%d][%d] = %d\n",i,j,cards[i][j]);
    //    }
    //}


    for(;question < 1024;question++){
        for(int i = 0;i < 10;i++){
            if((question & (1<<i)) > 0){
                color++;//printf("i = %d\n",i);
                for(int j = 0;j < 5;j++){
                    if(i < 5 && cards[i][j] >= 4096){
                        cards[i][j] ^= (1<<i);
                    }
                    if(i >= 5 && cards[j][i-5] >= 4096){
                        cards[j][i-5] ^= (1<<i);
                    }
                }
            }
        }
        //printf("color = %d  answer = %d  question = %d\n",color,answer,question);
        if(check(cards)){
                if(color < answer){answer = color;}
                }
        color = 0;
        for(int i = 0;i < 5;i++){
            for(int j = 0;j < 5;j++){
                if(cards[i][j] >= 4096){cards[i][j] = 4096;}
            }
        }
        //system("pause");
    }

    printf("%d\n",answer);

    return 0;
}
