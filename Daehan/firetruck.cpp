#include <iostream>
#include <vector>
#include <queue>

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
        }

        for(int i =0; i<m; ++i) {
            cin >> station[i];
        }

        vector<vector<int>> dist_from_stations;

        //i번째 스테이션에서 시작하는 경로를 모두 그려준다.
        for(int i=0; i<m; ++i){
            int here = station[i];
            dist_from_stations.push_back(shortestDist(here));
        }


        int ret =0;
        for(int i=0; i<n; ++i){
            int closest = INF;
            int here = fire[i];
            for(int j=0; j<m; ++j){
             // m번째 station에서 here에 가는 거리가 가장 가까우면 갱신.
                closest = min(closest, dist_from_stations[j][here]);
            }
            ret += closest;
        }

        cout << ret << endl;

    }

}
