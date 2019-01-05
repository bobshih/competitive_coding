#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

//int prime[1229];
bool prime[10001];
int prime_d[10001];
bool used[10001];

bool ispri(int a){
    for(int i = 2;i <= sqrt(a);i++){
        if(a%i == 0){return 0;}
    }
    return 1;
}

void BFS(int start,int ended){
    if(start == ended){
            //cout <<"start = "<<start<<" ended = "<<ended<<"level = "<<prime_d[ended]<<endl;
            //system("pause");
            return ;}
    //cout <<"start = "<<start<<" ended = "<<ended<<endl;

    int a[5];
    a[4] = 0;
    int temp;
    queue<int> aqueue;
    aqueue.push(start);

    while(!aqueue.empty()){
        temp = aqueue.front();
        for(int j = 3;j >= 0 ;j--){
            int p = pow(10.0,j);
            int t = temp/p;
            a[j] = t;
            temp = temp-a[j]*p;
            //cout <<a[j]<<endl;
            for(int i = 0;i < 10;i++){
                //cout <<"i = "<<i<<endl;
                if(j == 3 && i == 0)continue;
                int change = aqueue.front()-a[j]*pow(10.0,j)+i*pow(10.0,j);
                if(!used[change] && prime[change]){
                    used[change] = true;prime_d[change] = prime_d[aqueue.front()] + 1;
                    //cout <<"start = "<<aqueue.front()<<" change = "<<change<<"level = "<<prime_d[change]<<endl;
                    //system("pause");
                    aqueue.push(change);
                }
            }
        //system("pause");
        }
        aqueue.pop();
    }
    /*for(int i = 0;i < 10;i++){
        system("pause");

        for(int j = 0;j < 4;j++){
            system("pause");
            int t = pow(10.0,j+1);
            int p = pow(10.0,j);
            cout <<"t = "<<t<<endl;
            int temp = start/t*t;
            temp = start - temp;
            temp = start - temp + i*p;
            cout <<"start = "<<start<<" temp = "<<temp<<endl;
            if(!used[temp] && prime[temp]){
                used[temp] = 1;prime_d[temp] = prime_d[start] + 1;
                BFS(temp,ended);
            }
        }

    }*/
}

int main()
{
    int test;
    scanf("%d",&test);

    memset(prime,0,10001);
    for(int i = 2;i < 10000;i++){
        if(ispri(i)){
            //cout <<"a = "<<a<<" i = "<<i<<endl;
            //system("pause");
            prime[i] = 1;

        //if(a == 1229)break;
        }
    }

    for(int i = 0;i < 10001;i++){
        //if(prime[i])cout <<i<<endl;
        //system("pause");}
    }//cout <<"a = "<<a<<endl;

    int temp1,temp2;
    int cost;
    for(int a = 0;a < test;a++){
        scanf("%d %d",&temp1,&temp2);

        memset(prime_d,-1,10001);
        memset(used,0,10001);
        prime_d[temp1] = 0;
        used[temp1] = 1;

        BFS(temp1,temp2);
        if(used[temp2] == 0){
            printf("Impossible\n");
        }else {printf("%d\n",prime_d[temp2]);}
    }




    return 0;
}
