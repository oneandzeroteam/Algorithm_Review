#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

vector<int> getPartialMatch(const string& N) {
	unsigned m = N.size();
	vector<int> pi(m, 0);
	int begin = 1, matched = 0;
	
	while (begin + matched < m) {
		if (N[begin + matched] == N[matched]) {
			++matched;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				++begin;
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> getLength(const string& N) {
	vector<int> ret;
	ret.push_back(N.size());
	vector<int> pi = getPartialMatch(N);
	unsigned k = pi[N.size() - 1];
	if (k>0) ret.push_back(k);
	while (k > 0) {
		k = pi[k - 1];
		if (k <= 0) break;
		ret.push_back(k);
	}

	return ret;
}


int main() {
	string f, m;
	cin >> f >> m;

	//	vector<int> pi = getPartialMatchNaive(f + m);
	//	for (unsigned i = 0; i < (f + m).size(); ++i)
	//		cout << pi[i] << " ";
	//	cout << endl;

	vector<int> length = getLength(f + m);
	sort(length.begin(), length.end());
	for (unsigned i = 0; i < length.size(); ++i)
		cout << length[i] << " ";


}