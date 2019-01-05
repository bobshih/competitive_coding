#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char temp[103];
    scanf("%s",temp);

    int t = 0;
    for(int i = 0;i < strlen(temp);i++){
        if(temp[i] >= 'A' && temp[i] <= 'Z')t++;
    }
    if(t == strlen(temp)){
        for(int i = 0;i < strlen(temp);i++){
            printf("%c",temp[i]+32);
        }cout <<endl;
    }else if(t == strlen(temp)-1 && islower(temp[0])){
        printf("%c",temp[0]-32);
        for(int i = 1;i < strlen(temp);i++){
            printf("%c",temp[i]+32);
        }cout <<endl;
    }else {
        for(int i = 0;i < strlen(temp);i++){
            printf("%c",temp[i]);
        }cout <<endl;
    }

    return 0;
}
