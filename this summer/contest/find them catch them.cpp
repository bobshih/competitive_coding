#include <iostream>
#include <cstdio>

using namespace std;

int p[100010];   //父節點
int r[100010];   //與根節點的關係

int get(int a){
    if(p[a] == a){return a;}

    int temp = p[a];         //紀錄父節點，方便更新 r[]
    p[a] = get(temp);
    r[a] = (r[a] + r[temp])%2;
    return p[a];
}

void connect(int a,int b){
    int dad_a = get(a);
    int dad_b = get(b);

    p[dad_a] = dad_b;
    r[dad_a] = (r[a] + 1 + r[b])%2;
}

int main()
{
    int test;
    scanf("%d",&test);
    int people,q;

    for(int ca = 0; ca < test;ca++){
        scanf("%d %d",&people,&q);
        for(int i = 0;i <= people;i++){
            p[i] = i;
            r[i] = 0;
        }

        int temp1,temp2;
        char t;
        for(int i = 0;i < q;i++){
            getchar();
            scanf("%c %d %d",&t,&temp1,&temp2);

            if(t == 'A'){
                //cout <<get(temp1)<<"\t"<<get(temp2)<<endl;
                if(get(temp1) != get(temp2)){
                    printf("Not sure yet.\n");
                }else {
                    if(r[temp1] == r[temp2]){
                        printf("In the same gang.\n");
                    }else {
                        printf("In different gangs.\n");
                    }
                }
            }
            else if(t == 'D'){
                connect(temp1,temp2);
            }

        }
    }


    return 0;
}
