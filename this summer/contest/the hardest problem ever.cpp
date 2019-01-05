#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char t[20];
    char data[201];
    for(int i = 0;i < 201;i++)data[i] = ' ';
    char temp;
    int i;

    while(true){
        scanf("%s",t);
        if(t[0] == 'S'){
            getchar();
            i = 0;
            while(true){
                temp = getchar();
                if(temp == '\n'){break;}
                else {
                    //cout <<"temp is "<<temp;
                    if(isupper(temp)){printf("%c",'A' + (temp-'A'+21)%26);}
                    else {printf("%c",temp);}
                    //cout <<" data["<<i<<"] is "<<data[i]<<endl;
                    i++;
                }
            }printf("\n");
            /*for(int a = 0;a < i;a++){
                cout <<"data["<<a<<"] is ";
                printf("%c\n",&data[a]);
            }printf("\n");*/

        }else if(t[0] == 'E'){break;}
        scanf("%s",t);
    }



    return 0;
}
