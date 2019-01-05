#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

#define stop system("pause");
using namespace std;

1.
題目是有規律的
所求是找給定數字的一半，的最大互質的數

char integer[2005];
char half[2005];
char quater[2005];
int j,i;

void plus_one(){
    bool one = 1;
    for(int i = j-1;i >= 0;i--){
        if(one)half[i]++;
        if(half[i] > '9')half[i] = '0';
        else {one = 0;break;}
    }
    if(one){
        j++;
        for(int i = j-1;i > 0;i--){
            half[i] = half[i-1];
        }half[0] = '1';
    }

    //for(int i = 0;i < j;i++){
    //    printf("%c",half[i]);
    //}cout <<endl;
}

void minus_one(){
    bool carry = 1;
    //cout <<"in minus\n";
    for(int i = j-1;i >= 0;i--){
        //cout <<half[i]<<" - 1"<<endl;
        if(carry)half[i]--;
        if(half[i] < '0'){
            half[i] += 10;
        }else break;
    }

    if(half[0] == '0'){
        for(i = 0;i < j;i++){
            //cout <<half[i]<<"\t"<<half[i+1]<<endl;
            half[i] = half[i+1];
        }j--;
    }

    //for(int i = 0;i < j;i++){
    //    printf("%c",half[i]);
    //}cout <<endl;

}

int main()
{
    int temp_h;
    long long test;
    scanf("%I64d",&test);

    while(test--){
        scanf("%s",integer);
        //ss = integer;
        temp_h = 0;
        memset(half,0,sizeof(half));

        for(j = 0,i = 0;i < strlen(integer);i++){
            temp_h += integer[i]-'0';
            //cout <<temp<<endl;
            half[j] = temp_h/2+'0';
            temp_h = temp_h%2*10;
            //cout <<temp<<" half "<<j<<" = "<<half[j]<<endl;
            j++;
        }temp_h /= 10;

        if(half[0] == '0'){
            for(i = 0;i < j;i++){
                //cout <<half[i]<<"\t"<<half[i+1]<<endl;
                half[i] = half[i+1];
            }j--;
        }
        int q,temp_q = 0;
        for(q = 0,i = 0;i < strlen(integer);i++){
            temp_q += integer[i]-'0';
            quater[j] = temp_q/4 + '0';
            temp_q = temp_q%4*10;
            q++;
        }temp_q /= 10;

        if(quater[0] == '0'){
            for(i = 0;i < q;i++){
                quater[i] = quater[i+1];
            }q--;
        }

        //cout <<"q = "<<temp_q<<" h = "<<temp_h<<endl;
        if(temp_h == 1 && (temp_q == 1 || temp_q == 3)){

        }else if(temp_q == 2){
            minus_one();
            minus_one();
        }else if(temp_q == 0){
            minus_one();
        }

        for(int i = 0;i < j;i++){
            printf("%c",half[i]);
        }cout <<endl;
        if(test)puts("");

    }


    return 0;
}
