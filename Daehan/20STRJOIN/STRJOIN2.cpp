#include<iostream>
#include<queue>
#include<vector>
#include<functional>

using namespace std;

int solve(const vector<int>& v) {
	int ret = 0;

	priority_queue<int, vector<int>,greater<int>> pq;

	for (int i = 0; i < v.size(); ++i)
		pq.push(v[i]);

	while (pq.size() > 1) {

		int min1 = pq.top(); pq.pop();
		int min2 = pq.top(); pq.pop();

		ret += min1 + min2;
		pq.push(min1 + min2);

	}

	return ret;
}

int main() {

	int case_num; cin >> case_num;

	while (case_num--) {
		int num_str; cin >> num_str;

		vector<int> str_len;

		while (num_str--) {
			int temp; cin >> temp; str_len.push_back(temp);
		}

		cout << solve(str_len) << endl;

	}

}