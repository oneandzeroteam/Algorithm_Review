#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector< vector<int> > adj;
int cnt_global=0;

template<typename T>
void print(T v){
    for(int i =0; i<v.size(); ++i){
        cout << v[i]<< " ";
    }
    cout << endl;
}

void getEulerCircuit(int here, vector<int>& circuit){
    int nowheretogo=adj.size();
    for(int i=0; i<adj.size(); ++i)
        if (adj[i][here] > 0) {
            adj[i][here]=0;
            for (int j = 0; j < adj.size(); ++j)
                print(adj[j]);
            cout << endl;
        }
    for(int there=0; there<adj.size(); ++there){
        cout << "here :" <<here<<" | there :"<<there<<endl;
        if(adj[here][there]>0){
            nowheretogo--;
            cout <<"nowheretogo is " << nowheretogo<<endl;
            adj[here][there]=0;
            for(int j =0; j<adj.size(); ++j)
                print(adj[j]);
            cout <<endl;
            getEulerCircuit(there,circuit);
                }

        }
    //isolated node가 있으면 cnt에 기록한다.
    if(nowheretogo==adj.size()) {
        cnt_global++;
        cout << "cnt_global is now "<<cnt_global<<endl;
    }
    //나가는 길이 없는 노드가 2개 이상이면 종료한다.
    if(cnt_global>1)
        return;
    cout << here << "ends now" << endl;
    circuit.push_back(here);
}

void makeGraph(const vector<string>& words){

    for(int i =0; i<words.size(); ++i){
        for(int j =0; j<words.size() ; ++j){

            if(j==i) continue;

            const char& lch=words[i][words[i].size()-1];
            const char& fch=words[j][0];

            if(fch == lch){
                adj[i][j]=1;
            }
        }
    }



}



int main() {

    int C;
    cin >> C;
    while(C--){

        int n;
        cin >> n;

        vector<vector<int>> temp(n,vector<int>(n,0));
        adj = temp;

        vector<string> words(n);
        for(int i=0; i<n; ++i)
            cin >> words[i];

        for(int i =0; i<n; ++i)
            print(words[i]);
        cout << endl;
//        make graph
        makeGraph(words);


        for(int i =0; i<n; ++i)
            print(adj[i]);
        cout << endl;
        vector<int> circuit;

        int cnt=0;
        for(int i =0; i < n; ++i){
            if(adj[i] == vector<int>(n,0))
                cnt++;
        }
        //나가는 길이 없는 노드가 2개 이상이면 불가능.
        if(cnt>1)
            cout<<"IMPOSSIBLE"<<endl;
        else {

            getEulerCircuit(0, circuit);

//            나가는 길이 없는 노드가 2개 이상이면 불가능.
            if(cnt_global>2)
                cout<<"IMPOSSIBLE"<<endl;


            for (int i = 0; i < n; ++i)
                print(adj[i]);
            cout << endl;

            reverse(circuit.begin(), circuit.end());

            cout << endl;
            print(circuit);
            cout << endl;


            if (circuit.size() < n)
                cout << "IMPOSSIBLE" << endl;
            else {
                for (int i = 0; i < circuit.size(); ++i) {
                    int &it = circuit[i];
                    cout << words[it] << " ";
                }
                cout << endl;
            }
        }

        adj.clear();
        cnt_global=0;
    }



}
