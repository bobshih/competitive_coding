#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

int n,m,q;
vector<int> bulb[1001];
char qu[1001], light[1001], last[1001];
vector<int> change_s, unchange_s;
vector<int> change_l, unchange_l;

int main()
{
    //freopen("in.txt", "r", stdin);

    while(scanf("%d %d %d", &n,&m,&q) == 3){
        if(n == 0 && m == 0 && q == 0)break;

        for(int i = 0;i < 1001;i++){
            bulb[i].clear();
            for(int a = 0;a < n;a++){
                bulb[i].push_back(a);
            }
        }
        memset(last, '0', sizeof(last));

        for(int i = 0;i < q;i++){
            scanf("%s %s", qu, light);

            change_s.clear();
            unchange_s.clear();
            change_l.clear();
            unchange_l.clear();
            for(int j = 0;j < n;j++){
                if(qu[j] == '1')change_s.push_back(j);
                else unchange_s.push_back(j);
            }

            for(int j = 0;j < m;j++){
                if(light[j] != last[j]){
                    change_l.push_back(j);
                }else {
                    unchange_l.push_back(j);
                }
            }

            for(int j = 0;j < unchange_l.size();j++){
                int temp = unchange_l[j];
                if(bulb[temp].size() > 1){
                    for(int a = 0;a < change_s.size();a++){
                        for(int b = 0;b < bulb[temp].size();b++){
                            if(bulb[temp][b] == change_s[a]){
                                bulb[temp].erase(bulb[temp].begin()+b);
                                break;
                            }
                        }
                    }
                }
            }
            for(int j = 0;j < change_l.size();j++){
                int temp = change_l[j];
                if(bulb[temp].size() > 1){
                    for(int a = 0;a < unchange_s.size();a++){
                        for(int b = 0;b < bulb[temp].size();b++){
                            if(bulb[temp][b] == unchange_s[a]){
                                bulb[temp].erase(bulb[temp].begin()+b);
                                break;
                            }
                        }
                    }
                }
            }

            //for(int a = 0;a < m;a++){
                //cout <<"bulb["<<a<<"] = ";
                //for(int b = 0;b < bulb[a].size();b++){
                //    cout <<bulb[a][b]<<" ";
                //}cout <<endl;
            //}

            strcpy(last, light);
        }
        char ans[1001];
        for(int i = 0;i < m;i++){
            if(bulb[i].size() != 1){
                putchar('?');
                //ans[i] = '?';
            }else {
                if(bulb[i][0] <= 9)putchar((char)('0' + bulb[i][0]));
                    //ans[i] = (char)('0' + bulb[i][0]);
                else putchar((char)('A' + (bulb[i][0]-10)));
                    //ans[i] = (char)('A'+(bulb[i][0]-10));
            }
        }cout <<endl;
        //ans[m] = '\0';

        //puts(ans);
    }
    return 0;
}
