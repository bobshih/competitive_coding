#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#include "auto_check.h"

char temp[50];
int check;
int sum_str;
int sum_law;

int main()
{
    scanf("%s", temp);
    scanf(" %d", &check);
    sum_str = sum_law = 0;

    sum_str = temp[0] - '0';
    for(int i = 1;i < strlen(temp);){
        char opp = temp[i++];
        int t = temp[i++]-'0';
        if(opp == '+'){
            sum_str += t;
        }else {
            sum_str *= t;
        }
    }
    //printf("%d\n", sum_str);

    int a = 1;
    int t = temp[0]-'0';
    //sum_law = temp[0]-'0';
    while(a < strlen(temp)){
        //cout <<"sum = "<<sum_law<<" t = "<<t<<" a = "<<a<<endl;
        if(temp[a++] == '+'){
            sum_law += t;
            t = temp[a++]-'0';
        }else{
            t *= (temp[a++]-'0');
        }
    }
    sum_law += t;
    //printf("%d\n", sum_law);
    if(sum_str == check && sum_law == check){
        printf("US\n");
    }else if(sum_str == check){
        printf("L\n");
    }else if(sum_law == check){
        printf("M\n");
    }else printf("I\n");

    return 0;
}
