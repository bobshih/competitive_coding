#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

long long len;
long long a[1000000];

struct bign{
    int lenth;
    int num[100];

    bign(){
        lenth = 0;
        memset(num,0,sizeof(num));
    }
    bign(long long a){
        long long temp = a;
        lenth = 0;
        while(temp != 0){
            num[lenth] = temp%10;
            temp /= 10;
            lenth++;
        }
    }

    bign operator * (const bign& b) {
        bign ans;
        ans.lenth = 0;

        for (int i = 0; i < lenth; i++){
            int bignSum = 0;

            for (int j = 0; j < b.lenth; j++){
                bignSum += num[i] * b.num[j] + ans.num[i+j];
                ans.num[i+j] = bignSum % 10;
                bignSum /= 10;
            }
            ans.lenth = i + b.lenth;

            while (bignSum){
                ans.num[ans.lenth++] = bignSum % 10;
                bignSum /= 10;
            }
        }
        return ans;
    }
};

int main()
{
    scanf("%I64d",&len);
    for(int i = 0;i < len;i++)scanf("%I64d",&a[i]);
    sort(a,a+len);

    long long temp = a[len-1]-a[0];
    printf("%I64d ",temp);
    if(temp == 0){
        if(len%2){
            bign c1(len),c2((len-1)/2);bign c3 = c1*c2;
            for(int i = c3.lenth-1;i >= 0;i--){
                printf("%d",c3.num[i]);
            }cout <<endl;
        }else{
            bign c1(len/2),c2(len-1);bign c3 = c1*c2;
            for(int i = c3.lenth-1;i >= 0;i--){
                printf("%d",c3.num[i]);
            }cout <<endl;
        }
    }
    else {
        int i,t1,t2;
        for(i = 0;i < len;i++){
            if(a[i] != a[0]){t1 = i;break;}
        }
        for(;i<len;i++){
            if(a[i] == a[len-1]){
                t2 = len-i;break;
            }
        }
        bign c1(t1),c2(t2);
        bign c3 = c1*c2;

        for(int i = c3.lenth-1;i >= 0;i--){
            printf("%d",c3.num[i]);
        }cout <<endl;

    }
    return 0;
}
