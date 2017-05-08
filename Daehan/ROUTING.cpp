#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

int n;
int m;
const double INF=1e5;
// (연결된 노드 번호, 가중치)를 담는 인접 리스트 표현.
vector<vector<pair<double,int>>> adj;

//from과 to는 weight의 edge로 연결되어있다.
void link(int from, int to, double weight){
    adj[from].push_back(make_pair(weight,to));
    adj[to].push_back(make_pair(weight,from));
}

vector<double> shortestDist(int start){

    vector<double> dist(n, INF);
    dist[start] = .0;
    priority_queue<pair<double,int>> pq;

    pq.push(make_pair(.0,start));

//    for(int i=0; i<adj[0].size(); ++i){
//        int there = adj[0][i].second;
//        dist[there] = log(adj[0][i].first);
//    }

    while(!pq.empty()){
        double cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        //지금 뽑은 pair가 바뀌기 전의 것이므로 버린다.
        if(dist[here] < cost) continue;

        for(int i =0; i<adj[here].size(); ++i){
            int there = adj[here][i].second;
            double nextDist = cost + log(adj[here][i].first);
            if(dist[there] > nextDist){
                dist[there] = nextDist;
                pq.push(make_pair(-nextDist, there));
            }
        }
    }
    return dist;
}

int main() {
    int t;
    cin >> t;

    while(t--){
        cin >> n >> m;

        // adj 초기화.
        vector<vector<pair<double,int>>> _adj(n,vector<pair<double,int>>());
        adj = _adj;

        //그래프 생성.
        for(int i =0; i<m; ++i){
            int a,b;
            double c;
            cin >> a >> b >> c;
            link(a,b,c);
        }

        vector<double> answer = shortestDist(0);

        double ans = exp(answer[n-1]);
        printf("%.10lf\n",ans);
    }
}
