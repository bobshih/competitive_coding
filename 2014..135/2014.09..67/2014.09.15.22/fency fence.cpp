#include <iostream>

using namespace std;

int main()
{
    int n;cin >>n;
    /*int poly = 3;
    int ang[1000];
    do{
        if(((poly-2)*180)%poly != 0){
            ang[poly] = 0;
            cout <<"poly = "<<poly<<" "<<ang[poly]<<endl;
            poly++;
            continue;
        }
        ang[poly] = (poly-2)*180/poly;
        cout <<ang[poly]<<endl;
        poly++;
    }while(poly < 1000);*/

    for(int i = 0;i < n;i++){
        int angle;cin >>angle;
        if(360%(180-angle) == 0)cout <<"YES\n";
        else cout <<"NO\n";
    }

    return 0;
}
