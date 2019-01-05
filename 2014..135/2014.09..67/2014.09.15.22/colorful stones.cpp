#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a,b;
    cin >>a>>b;

    int i,j;
    for(i = 0,j = 0;j < b.size();j++){
        if(a[i] == b[j]){
            i++;
        }
    }
    cout <<i+1<<endl;

    return 0;
}
