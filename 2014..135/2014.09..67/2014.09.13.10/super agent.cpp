#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char temp[3][3];
    bool flag = 0;
    for(int i = 0;i < 3;i++){
        scanf("%s",temp[i]);

        if(i == 1){
            if(temp[i][0] != temp[i][2])flag = 1;
        }
    }

    if(temp[0][0] != temp[2][2])flag = 1;
    if(temp[0][1] != temp[2][1])flag = 1;
    if(temp[0][2] != temp[2][0])flag = 1;

    if(flag)printf("NO\n");
    else printf("YES\n");

    return 0;
}
