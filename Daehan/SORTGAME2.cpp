#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <map>

using namespace std;

map<string,int> dist;

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

void precalc(int n){

    string answer;
    for(char i=0; i<n; ++i)
        answer += i+'0';

    queue<string> q;

    dist[answer] = 0;
    q.push(answer);

    while(!q.empty()){
        string here = q.front();
        q.pop();

        int cost = dist[here];

        for(int i =0; i<n; ++i){
            for(int j =i+2; j<=n; ++j){
                reverse(here.begin()+i, here.begin()+j);

                if(dist.count(here) == 0){
                    dist[here] = cost+1;
                    q.push(here);
                }

                reverse(here.begin()+i, here.begin()+j);
            }
        }
    }
}

int main() {

    int testcase;
    cin >> testcase;

    //맵을 미리 다 만들어둠
    for(int i =1; i<=8; ++i) precalc(i);


    while(testcase--){
        int n;
        cin >> n;
        vector<int> input(n);
        for(int i =0; i<n; ++i){
            cin >> input[i];
        }

        string rep = stringRepr(input);
        cout << dist[rep] << endl;

    }

}
