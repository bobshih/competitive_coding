#include <iostream>
#include <cstdio>

using namespace std;

int mod(int a,int b){
    int temp = a/b*b;
    if(a-temp == 0)return a/b;
    return a/b+1;
}

int main()
{
    int a1,a2,a3,a4,a5,a6;

    while(scanf("%d %d %d %d %d %d",&a1,&a2,&a3,&a4,&a5,&a6) == 6){
        if(a1+a2+a3+a4+a5+a6 == 0)break;

        int number_packet = a6+a5+a4;
        int temp = a3%4;
        if(temp == 0){number_packet += a3/4;}
        else number_packet += (a3/4+1);
        //cout <<"initalize the packet number is "<<number_packet<<endl;

        int  L2 = a4*5;
        if(temp == 1){L2 += 5;}
        else if(temp == 2){L2 += 3;}
        else if(temp == 3){L2 += 1;}
        //cout <<"L2 = "<<L2<<endl;
        if(a2 > L2){
            //cout <<"a2 = "<<a2<<"\n";
            number_packet += mod(a2-L2,9);
        }

        int L1 = number_packet*36 - a6*36 - a5*25 - a4*16 - a3*9 - a2*4;
        //cout <<"L1 = "<<L1<<endl;
        if(a1 > L1){
                //cout <<"??\n";
            number_packet += mod(a1-L1,36);
        }
        printf("%d\n",number_packet);
    }


    return 0;
}
