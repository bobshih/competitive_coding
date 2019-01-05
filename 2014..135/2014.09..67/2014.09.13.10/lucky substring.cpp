#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char t[50];scanf("%s",t);
    int temp[50];memset(temp,0,sizeof(temp));

    bool flag = 0;
    for(int i = 0;i < strlen(t);i++){
        if(t[i] == '4' || t[i] == '7'){flag = 1;break;}
    }
    if(flag == 0)printf("-1\n");
    else {
        for(int i = 0;i < strlen(t);i++){
            if(t[i] == '4')temp[1]++;
            else if(t[i] == '7')temp[0]++;
        }

        if(temp[1] >= temp[0])printf("4\n");
        else if(temp[1] < temp[0])printf("7\n");
    }
    return 0;
}
