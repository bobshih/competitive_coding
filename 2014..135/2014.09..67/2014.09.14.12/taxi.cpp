#include <iostream>

using namespace std;

int main()
{
    int n;cin >>n;
    int child[100005],car = 0,one = 0,three = 0,two = 0;
    for(int i = 0;i < n;i++){
        cin >>child[i];
        if(child[i] == 4){car++;}
        else if(child[i] == 2)two++;
        else if(child[i] == 3)three++;
        else one++;
    }

    car += (two/2);
    if(two%2)two = 1;
    else two = 0;
    int tt = min(one,three);
    car += tt;
    one -= tt;
    three -= tt;

    if(three > 0){car+=three;car+=two;}
    else if(one > 0){
        if(two && one){
            car++;
            if(one >= 2)one-=2;
            else one--;
            car+=one/4;if(one%4 != 0)car++;}
        else {car+=(one/4);if(one%4 != 0)car++;}
    }else if(two > 0){
        car++;
    }
    cout <<car<<endl;

    return 0;
}
