#include <iostream>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int children;
    scanf("%d",&children);

    vector<string> name;
    string te;
    char s[100];

    for(int i = 0;i < children;i++){
        scanf("%s",s);
        te = s;
        name.push_back(te);
    }
    int start,limit;
    scanf("%d%c%d",&start,&s[0],&limit);
    start--;
    limit--;


    while(!name.empty()){


        if(name.size() > limit+start){
            start += limit;//cout <<"start = "<<start<<endl;
            cout <<name[start]<<endl;
            name.erase(name.begin()+start);
        }else {
            start = (start + limit)%name.size();
            //cout <<"start = "<<start<<endl;
            cout <<name[start]<<endl;
            name.erase(name.begin()+start);

        }
    }

    return 0;
}
