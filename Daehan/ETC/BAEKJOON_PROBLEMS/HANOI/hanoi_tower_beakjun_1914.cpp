#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

//이 프로그램은 n<107 까지만 작동합니다.
// n<=20 일 경우 옮기는 과정을 출력하고,
// n이 그 이상일 경우 경우의 수만 출력합니다. 

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
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < b.size(); ++j)
			c[i + j] += a[i] * b[j];
	normalize(c);
	return c;
}

vector<int> valueToVector(unsigned long long value) {
	vector<int> ret;
	do {
		int a = value % 10;
		value /= 10;
		ret.push_back(a);
	} while (value > 0);
	return ret;
}
/*
void print(const vector<int>& v) {
	unsigned vn = v.size();

	while (vn--) {
		cout << v[vn];
	}
	cout << endl;
}
*/
void print2(const vector<int>& v) {
	unsigned vn = v.size();

	while (vn-->1) {
		cout << v[vn];
	}
	cout << v[vn] - 1;
	cout << endl;
}

void hanoii(int n, int from ,int to) {
	// base case
	if (n == 1) {
		cout << from << " " << to << "\n";
	}
	else {
		int other = 6 - from - to;
		hanoii(n - 1, from, other);
		cout << from << " " << to << "\n";
		hanoii(n - 1, other, to);
	}	
}
/*
void debug_valueToVector(unsigned long long a) {
	vector<int> v = valueToVector(a);
	for (unsigned i = 0; i < v.size(); ++i)
		cout << v[i] << " ";
	cout << endl;
}*/
/*
void debug_print12(vector<int>& v) {
	print(v);
	print2(v);

}
*/

int main() {
	/*
	vector<int> test;
	for (unsigned i = 0; i < 10; ++i) {
		int a;
		cin >> a; test.push_back(a);
	}
	debug_print12(test);
		*/

	
		int num;
		cin >> num;
		if (num <= 53) {
			unsigned long long cases = pow(2, num) - 1;
			cout << cases << "\n";
		}
		else {
			int power_diff = num - 53;
			unsigned long long two_to_the_53 = pow(2, 53);
			unsigned long long value_diff = pow(2, power_diff);
			vector<int> twoToThe53 = valueToVector(two_to_the_53), valueDiff = valueToVector(value_diff);
			vector<int> result = multiply(twoToThe53, valueDiff);
			print2(result);
		}
		if (num <= 20)
			hanoii(num, 1, 3);
	}

//unsigned long long으로는 63이 한계
//새로 도입한 방법으로 63*2 = 126까지 표시 가능.