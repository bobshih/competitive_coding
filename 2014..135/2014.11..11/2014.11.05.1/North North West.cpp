#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

char dir[105];
int degree;
int two;

int main()
{
    while(scanf("%s", dir)){
        int len = strlen(dir);
        if(dir[len-1] == '#')break;
        else if(dir[len-1] == 'h'){
            degree = 0;two = 1;
            len -= 5;
        }else {
            degree = 90;two = 1;
            len -= 4;
        }

        for(;len != 0;){
            two++;
            if(dir[len-1] == 'h'){
                len -= 5;
                degree = degree*2 - 90;
            }else {
                len -= 4;
                degree = degree*2 + 90;
            }
        }

        if(two == 1){
            printf("%d\n", degree);
        }else if(two == 2){
            printf("%d\n", degree/2);
        }else {
            printf("%d/%d\n", degree/2, (int)pow(2.0, (double)two-2));
        }
    }

    return 0;
}
