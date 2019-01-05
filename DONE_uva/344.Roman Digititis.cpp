#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/*i是 1
v是 5
x是 10
l是 50
c是 100*/

void sum_t(int a[],int b[],int n){
    if(n == 0){return ;}
    b[0] += a[0];
    b[1] += a[1];
    b[2] += a[2];
    b[3] += a[3];
    b[4] += a[4];
}
void make_table(int a[],int n){
    int one = n%10;
    int ten = n/10;

    switch(one){
        case 1:a[0] = 1;;break;
        case 2:a[0] = 2;break;
        case 3:a[0] = 3;break;
        case 4:a[0] = 1;a[1] = 1;break;
        case 5:a[1] = 1;break;
        case 6:a[0] = 1;a[1] = 1;break;
        case 7:a[0] = 2;a[1] = 1;break;
        case 8:a[0] = 3;a[1] = 1;break;
        case 9:a[0] = 1;a[2] = 1;break;
        case 0:break;
    }
    switch(ten){
        case 0: break;
        case 1: a[2]++;break;
        case 2: a[2]+=2;break;
        case 3: a[2]+=3;break;
        case 4: a[2]++;a[3]++;break;
        case 5: a[3]++;break;
        case 6: a[2]++;a[3]++;break;
        case 7: a[2]+=2;a[3]++;break;
        case 8: a[2]+=3;a[3]++;break;
        case 9: a[2]++;a[4]++;break;
        case 10:a[4]++;break;
    }
}

int main(){
    int num[100][5];
    int a;

    for(int i = 0;i < 100;i++){num[i][0] = 0;num[i][1] = 0;num[i][2] = 0;num[i][3] = 0;num[i][4] = 0;
        make_table(num[i],i+1);sum_t(num[i-1],num[i],i);}

    while(scanf("%d",&a) == 1){
        if(a == 0){break;}
        a--;
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",a+1,num[a][0],num[a][1],num[a][2],num[a][3],num[a][4]);
    }

    return 0;
}
