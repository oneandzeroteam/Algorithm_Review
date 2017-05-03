//시간초과
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>

using namespace std;

string stringRepr(const vector<int>& v){
    vector<int> original= v, sorted = v;

    sort(sorted.begin(), sorted.end());

    string ret;
    for(int i =0; i<original.size(); ++i){
        for(int j=0; j<original.size(); ++j){
            if(sorted[j] == original[i]) {
                ret += char(j + '0');
                break;
            }
        }
    }

    return ret;

}

int bfs(const vector<int>& _v){

    int n = _v.size();

    string v = stringRepr(_v);
    string sorted = v;

    sort(sorted.begin(), sorted.end());

    queue<string> q;
    map<string,int> distance;

    distance[v] = 0;

    q.push(v);
    while(!q.empty()){
        string here = q.front();
        q.pop();

        if(here == sorted) return distance[here];
        int cost = distance[here];

        for(int i =0; i<n; ++i){
            for(int j =i+2; j<=n; ++j){
                reverse(here.begin()+i, here.begin()+j);

                if(distance.count(here) == 0){
                    distance[here] = cost+1;
                    q.push(here);
                }

                reverse(here.begin()+i, here.begin()+j);
            }
        }

    }
    return -1;
}

int main() {

    int testcase;
    cin >> testcase;

    while(testcase--){
        int n;
        cin >> n;
        vector<int> input(n);
        for(int i =0; i<n; ++i){
            cin >> input[i];
        }

        int ret = bfs(input);

        cout << ret << endl;
    }

}
