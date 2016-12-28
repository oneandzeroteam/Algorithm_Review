#include<iostream>
#include<vector>
#include<string>
using namespace std;

//TIMEOVER....

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() -1, 0);
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < b.size(); ++j)
			c[i + j] += a[i] * b[j];
	return c;
}

void reverse(vector<int>& a) {
	unsigned n = a.size();
	unsigned m = n;
	vector<int> b(m);
	while (m--) {
		b[n - m - 1] = a[m];
	}
	a = b;
}

void main() {
	
	int C;
	cin >> C;

	while (C--) {
		
		string fan, member;
		cin >> member >> fan;
		unsigned fan_size = fan.size();
		unsigned member_size = member.size();
		vector<int> fan_v(fan_size,0), member_v(member_size,0);
		
		// converting fan string and member string into corresponding vectors : 'M' -> 1 'F' -> 0 and orders are reversed
		for (unsigned i = 0; i < fan_size; ++i)
			if (fan[i] == 'M') fan_v[fan_size-i-1] = 1;

		for (unsigned i = 0; i < member.size(); ++i)
			if (member[i] == 'M') member_v[member_size-i-1] = 1;

		// reversing member vector.
		reverse(member_v);

		vector<int> result = multiply(fan_v, member_v);
		unsigned result_size = result.size();
		int cnt = 0;

		for (unsigned i = member_size - 1; i <= result_size - member_size; ++i) 
			if (result[i] != 0) ++cnt;
		
		unsigned sol = fan_size - member_size + 1 - cnt;

		cout << sol << endl;
	}
}