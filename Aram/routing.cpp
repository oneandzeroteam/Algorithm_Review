#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <limits>

using namespace std;

const double INF = 1e7;
vector<pair<int, double>> adj[10000];
int n, m;
vector<double> dijkstra(int src);

int main() {
	int testcase;
	cin >> testcase;

	while (testcase--) {
		cin >> n >> m;

		int a, b;
		double c;

		while (m--) {
			scanf("%d %d %f", &a, &b, &c);
			adj[a].push_back(make_pair(b, c));
			adj[b].push_back(make_pair(a, c));
		}
		vector<double> dist = dijkstra(0);

		double cost = exp(dist[n - 1]);
		printf("%.10lf\n", cost);

	}
	return 0;
}

vector<double> dijkstra(int src) {
	vector<double> dist(n, INF);
	dist[src] = 0;
	priority_queue <pair<int, double>>pq;
	pq.push(make_pair(src,0));

	while (!pq.empty()) {
		int here = pq.top().first;
		double cost = -pq.top().second;
		pq.pop();

		if (dist[here] < cost) continue;

		for (int i = 0; i < adj[here].size(); ++i) {
			int there = adj[here][i].first;
			int nextDist = cost + log(adj[here][i].second);

			if (dist[there] > nextDist) {
				dist[there] = nextDist;
				pq.push(make_pair(there, -nextDist));
			}
		}
	}
	return dist;
}

