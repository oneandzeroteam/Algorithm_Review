#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> fence;

int solve(int left, int right) {
	if (left == right)
		return fence[left];

	int mid = (left + right) / 2;

	int ret = max(solve(left, mid), solve(mid + 1, right));


	int lo = mid, hi = mid + 1;
	int height = min(fence[lo], fence[hi]);
	
	ret = max(ret, height * 2);

	while (left < lo || hi < right) {

		if (hi == right) {
			--lo;
			height = min(height, fence[lo]);

		}
		else if (lo == left) {
			++hi;
			height = min(height, fence[hi]);

		} else if(fence[lo - 1] <= fence[hi + 1]){
			++hi;
			height = min(height, fence[hi]);
		}else {
			--lo;
			height = min(height, fence[lo]);

		}

		ret = max(ret, height *(hi - lo + 1));
	//	cout << "lo = " << lo << " hi = " << hi << endl;
	//	cout << "ret = " << ret << endl;
	}
	return ret;
}


int main() {

	int testCase;
	cin >> testCase;

	for (int i = 0; i < testCase; ++i) {

		int numFence;

		cin >> numFence;

		fence.reserve(numFence);

		for (int j = 0; j < numFence; ++j) {
			int k; cin >> k;
			fence.push_back(k);

		}
		//for (int k = 0; k < numFence; ++k)
		//	cout << fence[k] << endl; vector 할당 확인용

		cout << solve(0, numFence - 1) << endl;

		fence.clear();

	}

}
//pass the exam!