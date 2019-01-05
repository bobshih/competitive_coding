#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main(){
    int a;
    scanf("%d",&a);

    int cases;
    int *c1;
    int *c2;
    int answer[500];
    for(int i = 0;i < 500;i++){
        answer[i] = 0;
    }
    int sum = 0;
    while(a != 0){
        scanf("%d",&cases);

        c1 = (int*)malloc(sizeof(int)*cases);
        c2 = (int*)malloc(sizeof(int)*cases);
        for(int i = 0;i < cases;i++){
            scanf("%d %d",&c1[i],&c2[i]);
            if(answer[c1[i]] < c2[i]){answer[c1[i]] = c2[i];}
            if(answer[c2[i]] < c1[i]){answer[c2[i]] = c1[i];}
        }
        for(int i = 0;i < 500;i++){
            sum += answer[i];
        }
        printf("%d\n",sum);
        /*for(int i = 0;i < cases;i++){
            printf("%d %d\n",c1[i],c2[i]);
        }*/a--;
        free(c1);
        free(c2);
        sum = 0;
        for(int i = 0;i < 500;i++){
            answer[i] = 0;
        }
    }

    return 0;
}
