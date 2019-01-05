#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void mathod_if_n_is_odd(int n,int** N);
void mathod_if_n_is_4m(int n,int** N);
void mathod_if_n_is_4m_2(int n,int** N);
void sum_row(int n,int** N){
     int i,j,sum = 0;
     for(i = 0;i < n;i++){
           for(j = 0;j < n;j++){
                 sum = sum + N[i][j];}
           cout <<"the "<<i<<" row's sum is "<<sum;
           sum = 0;
           cout <<endl;}
     }
void sum_column(int n,int** N){
     int i,j,sum = 0;
     for(i = 0;i < n;i++){
           for(j = 0;j < n;j++){
                 sum = sum + N[j][i];}
           cout <<"the "<<i<<" column's sum is "<<sum;
           sum = 0;
           cout <<endl;
           }
     }
void output(int n,int** N){
     int i,j;
     for(i = 0;i < n;i++){
           for(j = 0;j < n;j++){
                 cout <<N[i][j]<<"\t";
                 }cout <<endl;}
     sum_row(n,N);
     sum_column(n,N);
     }

int main(){
    int n,i,j;
    int sum,temp;

    cout <<"´X¶¥¤Û¤è? ";
    cin >>n;

    sum = (n*(n*n + 1)) / 2;
    int** N = (int**)malloc(sizeof(int *)*n);
    for(i = 0;i < n;i++){
          N[i] = (int*)malloc(sizeof(int)*n);}

    for(i = 0;i < n;i++){
          for(j = 0;j < n;j++){
                N[i][j] = 0;}}

    mathod_if_n_is_4m(n,N);
    cout <<"out\n";
    output(n,N);


    system("pause");
    return 0;
    }
void mathod_if_n_is_odd(int n,int** N){
     int x,y;
     int temp = 2;

     x = n/2;
     y = 0;
     N[y][x] = 1;
     y++;x++;
     cout <<"n = "<<n<<endl;
     while(temp < n*n+1){

                if(y==n && x==n){x = 0;y = 0;}
                else if(x == n){x = 0;}
                else if(y == n){y = 0;}

                if(N[y][x] != 0){y--;x--;
                           if(y < 0){y = n-1;}
                           if(x < 0){x = n-1;}}

                again:
                if(N[y][x] != 0){x--;if(x < 0){x = n-1;}cout <<"!";goto again;}
                else {N[y][x] = temp;}

                cout <<"temp = "<<temp<<"\t";
                cout <<"x = "<<x<<"y = "<<y<<endl;

                y++;x++;

                temp++;

                }
     }
void mathod_if_n_is_4m(int n,int** N){
     int i,j;
     int temp;
     int temp_i,temp_j;

     for(i = 0;i < n;i++){
           for(j = 0;j < n;j++){
                 N[i][j] = i*n + j + 1;}
           }
     output(n,N);

     for(i = 0;i < n;i++){
           for(j = 0;j < n;j++){
                 if(i+j >= n){continue;}

                 temp_i = abs(j - n + 1);
                 temp_j = abs(i - n + 1);
                 temp = N[i][j];
                 N[i][j] = N[temp_i][temp_j];
                 N[temp_i][temp_j] = temp;
                 }}
     output(n,N);
     for(i = 0;i < (n/2);i++){
           temp = N[i][i];
           N[i][i] = N[(n-i-1)][(n-i-1)];
           N[(n-i-1)][(n-i-1)] = temp;
           }
     output(n,N);
     for(i = 0;i < n;i++){
           for(j = 1;j < n;j++){
                 if(j > i){
                      if(j+i != 3){temp = N[i][j];
                             N[i][j] = N[j][i];
                             N[j][i] = temp;}
                      else {continue;}}
                 else {continue;}
                 }
           }

     }
void mathod_if_n_is_4m_2(int n,int** N){}
