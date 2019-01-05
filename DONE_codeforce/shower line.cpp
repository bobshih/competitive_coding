#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int a[5][5];

int main()
{
    //again:
    for(int i = 0;i < 5;i++){
        for(int j = 0;j < 5;j++){
            scanf("%d",&a[i][j]);
        }
    }

    int i[5] = {0,1,2,3,4};

    int maximum,temp;
    maximum = 0;
    do {
        //system("pause");
        temp = a[i[0]][i[1]] + a[i[1]][i[0]] + 2*a[i[2]][i[3]] + 2*a[i[3]][i[2]] + a[i[1]][i[2]] + a[i[2]][i[1]] + 2*a[i[3]][i[4]] + 2*a[i[4]][i[3]];
        if(temp > maximum)maximum = temp;
        //printf("%d",temp);
    }while(next_permutation(i,i+5));

    printf("%d\n",maximum);
    //goto again;

    return 0;
}
