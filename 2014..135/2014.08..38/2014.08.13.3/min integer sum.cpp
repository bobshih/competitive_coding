#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int mid;
int temp[35];
int temp1[20],len1;
int temp2[20],len2;
int zero;

int main()
{
    while(scanf("%d",&n) != EOF){
        len1 = len2 = zero = 0;
        for(int i = 0;i < n;i++){
            scanf("%d",&temp[i]);
            if(temp[i] == 0)zero++;
        }sort(temp,temp+n);

        if(zero == 0){
            for(int i = 0;i < n;i++){
                if(i%2 == 0){
                    temp1[len1] = temp[i];len1++;
                }else {
                    temp2[len2] = temp[i];len2++;
                }
            }
        }else {
            temp1[len1] = temp[zero];len1++;
            temp2[len2] = temp[zero+1];len2++;
            for(int i = 0;i < n;i++){
                if(i == zero || i == zero+1)continue;
                if(i%2 == 0){
                    temp1[len1] = temp[i];len1++;
                }else {
                    temp2[len2] = temp[i];len2++;
                }
            }
        }

        //cout <<"temp1 = ";
        //for(int i = 0;i < len1;i++){
        //    cout <<temp1[i];
        //}cout <<endl;

        //cout <<"temp2 = ";
        //for(int i = 0;i < len2;i++){
        //    cout <<temp2[i];
        //}cout <<endl;

        int carry = 0;
        for(int i = len1-1,a = len2-1;i >= 0,a >= 0;i--,a--){
            temp1[i] += (temp2[a]+carry);
            if(temp1[i] >= 10){
                temp1[i] %= 10;
                carry = 1;
            }else carry = 0;
        }

        if(carry){
            printf("1");
        }for(int i = 0;i < len1;i++){
            printf("%d",temp1[i]);
        }cout <<endl;

    }

    return 0;
}
