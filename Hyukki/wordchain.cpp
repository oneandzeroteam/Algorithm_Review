#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > matrix;
vector<string> graph[26][26];
vector<string> dictionary;
vector<int> in,out;

void wordChain();
void createGraph(vector<string>);
void getEulerCircuit(int , vector<int>&);
vector<int> getEulerTrailOrCircuit();
bool checkEuler();

int main()
{
    int n,k;
    string input;
    char temp;
    cin >> k;
    for(int i=0;i<k;i++){
        dictionary.clear();
        cin>>n;
        while(n--){
            cin>>input;
            dictionary.push_back(input);
        }
        createGraph(dictionary);
        wordChain();
    }
    return 0;
}
void createGraph(vector<string> dictionary){
    //graph and matrix initialization
    matrix=vector<vector<int> >(26,vector<int>(26,0));
    for(int i=0;i<26;i++)
        for(int j=0;j<26;j++)
            graph[i][j].clear();

    in=vector<int>(26, 0);
    out=vector<int>(26, 0);
    for(int i = 0; i < dictionary.size(); ++i){
        int a=dictionary[i][0] - 97;
        int b=dictionary[i][dictionary[i].size() - 1] - 97;
        graph[a][b].push_back(dictionary[i]);
        matrix[a][b]++;
        out[a]++;
        in[b]++;
     }

}
void wordChain(){
    if(!checkEuler()){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    vector<int> circuit=getEulerTrailOrCircuit();
    if(circuit.size()!=dictionary.size()+1){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    reverse(circuit.begin(), circuit.end());
         string result;
         for (int i = 1; i < circuit.size(); ++i){
                  int a = circuit[i - 1], b = circuit[i];
                  if (result.size()) result += " ";
                  result += graph[a][b].back();
                  graph[a][b].pop_back();
         }
    cout<<result<<endl;
}


void getEulerCircuit(int u, vector<int>& circuit){
         for (int v = 0; v < matrix.size(); ++v){
                  while (matrix[u][v]>0){
                           matrix[u][v]--;
                           getEulerCircuit(v, circuit);
                  }
         }
         circuit.push_back(u);
}
vector<int> getEulerTrailOrCircuit(){
         vector<int> circuit;
         for (int i = 0; i < 26; ++i){
                  if (out[i] == in[i] + 1){
                           getEulerCircuit(i, circuit);
                           return circuit;
                  }
         }

         for (int i = 0; i < 26; ++i){
                  if (out[i]){
                           getEulerCircuit(i,circuit);
                           return circuit;
                  }
         }

         return circuit;
}
bool checkEuler(){
         int plus1 = 0, minus1 = 0;
         for (int i = 0; i < 26; ++i){
                  int delta = out[i] - in[i];
                  if (delta < -1 || delta > 1) return false;
                  if (delta == 1) plus1++;
                  if (delta == -1) minus1++;
         }
         return (plus1 == 1 && minus1 == 1) || (plus1==0 && minus1==0);
}

