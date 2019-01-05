#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;

bool max_answer(string s[],int ma,int M){
    int counter = 0;

    for(int i = 0;i < 4;i++){
        if(s[i].length()-2 <= ma/2){counter++;}
    }

    if(counter == 3)return true;
    return false;
}
bool min_answer(string s[],int mi,int m){
    int counter = 0;

    for(int i = 0;i < 4;i++){
        if(s[i].length()-2 >= mi*2){counter++;}
    }

    if(counter == 3)return true;
    return false;
}

int main()
{
    string s[4];

    for(int i = 0;i < 4;i++){
        getline(cin,s[i]);
    }

    int maximum = 0;
    int minimum = 1000;
    int M,m;

    for(int i = 0;i < 4;i++){
        if(s[i].length()-2 > maximum){
                maximum = s[i].length()-2;M = i;}
        if(s[i].length()-2 < minimum){
                minimum = s[i].length()-2;m = i;}
    }

    if(max_answer(s,maximum,M) && min_answer(s,minimum,m)){
        printf("%c",'C');
    }else if(max_answer(s,maximum,M)){
        printf("%c",M+65);
    }else if(min_answer(s,minimum,m)){
        printf("%c",m+65);
    }else {printf("%c",'C');}


    return 0;
}
