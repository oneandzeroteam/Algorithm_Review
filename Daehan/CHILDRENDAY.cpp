#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 0~2n-1사이의 노드를 반환한다. 만들어진 값이 n보다 클 경우를 다뤄줌.
int append(int here, int edge, int mod){
    int there = here * 10 + edge;
    if(there >= mod ) return mod + there % mod;
    return there % mod;
}

string gifts(string digits, int n, int m){

    sort(digits.begin(), digits.end());

    vector<int> parent(2*n, -1), choice(2*n, -1);
    queue<int> q;

    //0이 루트 노드가 된다
    parent[0] = 0;
    q.push(0);
    while(!q.empty()){
        int here = q.front();
        q.pop();

        for(int i =0; i<digits.size(); ++i){
            int there = append(here, digits[i] - '0', n);
            if(parent[there] == -1){
                parent[there] = here;
                //there에 오기 위해 선택한 edge를 choice[there]에 저장.
                choice[there] = digits[i] - '0';
                q.push(there);
            }
        }
    }

    // 만들어진 숫자가 n이상이면서 나머지가 m인 경우가 존재하지 않는다면
    if(parent[n+m] == -1) return "IMPOSSIBLE";

    string ret;
    int here = n+m;
    while(parent[here] != here){
        ret += char('0' + choice[here]);
        here = parent[here];
    }
    reverse(ret.begin(), ret.end());
    return ret;

}


int main() {
    int testcase;
    cin >> testcase;
    while(testcase--){

        int n, m;
        string digits;
        cin >> digits >> n >> m;

        cout << gifts(digits, n, m) << endl;

    }
}
