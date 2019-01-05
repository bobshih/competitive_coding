#include <iostream>

using namespace std;

int main()
{
    int n,k;cin >>n>>k;

    if(n < k || (n > 1 && k == 1)){
        cout <<-1<<endl;return 0;
    }else if(n == k){
        for(int i = 0;i < n;i++){
            cout <<(char)('a'+i);
        }
    }else {
        int temp = k-2;
        int i;
        for(i = 0;i < n-temp;i++){
            if(i%2 == 0)cout <<'a';
            else cout <<'b';
        }
        for(int i = 2;i < temp+2;i++){
            cout <<(char)('a'+i);
        }cout <<endl;
    }

    return 0;
}
