#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdio>
#include <cstring>

���I(�}�C�H�����ƦC)
1.
��DFS�j�M�A�M��Ҧ��i��զX�A�Q�Τ覡�A�q�̤j��}�l�d��A�̧ǻP�U�@�Ӫ��׶i��զX�A�Ӹ`�O�A�b�զX��DFS���A��A�^�Ҩ줧�e�������A
�ɡAvis[i]���ȭn�^��0�A���O��i�JDFS���L�{���A�n���Nvis[i]�]��1�A�p�`�@�Хܪ��a��A���p��P�_�����F�O�H�Q��DFS�~��bool�ܼƨ��x�s�N
�i�H�F

2.
�Q�ΰŪK���ޥ��A�j�j��֭��ƪ�DFS�A��e�@��vis[i]��0�ɡA�B�ثe���ȻP�e�@�ӬۦP�A�N��H�L���զX�����ꤣ�X�өҭn�����ת��A�ҥH�H
continue���L�j�骺�o�@���A�p�`�G�ХܳB

3.
�������׬�0�ɪ��B�z�覡�A�b�@�}�l���禡���|�C�X�o�@�i��ﶵ�A������n�o�򰵡H�]���p�G���U�����j��i��B�z�A�|�o�ͥi��L�k�B�z
vis[a-1]��0�����D�A�t�@�譱�A�b�i����arr[a] == arr[a-1]���ɭԡA�]�|�o�Ϳ��~�A����ѨM��k���@�N�O��@�S�Ҷi��B�z�A�p�`�T

using namespace std;
int arr[100];
bool vis[100];
int n;
bool flag;

bool cmp(int a,int b){
    return a > b;
}
bool all(){
    for(int i = 0;i < n;i++){
        if(vis[i] == 0)return 0;
    }return 1;
}
void dfs(int len,int now,int index){
    if(flag){return ;}
    //cout <<"now = "<<now<<" index = "<<index<<endl;
    if(now == len){
        if(all()){flag = true;}
        else dfs(len,0,0);
        return;
    }

    if(now == 0){                //�`�T
        int k = 0;               //�`�T
        while(vis[k] == 1){      //�`�T
            k++;                 //�`�T
        }                        //�`�T
        vis[k] = true;           //�`�T
        dfs(len,arr[k],k+1);     //�`�T
        vis[k] = false;          //�`�T
        return;
    }

    for(int a = index;a < n;a++){
        if(vis[a] != 1 && arr[a]+now <= len){
            if(vis[a-1] == 0 && arr[a] == arr[a-1])continue;    //�`�G
            vis[a] = true;                                      //�`�@
            dfs(len,now+arr[a],a+1);                            //�`�@
            vis[a] = false;                                     //�`�@
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int sum;

    while(scanf("%d",&n) != EOF){
        if(n == 0)break;
        sum = 0;

        for(int i = 0;i < n;i++){
            scanf("%d",&arr[i]);
            sum += arr[i];
        }sort(arr,arr+n,cmp);

         flag = 0;
         for(int i = arr[0];i <= sum;i++){
            //cout <<"i = "<<i<<endl;
            if(sum%i == 0){
                memset(vis,0,sizeof(vis));
                dfs(i,0,0);
                if(flag){printf("%d\n",i);break;}
            }
         }
    }

    return 0;
}
