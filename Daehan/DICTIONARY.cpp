#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> visited(26,0);
vector<vector<int>> adj;
vector<int> order;

template<typename T>
void print(const vector<T>& v){
    for(int i=0; i<v.size(); ++i){
        cout << v[i];
    }
    cout << endl;
}

void makeGraph(const vector<string>& words){
    vector<vector<int>> temp(26, vector<int>(26,0));
    adj = temp;

    for(int j= 1 ; j<words.size(); ++j){

        int i = j-1;
        int len = min(words[i].size(), words[j].size());

        for(int k=0; k<len; ++k){

            if(words[i][k] != words[j][k]){
                int a = words[i][k] - 'a';
                int b = words[j][k] - 'a';

                adj[a][b] = 1;
                break;
            }

        }

    }
}

void dfs(int here){
    visited[here] = 1;
    for(int there =0; there<26; ++there){
        if(adj[here][there] && !visited[there])
            dfs(there);
    }
    order.push_back(here);
}


vector<int> topologicalSort(){
    int n = adj.size();
    visited = vector<int>(n,0);

    order.clear();

    for(int i =0; i<n; ++i){
        if(!visited[i])
            dfs(i);
    }
    reverse(order.begin(),order.end());


    for(int i=0; i<n; ++i){
        for(int j= i+1; j<n; ++j){
            if(adj[order[j]][order[i]])
                return vector<int>();
        }
    }

    return order;
}

int main() {

    int T;
    cin >> T;
    while (T--) {


        int numcase;
        cin >> numcase;
        vector<string> words(numcase);

        for (int i = 0; i < numcase; ++i)
            cin >> words[i];

        makeGraph(words);

        order =topologicalSort();

        vector<char> order2(26);
        copy(order.begin(), order.end(),order2.begin());

        if(!order.empty()) {
            for (int i = 0; i < order2.size(); ++i) order2[i] += 'a';
            print(order2);
        }
        else
            cout << "INVALID HYPOTHESIS" << endl;
    }

}
