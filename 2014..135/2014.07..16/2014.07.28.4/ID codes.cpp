#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    char str[55];

    while(scanf("%s",str)){
        if(str[0] == '#')break;

        int i = -1;
        for(int j = strlen(str)-1;j >= 0;j--){
            if(str[j] > str[j-1]){i = j-1;break;}
        }if(i == -1){printf("No Successor\n");continue;}

        int change;
        for(int j = strlen(str)-1;j > i;j--){
            if(str[j] > str[i]){change = j;break;}
        }

        //cout <<"i = "<<i<<" change = "<<change<<endl;
        char temp = str[change];
        str[change] = str[i];
        str[i] = temp;
        i++;
        //for(int j = 0;j < strlen(str);j++){
        //    printf("%c",str[j]);
        //}cout <<endl;


        //cout <<"times = "<<(strlen(str)-i)/2<<endl;
        for(int j = 0;j < (strlen(str)-i)/2;j++){
            temp = str[i+j];
            //cout <<"temp = "<<temp<<endl;
            str[i+j] = str[strlen(str)-1-j];
            //cout <<"str[] = "<<str[strlen(str)-1-j]<<endl;
            str[strlen(str)-1-j] = temp;
        }

        for(int j = 0;j < strlen(str);j++){
            printf("%c",str[j]);
        }cout <<endl;
    }

    return 0;
}
