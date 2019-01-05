#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main()
{
    int test;
    scanf("%d",&test);

    int h1,h2,m1,m2;
    for(int i = 0;i < test;i++){
        scanf("%d:%d %d:%d",&h1,&m1,&h2,&m2);

        int t = 0;
        if(m1 != m2){
            t += min(abs(m1-m2),abs(60-abs(m1-m2)));
        }
        if(h1 != h2){
            t += min(abs(h1-h2),abs(12-abs(h1-h2)));
        }
        cout <<t<<endl;
    }

    return 0;
}
