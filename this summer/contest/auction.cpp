#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

struct  lis{
    int price;
    char name[500];
};

int main()
{
    int n;
    scanf("%d",&n);
    //scanf(" ");

    int limit,people;

    for(int a = 1;a <= n;a++){
        scanf("%d %d",&limit,&people);

        int *w = new int[limit];
        lis *p = new lis[people];
        for(int i = 0;i < limit;i++){
            w[i] = 0;
        }
        int temp;
        for(int i = 0;i < people;i++){
            scanf("%s %d",p[i].name,&p[i].price);
            temp = p[i].price;
            w[temp-1] += 1;
        }

        int answer,m = people+1;
        for(int i = 0;i < limit;i++){
            //cout <<"w["<<i<<"] is "<<w[i]<<"\t min is "<<m<<endl;
            if(w[i] == 1){answer = i+1;break;}
            if(w[i] < m && w[i] != 0){answer = i+1;m = w[i];}
        }

        //cout <<"answer is "<<answer<<endl;
        printf("Case %d:\n",a);
        for(int i = 0;i < people;i++){
            if(p[i].price == answer){
                printf("The winner is %s.\n",p[i].name);
                printf("The price is %d.",p[i].price);
                break;
            }
        }

        if(a == n){break;}
        else {printf("\n\n");}
        //delete [] w;
        //delete [] p;
    }

    return 0;
}
