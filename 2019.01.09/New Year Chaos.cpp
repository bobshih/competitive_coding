#include <bits/stdc++.h>
#include <string> 

using namespace std;

vector<string> split_string(string);

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    int counts = 0;
    vector<int> temp;
    for(int i = 0; i < q.size();i++){
        temp.push_back(i+1);
    }

    for(int i = 0;i < q.size();i++){
        int diff = -1;
        if(temp[i+1] == q[i]){
            diff = 1;
        }else if(temp[i+2] == q[i]){
            diff = 2;
        }
        int steps = q[i]-i-1;
        if(steps > 2){
            cout<<"Too chaotic"<<endl;
            return;
        }else{
            int a, b, c;
            if(diff == 2){
                counts += diff;
                a = temp[i];
                b = temp[i+1];
                c = temp[i+2];
                temp[i] = c;
                temp[i+1] = a;
                temp[i+2] = b;
            }else if(diff == 1){
                counts += diff;
                a = temp[i];
                b = temp[i+1];
                temp[i] = b;
                temp[i+1] = a;
            }
        }
        // cout <<"diff = "<<diff<<" step "<<i;
        // for(int j = 0;j < q.size();j++){
        //     cout <<" "<<temp[j];
        // }cout<<endl;
    }
    cout<<counts<<endl;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}

