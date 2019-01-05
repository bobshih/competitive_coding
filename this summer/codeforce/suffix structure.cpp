#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

automaton��Ƶ��c�i�H���N�R�h�}�C��������(���צb����)�A�e���O�At�}�C�����Ҧ������As���n��
suffix��Ƶ��c�h�O���N�մ��}�C������Ӧ�m(�@�ˡA���צb����)�A�P�_����Φ��ǨӧP�_�A���y�ܻ��A�Ht�}�C�@��s�}�C�̱`�@�P�l�}�C�A�h�P�_�O���O


using namespace std;

int main(){
    string s,t;
    cin >>s>>t;

    //cout <<"s = "<<s<<" size = "<<s.size()<<endl;
    //cout <<"t = "<<t<<" size = "<<t.size()<<endl;

    int al_s[30],al_t[30];
    memset(al_s,0,sizeof(al_s));
    memset(al_t,0,sizeof(al_t));

    for(int i = 0;i < s.size();i++){
        al_s[s[i]-'a']++;
    }
    for(int i = 0;i < t.size();i++){
        al_t[t[i]-'a']++;
    }

    bool automaton = 0;
    if(s.size() > t.size()){automaton = 1;}

    for(int i = 0;i < 30;i++){
        if(al_t[i] > al_s[i]){
            printf("need tree\n");
            return 0;
        }
    }

    int suffix = 0;
    for(int i = 0;i < s.size();i++){
        if(s[i] == t[suffix])suffix++;
    }
    bool arr = 0;
    if(suffix != t.size()){arr = 1;}

    if(arr && automaton){printf("both\n");}
    else if(arr){printf("array\n");}
    else {printf("automaton\n");}

    return 0;
}
