#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int a[2][4];
string s;

int main()
{
    again:
    for(int i = 0;i < 2;i++){
        for(int j = 0;j < 4;j++){
            a[i][j] = 0;
        }
    }

    //char t;
    scanf("%d %d %d %d",&a[0][0],&a[0][1],&a[0][2],&a[0][3]);
    //getchar();

    cin >>s;
    //getline(cin,s);
    /*int i = 0;
    cout <<s<<endl;
    system("pause");*/

    for(int i = 0;i < s.length();i++){
        a[1][s[i]-49]++;
    }
    /*while(true){
        if(s[i] == '\0')break;
        a[1][s[i]-48]++;
        i++;
    }*/
    long long temp = a[0][0]*a[1][0]+a[0][1]*a[1][1]+a[0][2]*a[1][2]+a[0][3]*a[1][3];
    printf("%I64d\n",temp);

    //goto again;
    return 0;
}
