#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#define stop system("pause");
using namespace std;

char str[1000100];
int x[1000100];
int y[1000100];
int cot;

int main()
{
    int a;
    scanf("%d",&a);

    while(a--){
        scanf("%s",str);
        //cout <<str<<endl;

        int cot = 0;

        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        for(int i = 0;str[i] != '5';i++){
            //cout <<str[i]<<endl;
            cot++;
            switch(str[i]){
                case '1':            //Southwest
                    x[i+1] = x[i]-1;
                    y[i+1] = y[i]-1;
                    break;
                case '2':            //South
                    x[i+1] = x[i];
                    y[i+1] = y[i]-1;
                    break;
                case '3':            //Southeast
                    x[i+1] = x[i]+1;
                    y[i+1] = y[i]-1;
                    break;
                case '4':            //West
                    x[i+1] = x[i]-1;
                    y[i+1] = y[i];
                    break;
                case '5':
                    break;
                case '6':            //East
                    x[i+1] = x[i]+1;
                    y[i+1] = y[i];
                    break;
                case '7':            //Northwest
                    x[i+1] = x[i]-1;
                    y[i+1] = y[i]+1;
                    break;
                case '8':            //North
                    x[i+1] = x[i];
                    y[i+1] = y[i]+1;
                    break;
                case '9':            //Northeast
                    x[i+1] = x[i]+1;
                    y[i+1] = y[i]+1;
                    break;
            }
        }
        long long s = 0;
        //stop;
        for(int i = 1;i < cot;i++){
            //cout <<x[i-1]<<" "<<y[i-1]<<"\t"<<x[i]<<" "<<y[i]<<"\t"<<x[i+1]<<" "<<y[i+1]<<endl;
            s += x[i]*y[i+1]-x[i+1]*y[i];
            //cout <<s<<endl;
        }
        long long tt = (long long)fabs(s);
        //cout <<"tt = "<<tt<<endl;
        if(s%2 == 0){
            printf("%I64d\n",tt/2);
        }else {
            printf("%I64d.5\n",tt/2);
        }

    }


    return 0;
}
