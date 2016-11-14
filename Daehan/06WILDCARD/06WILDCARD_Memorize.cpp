#include<iostream>
#include<algorithm>
#include<string>
#include<cstring> //memset용
using namespace std;

int cache[101][101];

string W;
string S;

int matchMemorized(unsigned int w,unsigned int s) {
	int& ret = cache[w][s];

	if (ret != -1) return ret;
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s])){
	++w;
	++s;
	}

	if (w == W.size()) return ret = (s == S.size());
	
	if (W[w] == '*')
		for (int skip = 0; skip + s <= S.size(); ++skip)
			if (matchMemorized(w + 1, s + skip))
				return ret = 1;
	return ret = 0;
}


int main() {

	W.reserve(101);
	S.reserve(101);

	int numTestcase;

	cin >> numTestcase;

	for (int i = 0; i < numTestcase; ++i) {

		int numInput;
		int cnt=0;
		cin >> W
			>> numInput;
//		cout << "W : " << W << "\nnumInput: " << numInput << endl;디버깅
		string* input = new string[numInput];

		for (int j = 0; j < numInput; ++j)
			cin >> input[j];

		sort(input, input + numInput);
		memset(cache, -1, sizeof(cache));

		for (int k = 0; k < numInput; ++k) {
			S = input[k];
//			cout <<"S: "<< S << endl;디버깅
			if (matchMemorized(0, 0)==1) {
				input[cnt] = input[k];
				++cnt;
//				cout << "cnt = " << cnt << endl;디버깅
			}
			memset(cache, -1, sizeof(cache));
			S.clear();
		}
		for (int k = 0; k < cnt; ++k)
			cout << input[k] << endl;

		W.clear();
		delete[] input;
	}
}