// NOT WORKING

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

string S;
int cache[10000];
int INF = numeric_limits<int>::max();

int hardness(string S) {

	size_t len = S.size();
	int nums[5];

	for (size_t i = 0; i < len; ++i) {
		char ch = S[i];
		nums[i] = atoi(&ch);
	}

	bool p1 = true, p2 = true, p3 = true, p4 = true; // 1. 숫자 같음, 2. 1씩 증가나 감소, 3. 번갈아가며, 4. 등차수열

													 //p1
	for (size_t i = 0; i < len - 1; ++i)
		if (S[i] != S[i + 1]) {
			p1 = false;
			break;
		}
	if (p1) return 1;


	//p2
	int diff = 1;
	for (size_t i = 1; i < len - 1; ++i)
		if (nums[i + 1] - nums[i] != diff) {
			p2 = false;
			break;
		}
	if (p2) return 2;


	//p3
	for (size_t i = 0; i < len - 2; ++i)
		if (S[i] != S[i + 2]) {
			p3 = false;
			break;
		}
	if (p3) return 4;


	//p4
	diff = nums[1] - nums[0];
	for (size_t i = 1; i < len - 1; ++i)
		if (nums[i + 1] - nums[i] != diff) {
			p4 = false;
			break;
		}
	if (p4) return 5;

	return 10;
}

int memorize(int begin) {
	int& ret = cache[begin];
	if (ret != INF)
		return ret;
	ret = INF;
	for (size_t len = 3; len < 6; ++len) {
		ret = min(memorize(begin + len) + hardness(S.substr(begin, len)), ret);
	}

	return ret;
}

int main() {
	memset(cache, INF, sizeof(int) * 10000);
	S = "1415926535";
	cout << memorize(0) << endl;

}