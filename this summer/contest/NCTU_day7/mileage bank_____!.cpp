#include <iostream>
#include <cstdio>
#include <cstring>

技巧，把資料以字串的形式輸入，接著判斷是否為中止字元(利用strcmp())，再繼續程式的進行

using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE


    char temp;
    char t1[1000],t2[1000];
    int sum;
    int t;

    scanf("%s",t1);
    while(strcmp(t1,"#") != 0){
        sum = 0;

        while(strcmp(t1,"0") != 0){
            scanf("%s %d %c",t2,&t,&temp);

            if(temp == 'F'){
                sum += t*2;
            }else if(temp == 'B'){
                sum += t + t/2 + t%2;
            }else if(t < 500){
                sum += 500;
            }else {
                sum += t;
            }
            scanf("%s",t1);
        }
        printf("%d\n",sum);
        scanf("%s",t1);
    }



    return 0;
}
