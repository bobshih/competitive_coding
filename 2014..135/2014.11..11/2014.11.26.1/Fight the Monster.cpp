#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;

int incr_HP, incr_AK, incr_DF;
int HPM, HPY;
int AKM, AKY;
int DFM, DFY;

int main()
{
    scanf("%d %d %d %d %d %d %d %d %d", &HPY, &AKY, &DFY, &HPM, &AKM, &DFM, &incr_HP, &incr_AK, &incr_DF);
    int ans = INT_MAX;
    int start_AK = (DFM-AKY >= 0)?(DFM-AKY):0;
    int end_AK = (start_AK)?(start_AK+120):202;
    //cout <<"start_AK = "<<start_AK<<" end_AK = "<<end_AK<<endl;
    for(int i = 0;i <1200;i++){
        for(int j = start_AK;j < end_AK;j++){
            for(int k = 0;k < 105;k++){
                int hpy = HPY + i;
                int aky = AKY + j;
                int dfy = DFY + k;
                int minus_y = max(0, aky-DFM);
                int minus_m = max(0, AKM-dfy);
                int die_y = (minus_m)?((hpy%minus_m)?(hpy/minus_m+1):(hpy/minus_m)):INT_MAX;
                int die_m = (minus_y)?((HPM%minus_y)?(HPM/minus_y+1):(HPM/minus_y)):INT_MAX;
                //cout <<"die_y = "<<die_y<<" die_m = "<<die_m<<endl;
                if(die_y > die_m){
                    ans = min(ans, i*incr_HP + j*incr_AK + k*incr_DF);
                    //printf("ans = %d\n", ans);
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
