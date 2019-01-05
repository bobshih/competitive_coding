#include <iostream>
#include <cstring>
using namespace std;

bool lights[3][3];
void Light(int x,int y){
    lights[x][y] = !lights[x][y];
    if(x != 0)lights[x-1][y] = !lights[x-1][y];
    if(x != 2)lights[x+1][y] = !lights[x+1][y];
    if(y != 0)lights[x][y-1] = !lights[x][y-1];
    if(y != 2)lights[x][y+1] = !lights[x][y+1];

    //if(x != 0 && y != 0)lights[x-1][y-1] = !lights[x-1][y-1];
    //if(x != 0 && y != 2)lights[x-1][y+1] = !lights[x-1][y+1];
    //if(x != 2 && y != 0)lights[x+1][y-1] = !lights[x+1][y-1];
    //if(x != 2 && y != 2)lights[x+1][y+1] = !lights[x+1][y+1];
}
int main()
{
    memset(lights,1,sizeof(lights));

    int n;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cin >>n;
            if(n == 0)continue;
            else {
                if(n%2)Light(i,j);
            }
        }
    }

    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cout <<lights[i][j];
        }cout <<endl;

    }

    return 0;
}
