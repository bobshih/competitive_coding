#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

struct poi{
    int i;
    int j;

    poi(int a, int b){
        i = a;
        j = b;
    }
};

struct mmm{
    char mm[5][9];
    int step;

    poi check(poi a){
        for(int j = a.j+1;j < 9;j++){
            if(mm[a.i][j] == 'o' && check(a.i, j)){
                return poi(a.i, j);
            }
        }

        for(int i = a.i+1;i < 5;i++){
            for(int j = 0;j < 9;j++){
                if(mm[i][j] == 'o' && check(i,j)){
                    return poi(i,j);
                }
            }
        }

        return poi(-1, -1);
    }

    bool check(int i, int j){
        if(mm[i][j+1] == 'o' && mm[i][j+2] == '.' && j <= 6){
            return true;
        }else if(mm[i+1][j] == 'o' && mm[i+2][j] == '.' && i <= 2){
            return true;
        }else if(mm[i][j-1] == 'o' && mm[i][j-2] == '.' && j >= 2){
            return true;
        }else if(mm[i-1][j] == 'o' && mm[i-2][j] == '.' && i >= 2){
            return true;
        }

        return false;
    }

    bool jump(int d, poi a){
        if(d == 0 && a.i <= 2){     //向下跳
            if(mm[a.i+1][a.j] == 'o' && mm[a.i+2][a.j] == '.'){
                mm[a.i][a.j] = '.';
                mm[a.i+1][a.j] = '.';
                mm[a.i+2][a.j] = 'o';
                return true;
            }
        }

        if(d == 1 && a.j >= 2){     //向左眺
            if(mm[a.i][a.j-1] == 'o' && mm[a.i][a.j-2] == '.'){
                mm[a.i][a.j] = '.';
                mm[a.i][a.j-1] = '.';
                mm[a.i][a.j-2] = 'o';
                return true;
            }
        }

        if(d == 2 && a.i >= 2){     //向上跳
            if(mm[a.i-1][a.j] == 'o' && mm[a.i-2][a.j] == '.'){
                mm[a.i][a.j] = '.';
                mm[a.i-1][a.j] = '.';
                mm[a.i-2][a.j] = 'o';
                return true;
            }
        }

        if(d == 3 && a.j <= 6){     //向右跳
            if(mm[a.i][a.j+1] == 'o' && mm[a.i][a.j+2] == '.'){
                mm[a.i][a.j] = '.';
                mm[a.i][a.j+1] = '.';
                mm[a.i][a.j+2] = 'o';
                return true;
            }
        }

        return false;
    }

    int find_ans(){
        int t = 0;

        for(int i = 0;i < 5;i++){
            for(int j = 0;j < 9;j++){
                if(mm[i][j] == 'o')t++;
            }
        }

        return t;
    }
};

int ans,pp;
queue<mmm> aqueue;

void BFS(mmm m, poi a){
    //cout <<"now\n";

    mmm tp = m;
    if(tp.jump(0, a)){
        tp.step++;
        aqueue.push(tp);
    }

    tp = m;
    if(tp.jump(1, a)){
        tp.step++;
        aqueue.push(tp);
    }

    tp = m;
    if(tp.jump(2, a)){
        tp.step++;
        aqueue.push(tp);
    }

    tp = m;
    if(tp.jump(3, a)){
        tp.step++;
        aqueue.push(tp);
    }
    mmm temp;
    //cout <<"size = "<<aqueue.size()<<endl;
    poi aaaa(0,0);
    while(true && aqueue.size() != 0){
        temp = aqueue.front();
        aqueue.pop();

        aaaa = temp.check(poi(0,0));
        if(aaaa.i != -1)
            BFS(temp, aaaa);
        else {
            int ans_temp = temp.find_ans();
            if(ans > ans_temp){
                /*for(int i = 0;i < 5;i++){
                    for(int j = 0;j < 9;j++){
                        printf("%c", temp.mm[i][j]);
                    }cout <<endl;
                }cout <<endl;*/

                ans = ans_temp;
                pp = temp.step;
                //cout <<"ans = "<<ans<<" pp = "<<pp<<endl;
            }
        }
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int ttt;
    scanf("%d", &ttt);

    mmm maps;

    while(ttt--){
        for(int i = 0;i < 5;i++){
            scanf(" %s", maps.mm[i]);
        }

        ans = 10;
        pp = 1000000;
        maps.step = 0;
        aqueue.push(maps);
        poi temp = maps.check(poi(0,0));
        temp = poi(0,0);

        do{
            mmm m = aqueue.front();
            aqueue.pop();
            //cout <<"size = "<<aqueue.size()<<endl;
            if(m.check(poi(0, 0)).i == -1){
                int a = m.find_ans();

                if(a < ans){
                    ans = a;
                    pp = m.step;
                }
                continue;
            }

            temp = poi(0,0);
            //cout <<"a = "<<m.find_ans()<<endl;
            //cout <<"find\n";
            do{
                temp = m.check(temp);
                //cout <<"i = "<<temp.i<<" j = "<<temp.j<<endl;
                if(temp.i == -1)
                    break;

                mmm tp = m;
                if(tp.jump(0, temp)){
                    //cout <<"down\n";
                    tp.step++;
                    aqueue.push(tp);
                }

                tp = m;
                if(tp.jump(1, temp)){
                    //cout <<"left\n";
                    tp.step++;
                    aqueue.push(tp);
                }

                tp = m;
                if(tp.jump(2, temp)){
                    //cout <<"up\n";
                    tp.step++;
                    aqueue.push(tp);
                }

                tp = m;
                if(tp.jump(3, temp)){
                    //cout <<"right\n";
                    tp.step++;
                    aqueue.push(tp);
                }
            }while(true);

        }while(aqueue.size() != 0);

        /*
        if(temp.i == -1){
            if(ans > maps.find_ans()){
                //cout <<"!!\n";
                ans = maps.find_ans();
                pp = 0;
            }
        }

        while(temp.i != -1){
            //cout <<"i = "<<temp.i<<" j = "<<temp.j<<endl;
            BFS(maps, temp);
            temp = maps.check(temp);
        }*/

        printf("%d %d\n", ans, pp);
        //cout <<"ans = "<<ans<<" step = "<<pp<<endl;
    }

    return 0;
}
