#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <stack>

提示，EBNF輸入法是重點，因為這種輸入法，使得左括弧直接無視，也因此當遇到右括弧的時候，就要pop出兩個元素進行乘法！！！

using namespace std;

class matrix{
    public:
        char name;
        int row,col;
        matrix muli(matrix &t){
            matrix temp;
            temp.row = row;
            temp.col = t.col;
            return temp;
        }
};

int main()
{
    int n;
    char expr[150];
    matrix m[26];
    scanf("%d",&n);

    char t;int n1,n2;
    for(int i = 0;i < n;i++){
        getchar();
        scanf("%c %d %d",&m[i].name,&m[i].row,&m[i].col);
    }

    while(scanf("%s",expr) != EOF){
        stack<matrix> sta;
        int sum = 0;

        for(int i = 0;expr[i] != '\0';i++){
            if(expr[i] >= 'A' && expr[i] <= 'Z'){
                for(int j = 0;j < 26;j++){
                    if(m[j].name == expr[i]){sta.push(m[j]);break;}
                }
            }else if(expr[i] == ')'){
                matrix t2 = sta.top();
                sta.pop();
                matrix t1 = sta.top();
                sta.pop();

                if(t1.col != t2.row){
                    //cout <<"!!\n";
                    sum = -1;break;
                }
                sum += (t1.row*t1.col*t2.col);

                matrix temp;
                temp = t1.muli(t2);
                sta.push(temp);
            }
        }

        if(sum == -1){printf("error\n");}
        else printf("%d\n",sum);

        while(!sta.empty()){
            sta.pop();
        }
    }


    return 0;
}
