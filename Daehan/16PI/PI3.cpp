#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

string S;
int cache[10002];
const int INF = 987654321; // numeric limit은 2xxxxxxxxx 정도의 수지만 그걸로 INF를 잡게 되면 에러 발생

int hardness(string S) {

	size_t len = S.size();

	bool p1 = true, p2 = true, p3 = true; 

										//p1 :숫자 같음
	for (size_t i = 0; i < len - 1; ++i)
		if (S[i] != S[i + 1]) {
			p1 = false;
			break;
		}
	if (p1) return 1;


	//p2 : 1씩 증가나 감소
	int diff = S[1] - S[0];
	for (size_t i = 1; i < len - 1; ++i)
		if (S[i + 1] - S[i] != diff) {
			p2 = false;
			break;
		}
	// 공차의 절댓값이 1이면 
	if (p2 && abs(diff) == 1) return 2;


	//p3 : 번갈아가며
	for (size_t i = 0; i < len - 2; ++i)
		if (S[i] != S[i + 2]) {
			p3 = false;
			break;
		}
	if (p3) return 4;


	//p2 : 공차의 절댓값이 1이 아닌 등차수열이므로
	if (p2) return 5;
	
	//기타의 경우
	return 10;
}

int memorize(int begin) {
	if (begin == S.size()) return 0;
	int& ret = cache[begin];
	if (ret != -1)
		return ret;
	ret = INF;
	for (size_t len = 3; len < 6; ++len) {
		if(begin + len <= S.size())
			ret = min(memorize(begin + len) + hardness(S.substr(begin, len)), ret);
	}

	return ret;
}

int main() {


	memset(cache, -1, sizeof(int) * 10002);
	
	int C;
	cin >> C;
	while (C--) {
		cin >> S;
		cout << memorize(0) << endl;
		memset(cache, -1, sizeof(int) * 10002);
	}
}