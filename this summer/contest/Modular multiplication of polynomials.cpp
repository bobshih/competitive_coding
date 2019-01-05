#include <iostream>
#include <cstdio>
#include <cstring>


AC的理由，以exclusive or ( ^= )的方式取代if else的判斷式，加快運行時間
另外，資料進來的時候，可以處理就處理，盡量別事後處理

using namespace std;
int a[10000];
int b[10000];
int c[10000];
int d[10000];

void mulit(int s1,int s2,int s3){
    int all = s1+s2-1;


    //cout <<"all = "<<all<<endl;
    //cout <<"in plus\n";
    /*for(int i = 0;i < s2;i++){
        if(b[i] == 0){continue;}

        for(int j = 0;j < s1;j++){
            if(d[i+j] == 0){d[i+j] += a[j];}
            else {
                if(a[j] == 1){d[i+j] = 0;}
            }
        }
        /*printf("%d ",all);
        for(int l = 0;l < all;l++){
            printf("%d ",d[l]);
        }cout <<endl;*/
//    }

    //cout <<"in minus\n";
    /*for(int i = 10000;i >= 0;i--){
        if(i < s3 && i != 0){break;}

        if(d[i] == 1){
            for(int j = 0;j < s3;j++){
               //cout <<"d["<<i-j<<"] "<<d[i-j]<<" meet c["<<j<<"] "<<c[j];
                if(d[i-j] == 0){d[i-j] = c[j];}
                else if(c[j] == 1){
                    d[i-j] = 0;
                }
                //cout <<" become "<<d[i-j]<<endl;
            }
            //system("pause");
            /*printf("%d ",all);
            for(int l = 0;l < all;l++){
                printf("%d ",d[l]);
            }cout <<endl;*/
       /* }
    }*/
    int len3 = s3-1;
    int len = s1+s2-2;
    int j;
    while(len3<=len){
        j = len3;
        for(int k=len;k>=len-len3;k--){
            d[k] ^= c[j--];
        }

        while(d[len]==0)len--;
    }
    //cout<<len+1<<" ";
    printf("%d ",len+1);
    for(int k = len;k>=0;k--)printf("%d ",d[k]);//cout<<d[k]<<" ";
    printf("\n");
    //cout<<endl;
    //printf("%d ",all);
    //cout <<"in out\n";
    /*bool start = 0;
    for(int l = all;l >= 0;l--){
        if(start == 0 && d[l] == 0)continue;
        else if(start == 0 && d[l] == 1){
                start = 1;all = l;break;
                cout <<"all = "<<all<<endl;
                printf("%d ",d[l]);}
        else if(start){
            printf("%d ",d[l]);
        }
    }

    if(start){printf("%d ",++all);}
    else {printf("%d ",all);}

    for(int i = all-1;i >= 1;i--){
        printf("%d ",d[i]);
    }printf("%d\n",d[0]);*/
}

int main()
{
    int test;
    scanf("%d",&test);
    int size1,size2,size3;

    for(int m = 0;m < test;m++){
        memset(d,0,10000);
        scanf("%d",&size1);
        for(int i = size1-1;i >= 0;i--){
            scanf("%d",&a[i]);
            //cout <<"a["<<i<<"] = "<<a[i]<<endl;
        }

        scanf("%d",&size2);
        int coun = size2-1;
        for(int i = size2-1;i >= 0;i--){
            scanf("%d",&b[i]);
            if(b[i] == 0){coun--;continue;}

            for(int j = 0;j < size1;j++){
                if(d[coun+j] == 0){d[coun+j] += a[j];}
                else {
                    if(a[j] == 1){d[coun+j] = 0;}
                }
            }coun--;
            //cout <<"b["<<i<<"] = "<<b[i]<<endl;
        }

        scanf("%d",&size3);
        for(int i = size3-1;i >= 0;i--){
            scanf("%d",&c[i]);
            //cout <<"c["<<i<<"] = "<<c[i]<<endl;
        }

        mulit(size1,size2,size3);

    }


    return 0;
}
