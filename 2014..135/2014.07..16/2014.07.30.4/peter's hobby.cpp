#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

1.
�ಾ��{���G
��i - 1 �Ѫ��Ѯ�Oj1�A�� i �Ѫ��Ѯ�Oj2�A�Ѯ��ಾ�����v�Otable_w[j1][j2]
�� i �Ѫ���׬Ox2�A�h�bj2�Ѯ�U�A��׬�x2�����v�Otable_relate[j2][x2];
�ҥHdp[i][j2] = max(dp[i-1][j1]*table_w[j1][j2]*table_relate[j2][x])     ��j1�O�ܼ�
2.
�Ĥ@�Ѥ�����ಾ��{���ӨD�Ѯ�A�]���Ĥ@�Ѫ��Ѯ�O�����L�ѼƼv�T���A�O��ª����v

double dp[55][3];
double record[55][3];
int ans[55];
int day;

const double table_w[3][3] = {
                        {0.5, 0.375, 0.125},
                        {0.25, 0.125, 0.625},
                        {0.25, 0.375, 0.375}
                        };
const double table_relate[3][4] = {
                        {0.6, 0.2, 0.15, 0.05},
                        {0.25, 0.3, 0.2, 0.25},
                        {0.05, 0.1, 0.35, 0.5}
                        };

double max(int i,int j,double a,double b,double c){
    if(a >= b && a >= c){record[i][j] = 0;return a;}
    if(b >= a && b >= c){record[i][j] = 1;return b;}
    record[i][j] = 2;return c;
}

int get(){
    char h[100];
    scanf("%s",h);
    if(strcmp(h,"Dry") == 0)return 0;
    if(strcmp(h,"Dryish") == 0)return 1;
    if(strcmp(h,"Damp") == 0)return 2;
    if(strcmp(h,"Soggy") == 0)return 3;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    int t;scanf("%d",&t);
    int hum;
    int a = 1;

    while(t--){
        printf("Case #%d:\n",a++);
        memset(dp,-1,sizeof(dp));
        memset(record,-1,sizeof(record));
        memset(ans,-1,sizeof(ans));

        scanf("%d",&day);
        dp[0][0] = 0.63;
        dp[0][1] = 0.17;
        dp[0][2] = 0.2;

        hum = get();
        dp[1][0] = dp[0][0]*table_relate[0][hum];
        dp[1][1] = dp[0][1]*table_relate[1][hum];
        dp[1][2] = dp[0][2]*table_relate[2][hum];

        for(int i = 2;i <= day;i++){
            hum = get();
            for(int j = 0;j < 3;j++){
                dp[i][j] = max(i,j,dp[i-1][0]*table_w[0][j]*table_relate[j][hum],dp[i-1][1]*table_w[1][j]*table_relate[j][hum],dp[i-1][2]*table_w[2][j]*table_relate[j][hum]);
                //cout <<"dp["<<i<<"]["<<j<<"] = "<<dp[i][j]<<" record["<<i<<"]["<<j<<"] = "<<record[i][j]<<endl;
            }
        }

        int temp;
        if(dp[day][0] >= dp[day][1] && dp[day][0] >= dp[day][2]){temp = 0;ans[day+1] = 0;}
        if(dp[day][1] >= dp[day][0] && dp[day][1] >= dp[day][2]){temp = 1;ans[day+1] = 1;}
        if(dp[day][2] >= dp[day][0] && dp[day][2] >= dp[day][1]){temp = 2;ans[day+1] = 2;}

        int cou = day;
        while(cou != 1){
            temp = record[cou][temp];
            ans[cou] = temp;
            cou--;
        }

        for(int i = 2;i <= day+1;i++){
            if(ans[i] == 0)printf("Sunny\n");
            else if(ans[i] == 1)printf("Cloudy\n");
            else printf("Rainy\n");
        }
    }


    return 0;
}
