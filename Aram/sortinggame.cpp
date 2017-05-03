#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

map < vector<int>, int > toSort;
void precalc(int n);
int solve(const vector<int>& input);

int main() {
	int testcase;
	cin >> testcase;

	for (int i = 1; i <= 8; i++) {
		precalc(i);
	}
	while (testcase--) {
		int len;
		cin >> len;
		vector<int> input(len);

		for (int i = 0; i < len; ++i) {
			cin >> input[i];
		}
		cout << solve(input) << endl;
	}
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
