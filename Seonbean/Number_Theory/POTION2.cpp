#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a%b);
}

// 분수 a/b보다 같거나 큰 최소의 자연수를 반환한다.
int ceil(int a, int b) {
	return (a + b - 1) / b;
}

// 마법의 약 레시피와 이미 넣은 재료의 양이 주어질 때, 더 넣을 재료의 양을 구한다.
vector<int> solve(const vector<int>& recipe, const vector<int>&put) {
	int n = recipe.size();
	// 모든 recipte[]의 최대공약수를 구한다.
	int b = recipe[0];
	for (int i = 1; i < n; i++) b = gcd(b, recipe[i]);
	// 최소한 b/b = 1배는 만들어야 하므로, a의 초기 값을 b로 둔다.
	int a = b;
	// X를 직접 구하는 대신 ceil(put[i]*b, recipe[i])의 최대값을 구한다.
	for (int i = 0; i < n; i++)
		a = max(a, ceil(put[i] * b, recipe[i]));
	// a/b 배 분량을 만들면된다.
	vector<int> ret(n);
	for (int i = 0; i < n; i++)
		ret [i] = recipe[i] * a / b - put[i];
	return ret;
}

int main() {
	int num_case = 0;
	cin >> num_case;
	for (int i = 0; i < num_case; i++) {
		vector<int> put,recipe,solution;
		int temp, num_potion;
		cin >> num_potion;
		for (int j = 0; j < num_potion; j++) {
			cin >> temp;
			recipe.push_back(temp);
		}
		for (int j = 0; j < num_potion; j++) {
			cin >> temp;
			put.push_back(temp);
		}
		solution = solve(recipe, put);
		for (int k = 0; k < solution.size(); k++) {
			cout << solution[k] << " ";
		}
	}
	return 0;
}
