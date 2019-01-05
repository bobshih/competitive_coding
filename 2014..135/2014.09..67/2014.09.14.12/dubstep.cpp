#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    string a;
    char temp[205];
    bool flag = 0;
    cin >>a;
    for(int i = 0;i < a.size();){
        if(a[i] == 'W' && a[i+1] == 'U' && a[i+2] == 'B'){i+=3;continue;}
        else {
            int j;
            for(j = i;!(a[j] == 'W' && a[j+1] == 'U' && a[j+2] == 'B');j++){
                temp[j-i] = a[j];
                if(j >= a.size())break;
            }
            if(flag == 0){flag = 1;
                for(int k = i;k < j;k++){
                    printf("%c",a[k]);
                }
            }else {printf(" ");
                for(int k = i;k < j;k++){
                    printf("%c",a[k]);
                }
            }
            i = j;
        }if(i >= a.size())break;
    }cout <<endl;

    return 0;
}
