#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
string s[105];
int test(int i,int j){
    string temp = s[i]+s[j];
    //cout <<temp<<endl;
    bool flag = 0;
    for(int i = 0;i < temp.size()/2;i++){
        if(temp[i] == temp[temp.size()-i-1])continue;
        else {flag = 1;break;}
    }
    if(flag == 0)return 1;
    flag = 0;
    temp = s[j]+s[i];
    //cout <<temp<<endl;
    for(int i = 0;i < temp.size()/2;i++){
        if(temp[i] == temp[temp.size()-i-1])continue;
        else {flag = 1;break;}
    }
    if(flag == 0)return 2;
    return 0;
}

int main()
{
    int T;scanf("%d",&T);
    while(T--){
        int n;scanf("%d",&n);
        //cout <<"T = "<<T<<endl;
        for(int i = 0;i < n;i++){
            cin >>s[i];
        }

        int flag,i,j;
        for(i = 0;i < n;i++){
            for(j = 0;j < n;j++){
                flag = test(i,j);
                if(flag != 0)break;
            }
            if(flag == 1){
                //cout <<"ans = ";
                cout <<s[i]<<s[j]<<endl;
                break;
            }else if(flag == 2){
                //cout <<"ans = ";
                cout <<s[j]<<s[i]<<endl;
                break;
            }
        }
        if(flag == 0)cout <<0<<endl;
    }

    return 0;
}
