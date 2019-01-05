#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));

    for(int i = 0;i < 200;i++){
            //srand(time(NULL));
        cout <<rand()%30<<endl;
    }

    return 0;
}
