#include <iostream>
#include <cstdio>
#include <stack>
#include <cmath>
using namespace std;

struct node{
    int index;
    node* left;
    node* right;
};

int quary;
node tree;
stack<int> in;
char temp;
int e = 0;
bool beNULL;
bool minu = 0;
bool values;

void input(node* t){
    t->index = 0;
    t->right = NULL;
    t->left = NULL;

    do{
        if(temp == '('){
            int sum = 0;
            e = 0;
            bool counting = false;
            
            while(temp = getchar()){
                if(temp == '-'){
                	//counting = true;
					minu = true;
					//cout <<"negetive\n";
					continue;
				}
                if(temp >= '0' && temp <= '9'){
                    counting = true;
                    values = true;
					in.push(temp-'0');
                	//cout <<"top = "<<in.top()<<endl;
                }else if(counting && /*temp != ')' &&*/ (temp < '0' || temp >'9')){
                    //cout <<"!!\n";
                    while(!in.empty()){
                        sum+=in.top()*(int)pow(10.0,e);
                        e++;
                        //cout <<"sum = "<<sum<<endl;
                        in.pop();
                    }
                    break;
				}
                else if(temp == ')' && !counting){
                    //cout <<"NULL ,return\n";
                    temp = getchar();
                    beNULL = 1;return;
                }
           }
           if(minu){sum *=-1;minu = 0;}
           t->index = sum;
           //cout <<"index = "<<t->index<<endl;
           t->left = new node;
           t->right = new node;
           //cout <<"in left tree, in index "<<t->index<<endl;
           input(t->left);
           if(beNULL){beNULL = 0;t->left = NULL;}
           //if(t->left == NULL){cout <<"be NULL\n";}
           //else {cout <<"left still has sth\n";}
           //cout <<"in right tree, in index "<<t->index<<endl;
           input(t->right);
           if(beNULL){beNULL = 0;t->right = NULL;}
           //if(t->right == NULL){cout <<"be NULL\n";}
           //else {cout <<"right still has sth\n";}
           if(temp == ')'){
                temp = getchar();
                //cout <<"return\n";
                return;
           }
        }else if(temp == ')'){
            temp = getchar();
            //cout <<"return\n";
            return;}
    }while(temp = getchar());
}
int pointer;
long long a[10000];
void summing(node* t,long long s){
    if(t->right == NULL && t->left == NULL){
        a[pointer] = s+t->index;
        pointer++;
        //cout <<"s = "<<s+t->index<<endl;
    }else if(t->right == NULL){
        summing(t->left,s+t->index);
    }else if(t->left == NULL){
        summing(t->right,s+t->index);
    }else {
        summing(t->left,s+t->index);
        summing(t->right,s+t->index);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    char t;
    while(scanf("%d",&quary) == 1){
        temp = 0;
        beNULL = 0;
        values = false;
        input(&tree);
        //cout <<"end input\n"<<endl<<endl<<endl;
        //system("pause");
        if(!values){
			printf("no\n");
			continue;
		}
        pointer = 0;
        summing(&tree,0);
        int i;
        for(i = 0;i < pointer;i++){
            if(quary == a[i]){printf("yes\n");break;}
        }
        if(i == pointer)printf("no\n");

    }



    return 0;
}
