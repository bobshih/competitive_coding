#include <iostream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

int main(){

unsigned char key;
     cout <<"start\n";
key=getch();
  switch(key)
  {
   case 224:
    cout <<"get\n";
    key=getch();
    switch(key)
    {
     case 72:
          cout <<"up\t"; // UP
          cout <<key;
     break;
     case 0x50:
          cout <<"down\t"; // DOWN
          cout <<key;
     break;
     case 0x4D: 
          cout <<"right\t";// Right
          cout <<key;
     break;
     case 0x4B: 
          cout <<"left\t";// Left
          cout <<key;
     break;
     }
     
     cout <<key<<hex;
     break;
   default:
           cout <<"!";
           cout <<(int)key<<"\n";
           cout <<"!\n";
           break;
   }
   cout <<"\nya "<<key;
   cout <<"\nEND";
system("PAUSE");
return 0;
}
