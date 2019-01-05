#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int n,temp;
    cin >>n;
    bool index[3005];
    memset(index,0,sizeof(index));
    for(int i = 0;i < n;i++){
        cin >>temp;
        index[temp]++;
    }

    for(int i = 1;i < 3004;i++){
        if(index[i] == 0){cout <<i<<endl;break;}
    }

    return 0;
}
