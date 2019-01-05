#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,m;
    cin >>n>>m;

    if(n == 0 || m == 0){
        if(n == 0){
            cout <<"0 1\n"
                 <<"0 "<<m<<endl
                 <<"0 0\n"
                 <<"0 "<<m-1<<endl;
        }else {
            cout <<"1 0\n"
                 <<n<<" 0\n"
                 <<"0 0\n"
                 <<n-1<<" 0\n";
        }
    }else if(n == 0 || m == 0){
        if(n == 0){
            cout <<"0 1\n"
                 <<"0 "<<m<<endl
                 <<"0 0\n"
                 <<"0 "<<m-1<<endl;
        }else {
            cout <<"1 0\n"
                 <<n<<" 0\n"
                 <<"0 0\n"
                 <<n-1<<" 0\n";
        }
    }else {
        double s1 = n + 2*sqrt(n*n+m*m);
        double s2 = m + 2*sqrt(n*n+m*m);
        double s3 = sqrt(n*n+m*m) + 2*sqrt((n-1)*(n-1)+m*m);
        double s4 = sqrt(n*n+m*m) + 2*sqrt(n*n+(m-1)*(m-1));

        if(s1 > s2 && s1 > s3 && s1 > s4){
            //cout <<"s1\n";
            cout <<"0 0\n"
                 <<n<<' '<<m<<endl
                 <<"0 "<<m<<endl
                 <<n<<" 0\n";
        }else if(s2 >= s1 && s2 > s3 && s2 >s4){
            //cout <<"s2\n";
            cout <<"0 0\n"
                 <<n<<' '<<m<<endl
                 <<n<<" 0\n"
                 <<"0 "<<m<<endl;
        }else {
            //cout <<"other\n";
            if((n-1)*(n-1)+m*m > (m-1)*(m-1)+n*n){
                cout <<n-1<<' '<<m<<endl
                     <<"0 0\n"
                     <<n<<' '<<m<<endl
                     <<"1 0\n";
            }else {
                cout <<n<<' '<<m-1<<endl
                     <<"0 0\n"
                     <<n<<' '<<m<<endl
                     <<"0 1\n";
            }

        }
    }

    return 0;
}
