#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> makeGraph(const vector<string> &words);
void dfs(const vector<vector<int>> &adj, vector<int> &seen, vector<int> &order, int here);
vector<int> topologicalSort(const vector<vector<int>> &adj);

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int wordsnum;
		cin >> wordsnum;
		vector<vector<int>> adj;
		vector<string> words(wordsnum);

		for (int i = 0; i < wordsnum; i++) {
			cin >> words[i];
		}

		adj = makeGraph(words);


		vector<int> order = topologicalSort(adj);

		if (order.empty())
			cout << "INVALID HYPOTHESIS" << endl;

		else {
			for (int i = 0; i < 26; ++i) {
				cout << (char)(order[i] + 'a');
			}
			cout << endl;
		}

	}
}

vector<vector<int>> makeGraph(const vector<string> &words) {
	vector<vector<int>> adj = vector<vector<int>>(26, vector<int>(26, 0));
	for (int j = 1; j < words.size(); ++j) {
		int i = j - 1;
		int len = min(words[i].size(), words[j].size());
		for (int k = 0; k < len; ++k)
			if (words[i][k] != words[j][k]) {
				adj[words[i][k] - 'a'][words[j][k] - 'a'] = 1;
				break;
			}
	}
	return adj;
}

void dfs(const vector<vector<int>> &adj, vector<int> &seen, vector<int> &order, int here) {
	seen[here] = 1;
	for (int there = 0; there < adj.size(); ++there)
		if (adj[here][there] && !seen[there])
			dfs(adj, seen, order, there);
	order.push_back(here);
}

vector<int> topologicalSort(const vector<vector<int>> &adj) {
	int n = adj.size();
	vector<int> seen = vector<int>(n, 0);
	vector<int> order;
	for (int i = 0; i < n; ++i)
		if (!seen[i])
			dfs(adj, seen, order, i);
	reverse(order.begin(), order.end());

	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (adj[order[j]][order[i]])
				return vector<int>();
	return order;
}
