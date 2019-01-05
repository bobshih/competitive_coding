#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a1,a2,a3;
    int b1,b2,b3;
    int n;
    int a,b;

    scanf("%d %d %d",&a1,&a2,&a3);a = a1+a2+a3;
    scanf("%d %d %d",&b1,&b2,&b3);b = b1+b2+b3;
    scanf("%d",&n);

    for(int i = 0;i < n;i++){
        if(b > 0){b -= 10;}
        else if(a > 0){a -= 5;}
        else break;
    }

    //cout <<a<<"\t"<<b<<endl;
    if(a <= 0 && b <= 0){printf("YES\n");}
    else {printf("NO\n");}


    return 0;
}
