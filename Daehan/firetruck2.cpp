#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>

using namespace std;

const int INF = 30000;
vector<vector<pair<int,int>>> adj;
int v,e,n,m;

void link(int from, int to, int weight) {
    adj[from].push_back(make_pair(weight,to));
    adj[to].push_back(make_pair(weight,from));
}

vector<int> shortestDist(int start){

    vector<int> dist(v+1,INF);
    priority_queue<pair<int,int>> pq;

    dist[start] = 0;
    pq.push(make_pair(0,start));

    while(!pq.empty()){

        int here = pq.top().second;
        int cost = -pq.top().first;

        pq.pop();

        //dist[here]이 업데이트 되었다면 이 pair를 무시한다.
        if(cost > dist[here]) continue;


        for(int i =0; i<adj[here].size(); ++i){
            int there = adj[here][i].second;
            int nextDist = adj[here][i].first + cost;
            if(nextDist < dist[there]){
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist,there));
            }

        }
    }
    return dist;
}


int main() {

    int C;
    cin >> C;
    while(C--){


        cin >> v >> e >> n >> m;
        vector<vector<pair<int,int>>> _adj(v+1);
        adj = _adj;

        vector<int> station(m), fire(n);


        for(int i =0; i< e; ++i){
            int a,b,c;
            cin >> a >> b >> c;
            link(a,b,c);
        }

        for(int i =0; i<n; ++i) {
            cin >> fire[i];
//            fire[i]--;
        }

        for(int i =0; i<m; ++i) {
            cin >> station[i];
//            station[i]--;
        }

        //station끼리는 가중치 0인 간선을 연결해 준다. 다익스트라 알고리즘 한번만 실행해도 됨.
        for(int i=0; i<m; ++i) {
            int here = station[i];
            for (int j = i + 1; j < m; ++j) {
                int there = station[j];
                link(here,there,0);
            }
        }


        vector<vector<int>> dist_from_stations;

        //1번째 스테이션에서 시작하는 경로만 그려준다.
        int first_station = station[0];
        vector<int> minDist = shortestDist(first_station);


        int ret =0;
        for(int i=0; i<n; ++i){
            int here = fire[i];
            ret += minDist[here];
        }

        cout << ret << endl;

    }

}
