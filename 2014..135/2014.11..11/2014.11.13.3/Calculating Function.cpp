#include <iostream>
#include <cstdio>
using namespace std;

long long input;

int main()
{
    scanf("%I64d", &input);
    //printf("%I64d\n", input/2);
    //cout <<<<endl;
    printf("%I64d\n", (long long)(input/2 + ((input%2)?((-1)*input):0)));
    return 0;
}
