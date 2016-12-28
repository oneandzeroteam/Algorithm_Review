#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

//TIMEOVER...

void normalize(vector<int>& num) {
	unsigned m = num.size();
	num.push_back(0);
	for (int i = 0; i < m; ++i) {
		if (num[i] < 0) {
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;
			//			cout << "if\n";
		}
		else {
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
			//			cout << "else\n";
		}
	}
	while (num.size()>1 && num.back() == 0) {
		num.pop_back();
		//	cout << "poped 0\n";
	}
}

vector<int> multiply(const vector<int>& a, const vector<int>& b) {
	vector<int> c(a.size() + b.size() - 1, 0);
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < b.size(); ++j)
			c[i + j] += a[i] * b[j];
//	normalize(c);
	return c;
}

void addTo(vector<int>& a, const vector<int>& b, int k) { // 10^k만큼 b에 곱한 값을 a에 곱한다.
	unsigned m = a.size();
	unsigned n = b.size();

	if (a.size() < k) {

		for (unsigned i = 0; i < k - m; ++i)
			a.push_back(0);
		for (unsigned i = 0; i < n; ++i)
			a.push_back(b[i]);
	}
	else {
		for (unsigned i = 0; i < min(m - k, n); ++i) {
			a[i + k] += b[i];
		}
		if (m < n + k)
			for (unsigned i = m - k; i < n; ++i)
				a.push_back(b[i]);
	}
}
void subFrom(vector<int>& a, const vector<int>& b) { // b.size() < a.size()라고 가정.
	for (unsigned i = 0; i < b.size(); ++i) {
		a[i] -= b[i];
	}
}

vector<int> karatsuba(const vector<int>& a, const vector<int>& b) {

	int an = a.size(), bn = b.size();

	if (an < bn) return karatsuba(b, a);

	if (an == 0 || bn == 0) return vector<int>();

	if (an <= 50) return multiply(a, b);
	int half = an / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	vector<int> z2 = karatsuba(a1, b1);

	vector<int> z0 = karatsuba(a0, b0);

	addTo(a0, a1, 0); addTo(b0, b1, 0);

	vector<int> z1 = karatsuba(a0, b0);

	subFrom(z1, z0);
	subFrom(z1, z2);


	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
//	normalize(ret);
	return ret;
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


int main() {


	int C;
	cin >> C;

	while (C--) {

		string fan, member;
		cin >> member >> fan;
		unsigned fan_size = fan.size();
		unsigned member_size = member.size();
		vector<int> fan_v(fan_size, 0), member_v(member_size, 0);

		// converting fan string and member string into corresponding vectors : 'M' -> 1 'F' -> 0 and orders are reversed
		for (unsigned i = 0; i < fan_size; ++i)
			if (fan[i] == 'M') fan_v[fan_size - i - 1] = 1;

		for (unsigned i = 0; i < member.size(); ++i)
			if (member[i] == 'M') member_v[member_size - i - 1] = 1;

		// reversing member vector.
		reverse(member_v);

		vector<int> result = karatsuba(fan_v, member_v);
		unsigned result_size = result.size();
		int cnt = 0;

		for (unsigned i = member_size - 1; i <= result_size - member_size; ++i)
			if (result[i] != 0) ++cnt;

		unsigned sol = fan_size - member_size + 1 - cnt;

		cout << sol << endl;
	}
}