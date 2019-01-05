#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

#define stop system("pause")
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    int tt;
    scanf("%d",&tt);
    char str[15];

    while(tt--){
        scanf("%s",str);
        sort(str,str+strlen(str));
        printf("%s\n",str);

        int i;
        int change;
        do{
            i = -1;
            for(int j = strlen(str)-1;j > 0;j--){
                if(str[j] > str[j-1]){
                    i = j-1;break;
                }
            }if(i == -1)break;

            for(int j = strlen(str)-1;j > i;j--){
                if(str[j] > str[i]){
                    char temp = str[i];
                    //cout <<str[j]<<"\t"<<str[i]<<endl;
                    str[i] = str[j];
                    str[j] = temp;
                    i++;break;
                }
            }//printf("%s\n",str);

            for(int j = 0;j < (strlen(str)-i)/2;j++){
                char temp = str[i+j];
                str[i+j] = str[strlen(str)-1-j];
                str[strlen(str)-1-j] = temp;
            }

            printf("%s\n",str);
            //stop;
        }while(true);

        //if(tt)
        puts("");
    }

    return 0;
}
