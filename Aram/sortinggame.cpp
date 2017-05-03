#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

map < vector<int>, int > toSort;

int bfs(const vector<int>& input);
void precalc(int n);
int solve(const vector<int>& input);

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int len;
		cin >> len;
		vector<int> input(len);

		for (int i = 0; i < len; ++i) {
			cin >> input[i];
		}

//		len = bfs(input);
//		if (len < 0)
//			cout << "Failure" << endl;
//		else
//			cout << len << endl;

		precalc(len);
		len = solve(input);
		if (len < 0)
			cout << "Failure" << endl;
		else
			cout << len << endl;


	}

}

int bfs(const vector<int>& input) {
	vector<int> answer = input;
	int len = input.size();
	sort(answer.begin(), answer.end());
	queue<vector<int>> q;
	map<vector<int>, int> distance;

	distance[input] = 0;
	q.push(input);
	while (!q.empty()) {
		vector<int> here = q.front();
		q.pop();

		if (here == answer)
			return distance[here];

		int cost = distance[here];

		for (int i = 0; i < len; ++i) {
			for (int j = i + 1; j <= len; ++j) {
				reverse(here.begin() + i, here.begin() + j);
				if (distance.count(here) == 0) {
					distance[here] = cost + 1;
					q.push(here);
				}
				reverse(here.begin() + i, here.begin() + j);
			}
		}
	}
	return -1;
}

void precalc(int n) {
	vector<int> perm(n);
	for (int i = 0; i < n; ++i)
		perm[i] = i;
	queue<vector<int>> q;
	q.push(perm);
	toSort[perm] = 0;
	int iteration = 0;
	while (!q.empty()) {
		vector<int> here = q.front();
		q.pop();
		
		int cost = toSort[here];

		for (int i = 0; i < n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				reverse(here.begin() + i, here.begin() + j);
				if (toSort.count(here) == 0) {
					toSort[here] = cost + 1;
					q.push(here);
				}
				cout << "iteration = " << iteration << endl;
				++iteration;
				reverse(here.begin() + i, here.begin() + j);
			}
		}
	}
}

int solve(const vector<int>& input) {
	int n = input.size();
	vector<int> fixed(n);
	for (int i = 0; i < n; ++i) {
		int smaller = 0;
		for (int j = 0; j < n; ++j)
			if (input[j] < input[i])
				++smaller;
		fixed[i] = smaller;
	}
	return toSort[fixed];
}
