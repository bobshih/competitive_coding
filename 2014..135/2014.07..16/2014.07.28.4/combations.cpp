#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
char gg[1000];
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

    if(carry != 0){
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

    if(b > 10){
        temp += (g[len-1]-'0');
        len--;
    }else if(b == 100){
        temp += 10*(g[len-1]-'0');
        temp += 1*(g[len-1]-'0');
        len -= 2;
    }
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

}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    int a,b;

    while(scanf("%d %d",&a,&b)){
        if(a == 0 && b == 0)break;
        memset(gg,'0',sizeof(gg));
        gg[0] = '1';
        len = 1;

        for(int i = 0;i < b;i++){
            multi(gg,a-i);
            divid(gg,i+1);
        }
        printf("%d things taken %d at a time is ",a,b);
        for(int i = len-1;i >= 0;i--){
            printf("%c",gg[i]);
        }printf(" exactly.\n");
    }

    return 0;
}
