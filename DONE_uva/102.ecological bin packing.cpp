#include <iostream>

using namespace std;

long long solve(long long a,long long b,long long c,long long d,long long e,long long f,long long g,long long h,long long i,int m){
     switch (m){
            case 1:
                 return(b+c+d+e+g+i);
            case 2:
                 return(b+c+d+f+g+h);
            case 3:
                 return(a+b+e+f+g+i);
            case 4:
                 return(a+b+d+f+h+i);
            case 5:
                 return(a+c+e+f+g+h);
            case 6:
                 return(a+c+d+e+h+i);
            }
     }

void print(long long a){
     switch (a){
            case 1: cout <<"BCG ";break;
            case 2: cout <<"BGC ";break;
            case 3: cout <<"CBG ";break;
            case 4: cout <<"CGB ";break;
            case 5: cout <<"GBC ";break;
            case 6: cout <<"GCB ";break;}
     }

int main(){
    long long a,b,c,d,e,f,g,h,i;
    long long min, m;
    
    while (cin >>a>>b>>c>>d>>e>>f>>g>>h>>i/*scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&g,&h,&i) != EOF*/){
          
          //cin >>a>>b>>c>>d>>e>>f>>g>>h>>i;
          //if(cin.eof()){break;}
          min = solve(a,b,c,d,e,f,g,h,i,1);m = 1;
          for(int mathod = 2;mathod < 7;mathod++){
                  if(solve(a,b,c,d,e,f,g,h,i,mathod)<min){min = solve(a,b,c,d,e,f,g,h,i,mathod);m = mathod;}
                  }
          print(m);cout<<min<<endl;
          }
    //cout <<endl;
    return 0;
    }
