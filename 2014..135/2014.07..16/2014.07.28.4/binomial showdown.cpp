#include <iostream>
#include <cstdio>
#include <climits>
#include <cstring>

using namespace std;
/*
char gg[100000];
int len;

void multi(char g[],int a){
    int carry = 0;

    for(int i = 0;i < len;i++){
        int temp = g[i]-'0';
        temp *= a;
        temp += carry;
        g[i] = (temp%10)+'0';
        carry = temp/10;
    }

    while(carry != 0){
        //cout <<"carry = "<<carry<<endl;
        g[len] = carry%10+'0';
        len++;
        carry/=10;
    }

    /*if(carry != 0){
        g[len] = carry%10+'0';
        len++;
        carry /= 10;
        if(carry != 0){
            g[len] = carry%10+'0';
            len++;
            carry /= 10;
            if(carry != 0){
                 g[len] = carry%10+'0';
                len++;
                carry /= 10;
            }
        }
    }return;
}
void divid(char g[],int b){
    int carry = 0;
    int temp = 0;

    //if(b > 10){
    //    temp += (g[len-1]-'0');
    //    len--;
    //}else if(b == 100){
    //    temp += 10*(g[len-1]-'0');
    //    temp += 1*(g[len-1]-'0');
    //    len -= 2;
    //}
    //for(int i = len-1;i >= 0;i--){
    //    printf("%c",gg[i]);
    //}cout <<endl;

    for(int i = len-1;i >= 0;i--){
        temp *= 10;
        temp += (g[i]-'0');
        //cout <<"temp = "<<temp;
        if(temp < b){
            //cout <<"small\n";
            g[i] = '0';
            //temp *= 10;
        }else{
            //cout <<"big\n";
            g[i] = '0'+temp/b;
            temp %= b;
        }
    }
    for(int i = len-1;i >= 0;i--){
        if(g[i] == '0'){
            len--;
        }else break;

    }

    //for(int i = len-1;i >= 0;i--){
    //    printf("%c",gg[i]);
    //}cout <<endl;

}*/
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE
    long long a = 1,b = 1;
    long long temp;

    while(scanf("%I64d %I64d",&a,&b)){
        if(a == 0 && b == 0)break;
        if(b > a/2){b = a-b;}
        temp = 1;
        //memset(gg,'0',sizeof(gg));
        //len = 1;
        //gg[0] = '1';

        for(int i = 0;i < b;i++){
            temp *= (a-i);
            temp /= (i+1);
            //multi(gg,a-i);
            //divid(gg,i+1);
        }

        printf("%I64d\n",temp);
        //for(int i = len-1;i >= 0;i--){
        //    printf("%c",gg[i]);
        //}cout <<endl;
    }


    return 0;
}
