#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int w[26];

int main()
{
    char temp[1001];
    scanf("%s",temp);
    string s = temp;
    //cout <<s;

    int l;
    scanf("%d",&l);

    int ma = -1;
    for(int i = 0;i < 26;i++){
        scanf("%d",&w[i]);
        if(w[i] > ma){ma = w[i];}
    }

    int sum = 0;
    for(int i = 0;i < s.size()+l;i++){
        if(i < s.size()){
                //cout <<"plus "<<
                sum += w[(s[i]-'a')]*(i+1);}
        else sum += (i+1)*ma;
    }
    printf("%d\n",sum);

    return 0;
}
