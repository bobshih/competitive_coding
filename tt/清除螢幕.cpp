#include <iostream>
#include <windows.h>

using namespace std;

int main(){
    char words[100] = {"hello , world"};
    int i,a;
    
    print:
    cin >>a;
    for(i = 0;i < a;i++){
    cout <<words<<"\t";}
    
    cout <<endl<<"!?"<<endl;
    
    system("pause");
    system("cls");
    
    goto print;
    
    
    }
