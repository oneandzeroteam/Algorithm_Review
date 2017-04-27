#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>

using namespace std;

vector<vector<int>>adj;
vector<int> indegree, outdegree;
vector<string> words;
vector<string> graph[26][26];

template<typename T>
void print(T v){
    for( int i =0 ; i<v.size(); ++i)
        cout << v[i] << " ";
    cout << endl;
}

//그래프를 만든다.
void makeGraph(){

    for(string& str: words){
        int start = str[0]-'a';
        int end = str[str.size()-1]-'a';
        adj[start][end]++;
        indegree[end]++;
        outdegree[start]++;
        graph[start][end].push_back(str);
    }

}

//오일러 서킷이나 트레일이 존재할 수 있는지 체크한다.
bool checkEuler(){
    int plus1 =0, minus1=0;
    for(int i =0; i<26; ++i){
        int delta = outdegree[i]- indegree[i];
        if(delta < -1 || 1 < delta) {assert(true); return false;}
        if(delta == 1) plus1++;
        if(delta == -1) minus1++;
    }
    return (plus1 == 1 && minus1 ==1) || (plus1 ==0 && minus1 ==0);
}

void getEulerCircuit(int here, vector<int>& circuit){
    for(int there =0; there < adj.size(); ++there){
        while(adj[here][there]>0){
            adj[here][there]--;
            getEulerCircuit(there,circuit);
        }
    }
    circuit.push_back(here);
}

//오일러 train이나 circuit이 있는지 찾는다.
vector<int> getEulerTrailOrCircuit(){

    vector<int> circuit;

    for(int i =0; i<26; ++i){
        if(outdegree[i] == indegree[i]+1){
            getEulerCircuit(i, circuit);
            return circuit;
        }
    }

    for(int i =0; i<26; ++i){
        if(outdegree[i]){
            getEulerCircuit(i,circuit);
            return circuit;
        }
    }

    return circuit;

}



int main() {
    int T;
    cin >> T;
    while(T--){

        int num_words;
        cin >> num_words;

        //인접 행렬, 단어 초기화, indeg, outdeg 초기화.
        vector<vector<int>> _adj(26,vector<int>(26,0));
        vector<string> _words(num_words);
        adj = _adj; words = _words;
        indegree = vector<int>(26,0);
        outdegree = vector<int>(26,0);

        for(int i =0; i<num_words; ++i){
            cin >> words[i];
        }


        //인접행렬 만들기.
        makeGraph();

        //오일러 경로가 존재할 수 없다면 끝.
        if(!checkEuler()) {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        vector<int> circuit;
        circuit = getEulerTrailOrCircuit();


        //모든 간선을 다 방문하지 않았다면 끝. 이런 경우는 컴포넌트가 2개 이상.
        if(circuit.size() != words.size() +1){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        //circuit을 이용해서 단어 순서 반환.
        reverse(circuit.begin(), circuit.end());

        string ret;
        for(int i =1; i<circuit.size(); ++i){
            int a = circuit[i-1], b = circuit[i];
            if(ret.size()) ret += " ";
            ret += graph[a][b].back();
            graph[a][b].pop_back();
        }

        cout << ret << endl;

        for(int i =0 ; i < 26; ++i)
            for(int j =0 ; j<26; ++j)
                graph[i][j].clear();

    }

    return 0;
}
