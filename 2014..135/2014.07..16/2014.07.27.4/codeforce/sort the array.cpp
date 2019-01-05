#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    long long arr[100100];
    memset(arr,LLONG_MAX+100,sizeof(arr));
    //for(int i = 0;i < 100;i++){
    //    cout <<arr[i]<<endl;
    //}
    long long start = -1;
    long long ends = n-1;

    for(int i = 0;i < n;i++){
        scanf("%I64d",&arr[i]);
        if(arr[i] < arr[i-1] && start == -1 && i > 0)start = i;
    }

    int i = start;
    //cout <<"find start\n";
    /*for(i = 0;i < n;i++){
        if(arr[i] > arr[i+1]){
            //cout <<arr[i]<<endl;
            start = ++i;
            //cout <<"start = "<<start<<endl;
            break;
        }
    }*/
    //cout <<"find ends\n";
    for(;i < n;i++){
        //cout <<arr[i]<<endl;
        if(arr[i] < arr[i+1]){
            //cout <<arr[i]<<endl;
            ends = ++i;
            //cout <<"ends = "<<ends<<endl;
            break;
        }
    }

    //cout <<"find bye\n";

    if(start != -1){
        sort(arr+start-1,arr+ends);
        //for(int i = 0;i < n;i++){
        //    printf("%d ",arr[i]);
        //}cout <<endl;

        for(i = 0;i < n;i++){
            if(arr[i] > arr[i+1]){
                printf("no\n");return 0;
            }
        }

        //for(int a = ends;a < n;a++){
        //    if(arr[a] < t){
                //cout <<arr[a]<<endl;
        //        printf("no\n");return 0;}
        //}
    }

    printf("yes\n");
    if(start == -1){printf("1 1\n");}
    else printf("%I64d %I64d\n",start,ends);

    return 0;
}
