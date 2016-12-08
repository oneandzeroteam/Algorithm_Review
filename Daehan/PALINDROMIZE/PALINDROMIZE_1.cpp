#include<iostream>
#include<vector>
#include<string>

using namespace std;

string reverse(const string S) {
	string rev(S);
	unsigned m = rev.size();
	//rev.reserve(m);
	for (unsigned i = 0; i < m; ++i) {
		rev[m - i - 1] = S[i];
	}
	return rev;
}

int getPalindromeMatch(const string& N) {
	unsigned m = N.size();
	string rev = reverse(N);

	int begin = 0, matched = 0, smallest = 0;
	while (begin + matched < m) {
		if (N[begin + matched] == rev[matched]) {
			++matched;
		}
		else{
			++smallest; // matching failed.
			++begin;
			matched=0;
		}
	}
	return smallest;

}

int main() {
	
	int C;
	cin >> C;
	for (int i = 0; i < C; ++i) {
		string S;
		cin >> S;
		cout << S.size() + getPalindromeMatch(S) << endl;
	}
}