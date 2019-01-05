#include <iostream>
#include <cstdio>
using namespace std;

int n,k;

1.
自動機!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
2.
推出輸贏的關係

class TREE{
public:
    TREE * c[26];
    bool win,lose;

    TREE():win(false),lose(true){
        for(int i = 0;i < 26;i++){
            c[i] = NULL;
        }
    }
    void add(char* t){
        int x = *t;
        if(!x)return;
        x-='a';lose = false;
        if(c[x] == NULL)c[x] = new TREE;
        c[x]->add(t+1);
    }
    void dfs(){
        if(lose)return;
        for(int i = 0;i < 26;i++){
            if(c[i]){
                c[i]->dfs();
                win |= !(c[i]->win);
                lose |= !(c[i]->lose);
            }

        }
    }
}tree;

int main()
{
    scanf("%d %d",&n,&k);

    char temp[100040];
    for(int i = 0;i < n;i++){
        scanf("%s",temp);
        tree.add(temp);
    }
    tree.dfs();

    printf(tree.win && (tree.lose || k % 2) ? "First" : "Second");

    return 0;
}
