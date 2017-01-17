// Not Working

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int n, m; // n : 한 문장 안에 존재하는 단어의 개수
//m : 가능한 모든 단어의 종류 수
int R[100]; // 분류기가 반환한 문장을 단어 번호로 저장
double T[501][501]; // 여기에 특정 단어가 첫자리에 올 확률 포함됨.
double M[501][501];
int choice[102][502];
double cache[102][502];

double mylog(double a) {
	if (a == 0.0) return -1e200;
	return log(a);
}

double recognize(int segment, int previousMatch) {
	if (segment == n) return 0;
	double& ret = cache[segment][previousMatch];
	if (ret != 1.0) return ret;
	ret = -1e200;
	int& choose = choice[segment][previousMatch];

	for (int thisMatch = 0; thisMatch < m; ++thisMatch) {
		double comp = T[previousMatch][thisMatch] + M[thisMatch][R[segment]] + recognize(segment + 1, thisMatch);
		if (ret < comp) {
			ret = comp;
			choose = thisMatch;
		}

	}
	return ret;
}

string corpus[501];

string reconstruct(int segment, int previousMatch) {
	int choose = choice[segment][previousMatch];
	string ret = corpus[choose];
	if (segment < n - 1)
		ret = ret + " " + reconstruct(segment + 1, choose);
	return ret;
}

int findIndex(string toFind) {
	for (int i = 0; i < m; ++i)
		if (corpus[i] == toFind) return i;
}

int main() {
//	corpus[0] = "Hi";

	int num_line;
	cin >> m >> num_line;
	for (int i = 0; i < m; ++i)
		cin >> corpus[i];
	corpus[m] = "I'm cool!";

	// B[i]를 채워주는 부분
	for (int j = 0; j < m; ++j) {
		cin >> T[m][j];
		T[m][j] = mylog(T[m][j]);
	}

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> T[i][j];
			T[i][j] = mylog(T[i][j]);
		}

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> M[i][j];
			M[i][j] = mylog(M[i][j]);
		}

	while (num_line--) {

		cin >> n;

		for (int i = 0; i < n; ++i) {
			string temp;
			cin >> temp;
			R[i] = findIndex(temp);
//			cout << R[i];
		}
//		recognize(0, 0);
		cout << reconstruct(0, m) << endl;
	}

}