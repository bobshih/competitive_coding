#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <cstdlib>
#include <cstring>
using namespace std;

string a,b;
long double temp1[100105];
long long n1,n2;

int main()
{
    cin >>a>>b;

    int temp;
    n1 = a.size();
    n2 = b.size();
    memset(temp1,0,sizeof(temp1));
    for(int i = 0;i < a.size();i++){
        temp1[a.size()-i-1] = a[i]-'0';
    }
    for(int i = 0;i < b.size();i++){
        temp = b[i]-'0';
        temp1[b.size()-i-1] -= temp;
    }

    int n = max(n1,n2);

    //for(int i = 0;i < n;i++){
    //    cout <<temp1[i]<<endl;
    //}
    for(int i = n;i >= 2;i--){
         if (temp1[i]!=0) {
            temp1[i-1]+=temp1[i];
            temp1[i-2]+=temp1[i];
            temp1[i]=0;
        }
        /*double temptemp = temp1[i];
        if(temp == 0)continue;
        temp1[i-1] += temp;
        temp1[i-2] += temp;
        temp1[i] = 0;*/
        //cout <<"temp = "<<temp<<"\t"<<temp1[i-1]<<"\t"<<temp1[i-2]<<endl;
    }

    //cout <<temp1[0]<<"\t"<<temp1[1]<<endl;
    if (fabs(temp1[0])<1e-5 && fabs(temp1[1])<1e-5) puts("="); else
    puts((temp1[1]*(sqrt(5)+1)>-2*temp1[0])?">":"<");

    /*long double t1 = 1.618033988*temp1[1] + temp1[0];
    if(fabs(t1) <= 1.e-7)puts("=");
    else if(t1 > 0)puts(">");
    else puts("<");*/

    return 0;
}
