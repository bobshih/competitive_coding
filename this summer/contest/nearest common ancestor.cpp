#include <iostream>
#include <cstdio>


using namespace std;

void find_floor(int root,int tree[],int fl[],int n){
    for(int i = 0;i < n;i++){
        if(tree[i] == root){
            fl[i] = fl[root]+1;
            //cout <<root<<" has a child "<<i<<" in the floor "<<fl[i]<<endl;
            find_floor(i,tree,fl,n);
            }
    }
}

int main()
{
    int test;
    scanf("%d",&test);

    for(int i = 0;i < test;i++){
        int node;
        scanf("%d",&node);
        //cout <<"get node, node are "<<node<<endl;

        int *tree = new int[node+1];
        for(int j = 0;j < node;j++){tree[j] = 0;}
        tree[0] = -1;
        int *floor = new int[node+1];
        for(int j = 0;j < node;j++){floor[j] = -1;}
        int temp1,temp2;

        for(int j = 0;j < node-1;j++){
            scanf("%d %d",&temp1,&temp2);
            tree[temp2] = temp1;
        }

        for(int j = 0;j < node+1;j++){
            if(tree[j] == 0){
                    floor[j] = 0;
                    //cout <<j<<" is the root"<<endl;
                    find_floor(j,tree,floor,node+1);break;}
        }

        scanf("%d %d",&temp1,&temp2);
        int ans;
        while(true){
            if(floor[temp1] > floor[temp2]){temp1 = tree[temp1];}
            else if(floor[temp1] < floor[temp2]){temp2 = tree[temp2];}
            else if(floor[temp1] == floor[temp2]){
                if(temp1 == temp2){ans = temp1;break;}
                else {temp1 = tree[temp1];}
            }

        }
        printf("%d\n",ans);

        delete [] tree;
        delete [] floor;
    }


    return 0;
}
