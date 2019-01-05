#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char temp[100005];

struct bign{
    int tt[100005];
    int len;

    bign(char t[]){
        len = 0;
        int i = 0;
        while(t[i] != '\0'){
            tt[len] = t[i]-48;
            //cout <<"tt["<<len<<"] = "<<tt[len]<<endl;
            i++;
            len++;
        }
    }

    int operator %(const int a){
        int carry = 0,temp;
        for(int i = 0;i < len;i++){
            temp = (tt[i] + carry)%a;
            carry  = temp*10;
        }
        return temp;
    }
};

int main()
{
    scanf("%s",temp);

    bign Integ(temp);

    int mod2[4] = {1,2,4,3};
    int mod3[4] = {1,3,4,2};
    int mod4[2] = {1,4};
    int t1  = 1 + mod2[Integ%4] + mod3[Integ%4] + mod4[Integ%2];

    printf("%d\n",t1%5);
    return 0;
}
