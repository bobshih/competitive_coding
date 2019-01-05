#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    double temp;
    double sum = 0;

    while (scanf("%lf",&temp) != EOF){
        sum = temp;
        for(int i = 1;i < 12;i++){
            scanf("%lf",&temp);
            sum += temp;
        }
        double average = sum/12.0;
        printf("$%.2f\n",average);
    }

    return 0;
}
