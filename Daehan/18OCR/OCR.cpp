// 돌아간다!!!!!

#include<iostream>
#include<string>
#include<string.h>
#include<math.h>
#include<limits>
using namespace std;

int n, m; // n : 한 문장 안에 존재하는 단어의 개수
		  //m : 가능한 모든 단어의 종류 수
int R[100]; // 분류기가 반환한 문장을 단어 번호로 저장
double T[501][501]; // 여기에 특정 단어가 첫자리에 올 확률 포함됨.
double M[501][501];
int choice[102][502];
double cache[102][502];
string corpus[501];
double NEGINF = -numeric_limits<double>::max();


double recognize(int segment, int previousMatch) {
	if (segment == n) return 0;
	double& ret = cache[segment][previousMatch];
	if (ret != 1.0) return ret;
	ret = NEGINF;
	int pick = 0;


	for (int thisMatch = 0; thisMatch < m; ++thisMatch) {
		double comp = T[previousMatch][thisMatch] + M[thisMatch][R[segment]] + recognize(segment + 1, thisMatch);
		if (ret < comp) {
			ret = comp;
			pick = thisMatch;
		}

	}
	choice[segment][previousMatch] = pick;
	return ret;
}


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


	int num_line;
	double temp;
	cin >> m >> num_line;
	for (int i = 0; i < m; ++i)
		cin >> corpus[i];


	// B[i]를 채워주는 부분
	for (int j = 0; j < m; ++j) {
		cin >> temp;
		T[m][j] = log(temp);
	}

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> temp;
			T[i][j] = log(temp);
		}

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> temp;
			M[i][j] = log(temp);
		}

	while (num_line--) {

		for (int i = 0; i < 102; ++i)
			for (int j = 0; j < 502; ++j) {
				cache[i][j] = 1.0;
				choice[i][j] = 0;
			}
		cin >> n;

		for (int i = 0; i < n; ++i) {
			string temp;
			cin >> temp;
			R[i] = findIndex(temp);

		}
		recognize(0, m);
		cout << reconstruct(0, m) << endl;
	}

}