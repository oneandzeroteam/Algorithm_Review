#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<bool> > matrix;
vector<string> dictionary;
vector<int> result;
vector<bool> visited;
void createGraph(vector<string>);
void topoSort();
void dfs(int);
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
        topoSort();
    }
    /* graph matrix check (print)
    cout<<"   ";
    for(int a=0;a<26;a++){
        temp=a+97;
        cout<<temp<<" ";
    }
    cout<<endl;
    for(int a=0;a<26;a++){
        temp=a+97;
        cout<<temp<<" ";
        for(int b=0;b<26;b++){
            cout<<matrix[a][b]<<" ";
        }
        cout<<endl;
    }
    */

    return 0;
}
void createGraph(vector<string> dictionary){
    int length;
    matrix=vector<vector<bool> >(26,vector<bool>(26,false));
    //create matrix based on dictionary
    for(int i=0;i<dictionary.size()-1;i++){
        length=min(dictionary[i].size(),dictionary[i+1].size());
        for(int j=0;j<length;j++){
            if(dictionary[i].at(j) != dictionary[i+1].at(j)){
                matrix[dictionary[i].at(j)-97][dictionary[i+1].at(j)-97]=true;
                break;
            }
        }
    }
}
void topoSort(){
    char temp;
    visited=vector<bool>(26,false);
    result.clear();
    //sorting the matrix using dfs
    for(int i=0;i<26;i++){
        if(!visited[i])
            dfs(i);
    }
    reverse(result.begin(),result.end());

    //DAG checking
    for(int i=0;i<26;i++){
        for(int j=i+1;j<26;j++){
            if(matrix[result[j]][result[i]]){
                    cout<<"INVALID HYPOTHESIS"<<endl;
            return;
            }
        }
    }
    for(int i=0;i<result.size();i++){
        temp=result[i]+97;
        cout<<temp;
    }
    cout<<endl;
}
void dfs(int i){

    visited[i]=true;

    for(int j=0;j<26;j++){
        if(matrix[i][j]&&!visited[j])
            dfs(j);
    }
    result.push_back(i);
}
