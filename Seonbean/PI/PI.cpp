#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int INF = 987654321;
string N;
// N[a,b] 구간의 난아도를 반환한다.
int classify(int a, int b) {
	// 숫자 조각을 가져온다.
	string M = N.substr(a,b-a+1);
	// 첫 글자 만으로 이루어진 문자열과 같으면 난이도는 1
	if (M == string(M.size(), M[0])) return 1;
	// 등차수열인지 검사
	bool progressive = true;
	for (int i = 0; i < M.size()-1;++i) {
		if(M[i+1]- M[i] != M[1] - M[0])
			progressive = false;
	}
	// 등차수열이고 공차가 1 혹은 -1 이면 난이도 2
	if (progressive && abs(M[1] - M[0]) == 1)
		return 2;
	// 두 수가 번갈아 등장하는 지 확인
	bool alternating = true;
	for (int i = 0; i < M.size();++i) {
		if(M[i] != M[i % 2])
			alternating = false;
	}
	if(alternating) return 4;
	if(progressive) return 5;
	return 10;
}

int cache[10002];
// 수열 N[begin..]를 외우는 방법 중 난이도의 최소 합을 출력한다.

int memorize(int begin) {
	// 기저 사례 : 수열의 끝에 도달했을 경우
	if (begin == N.size()) return 0;
	// memorization
	int& ret = cache[begin];
	if (ret != -1) return ret;
	ret = INF;
	for (int L = 3; L <= 5; ++L) {
		if (begin + L <= N.size()) 
			ret = min(ret,memorize(begin+L) + 
				classify(begin,begin+ L - 1));
	}		
		return ret;
	
}

int main() {
	int num_case = 0;
	cin >> num_case;
	for (int i = 0; i < num_case; i++) {
		memset(cache, -1, sizeof(int)*10002);
		cin >> N;
		cout << memorize(0) << endl;
		
		
	}
	return 0;
}
