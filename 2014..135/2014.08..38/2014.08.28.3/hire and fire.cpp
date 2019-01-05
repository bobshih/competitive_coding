#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

struct tree{
    vector<string> name;
    string         dad;
    string         self;
    int            floor;
};

tree company[5010];
int pos;

void clean(int i){
    int j;
    for(j = i;company[j].floor > -1;j++){
        //cout <<"j is "<<j<<endl;
        //system("pause");
        company[j].name = company[j+1].name;
        company[j].dad = company[j+1].dad;
        company[j].self = company[j+1].self;
        company[j].floor = company[j+1].floor;
    }
    company[j].floor = -1;
}
void remov(string dad,string son){
    for(int i = 0;i < 1010;i++){
        if(company[i].self == dad && company[i].floor != -1){
            for(int j = 0;j < company[i].name.size();j++){
                if(company[i].name[j] == son){
                    company[i].name.erase(company[i].name.begin()+j);
                }
            }
        }
    }
}
void remo(string dad,string son,string new_son){
    for(int i = 0;i < 1010;i++){
        if(company[i].self == dad && company[i].floor != -1){
            for(int j = 0;j < company[i].name.size();j++){
                    //cout <<"in remo j = "<<company[i].name[j]<<" son is "<<son<<" new son is "<<new_son<<endl;
                if(company[i].name[j] == son){
                    company[i].name.erase(company[i].name.begin()+j);
                    company[i].name.insert(company[i].name.begin()+j,new_son);
                    return;
                }
            }
        }
    }
}
void fire_son(string n,int fl,string dad){
    for(int i = 0;i < 1010;i++){
        if(company[i].self == n && company[i].floor >= fl){
            if(company[i].name.empty()){
                remov(dad,n);
                clean(i);
                return;
            }else {
                remo(dad,n,company[i].name.front());
                company[i].self = company[i].name.front();
                fire_son(company[i].name.front(),company[i].floor+1,company[i].self);
            }
        }
    }
}

void fire(string n,int fl){
    //cout <<"fire "<<n<<" after the floor "<<fl<<endl;
    for(int i = 0;i < 1010;i++){
        if(company[i].self == n && company[i].floor >= fl){
            if(company[i].name.empty()){
                    remov(company[i].dad,n);
                    clean(i);
                    return;
            }else {
                //cout <<"dad is "<<company[i].dad<<" name is "<<n<<" the new one is "<<company[i].name.front()<<endl;;
                if(company[i].dad != " ")remo(company[i].dad,n,company[i].name.front());

                company[i].self = company[i].name.front();
                //cout <<"prompt "<<company[i].self<<endl;
                fire_son(company[i].name.front(),company[i].floor+1,company[i].self);
            }
        }

    }
}

void print(string n){
    for(int i = 0;i < 1010;i++){
        if(company[i].self == n && company[i].floor != -1){
            for(int a = 0;a < company[i].floor;a++)printf("+");
            cout <<n<<endl;
            //out <<"size is "<<company[i].name.size()<<endl;
            //system("pause");
            for(int a = 0;a < company[i].name.size();a++){
                print(company[i].name[a]);
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    for(int i = 0;i < 1010;i++){
        company[i].floor = -1;
        company[i].name.clear();
    }

    char temp1[25],temp2[25],temp3[25];
    string t,s1,s2,s3;
    scanf("%s",temp1);
    t = temp1;

    company[0].floor = 0;
    company[0].dad =" ";
    company[0].self = t;
    pos = 1;
    int occassion;

    while (scanf("%s",temp1) != EOF){
        s1 = temp1;
        if(s1 == "print"){occassion = 1;}
        else if(s1 == "fire"){occassion = 2;scanf("%s",temp2);}
        else {scanf("%s %s",temp2,temp3);occassion = 3;}

        switch(occassion){
            case 1:
                print(company[0].self);
                printf("------------------------------------------------------------\n");
                break;
            case 2:
                s1 = temp2;
                fire(s1,0);
                break;
            case 3:
                s1 = temp1;
                s3 = temp3;
                for(int i = 0;i < 1010;i++){
                    if(company[i].self == s1 && company[i].floor != -1){
                        company[i].name.push_back(s3);

                        for(;pos < 1010;pos++){
                            //cout <<"pos is "<<pos<<endl;
                            if(company[pos].floor != -1)continue;
                            else {
                                company[pos].dad = company[i].self;
                                company[pos].floor = company[i].floor+1;
                                company[pos].self = s3;
                                break;}
                        }
                    }
                }
                break;
        }

    }
    return 0;
}
