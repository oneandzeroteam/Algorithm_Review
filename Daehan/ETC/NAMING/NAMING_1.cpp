#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> findLength(const string& N) {
	vector<int> ret ;
	ret.push_back(N.size());
	for (unsigned begin = 1; begin < N.size(); ++begin) {
		bool matched = true;
		for (unsigned i = 0; i + begin < N.size(); ++i) {
			if (N[i] != N[begin + i]) { matched = false; break; }
		}
		if (matched) ret.push_back(N.size()-begin);
	}

	return ret;
}

int main() {
	string f, m;
	cin >> f >> m;
	vector<int> length = findLength(f + m);
	sort(length.begin(), length.end());

	for (unsigned i = 0; i < length.size(); ++i) {
		cout << length[i] << " ";
	}
	cout << endl;
}