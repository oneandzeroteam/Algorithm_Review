#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
using namespace std;


vector<int> solveSimulation(const vector<int>& recipe, vector<int> put) {
	vector<int> oa = put;
	int n = recipe.size();
	vector<int> ret(n);
	// 각 재료를 최소한 recipe에 적힌 만큼은 넣어야 한다.
	for(int i = 0; i < n; i++) {
		ret[i] = max(recipe[i] - put[i], 0);
		put[i] += ret[i];
	}

	// 비율이 전부 맞을 때까지 재료를 계속 추가하자.
	int iter = 0;
	while(true) {
		++iter;
		// 냄비에 재료를 더 넣지 않아도 될 때까지 반복한다.
		bool ok = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				// i 번째 재료에 의하면 모든 재료는 put[i] / recipe[i]= X배 이상은 넣어야 한다.
				// 따라서 put[j]는 recipe[j] * X 이상의 정수가 되어야 한다.
				int required = (put[i] * recipe[j] + recipe[i] - 1) / recipe[i];
				// 더 넣어야 하는가?
				if(required > put[j]) {
					ret[j] += required - put[j];
					put[j] = required;
					ok = false;
				}
			}
		}
		if (ok) break;
	}
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
		solution = solveSimulation(recipe, put);
		for (int k = 0; k < solution.size(); k++) {
			cout << solution[k] << " ";
		}
	}
	return 0;
}
