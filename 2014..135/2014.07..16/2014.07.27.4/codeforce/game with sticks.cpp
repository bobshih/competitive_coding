#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    bool mal,aks;

    mal = 1;
    while(n!=0 && m!=0){
        //cout <<"n = "<<n<<" m = "<<m<<endl;
        if(mal){mal = 0;aks = 1;n--;m--;}
        else if(aks){mal = 1;aks = 0;m--;n--;}
    }

    if(mal)printf("Malvika\n");
    else printf("Akshat\n");

    return 0;
}
