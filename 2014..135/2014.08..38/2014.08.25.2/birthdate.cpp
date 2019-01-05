#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
int m[3],M[3],t[3];
char old[20],young[20],temp[20];

int main()
{
    scanf("%d",&n);

    for(int i = 0;i < n;i++){
        scanf("%s %d %d %d",temp,&t[0],&t[1],&t[2]);
        if(i == 0){
            strcpy(old,temp);
            strcpy(young,temp);
            m[0] = M[0] = t[0];
            m[1] = M[1] = t[1];
            m[2] = M[2] = t[2];
        }else {
            if(t[2] < M[2]){
                M[2] = t[2];M[1] = t[1];M[0] = t[0];
                strcpy(old,temp);
            }else if(t[2] == M[2]){
                if(t[1] < M[1]){
                    M[1] = t[1];M[0] = t[0];
                    strcpy(old,temp);
                }else if(t[1] == M[1]){
                    if(t[0] < M[0]){strcpy(old,temp);M[0] = t[0];}
                }
            }

            if(t[2] > m[2]){
                strcpy(young,temp);
                m[2] = t[2];m[1] = t[1];m[0] = t[0];
            }else if(t[2] == m[2]){
                if(t[1] > m[2]){
                    strcpy(young,temp);
                    m[1] = t[1];m[0] = t[0];
                }else if(t[1] == m[1]){
                    if(t[0] > m[0]){strcpy(young,temp);m[0] = t[0];}
                }
            }
        }
    }
    printf("%s\n%s\n",young,old);

    return 0;
}
