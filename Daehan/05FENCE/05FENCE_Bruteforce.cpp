#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int bruteForce(const vector<int>& h) {
	int ret = 0;
	int N = h.size();

	for (int left = 0; left < N; ++left) {
		int minHeight = h[left];
		for (int right = left; right < N; ++right) {
			minHeight = min(minHeight, h[right]);
			ret = max(ret, (right - left + 1)* minHeight);
		}
	}

	return ret;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; ++i) {

		int numFence;

		cin >> numFence;

		vector<int> fence;
		fence.reserve(numFence);

		for (int j = 0; j < numFence; ++j) {
		int k; cin >> k;
		fence.push_back(k);

	}
		//for (int k = 0; k < numFence; ++k)
		//	cout << fence[k] << endl; vector 할당 확인용

		int out =  bruteForce(fence);
		cout << out << endl;

	}

}
// right answer but time-over!