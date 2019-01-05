#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

automaton資料結構可以任意刪去陣列中的元素(不論在那兒)，前提是，t陣列中的所有元素，s都要有
suffix資料結構則是任意調換陣列中的兩個位置(一樣，不論在那兒)，判斷條件用次序來判斷，換句話說，以t陣列作為s陣列最常共同子陣列，去判斷是不是


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
