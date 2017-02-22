#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;


// Ten Million
const int TM = 1000*1000*10;
// minFactor[i] = i의 가장 작은 소인수(i가 소수인 경우 자기 자신)
int minFactor[TM + 1];
// minFactorPower[i] = i의 소인수분해에는 minFactor[i]의 몇 승이 포함되어 있는가?
int minFactorPower[TM + 1];

//factors[i] = i가 가진 약수의 수
int factors[TM+1];

void getFactorsSmart() {
	factors[1] = 1;
	for(int n = 2; n <= TM; ++n) {
		// 소수인 경우 약수가 2 개 밖에 없다.
		if(minFactor[n] == n) {
			minFactorPower[n] = 1;
			factors[n] = 2;
		}
		// 소수가 아닌 경우, 가장 작은 소인수로 나눈 수(m)의
		// 약수의 수를 이용해 n의 약수의 수를 찾는다.
		else {
			int p = minFactor[n];
			int m = n / p;
			// m이 p로 더이상 나누어지지 않는 경우
			if (p != minFactor[m])
				minFactorPower[n] = 1;
			else
				minFactorPower[n] = minFactorPower[m] + 1;
			int a = minFactorPower[n];
			factors[n] = (factors[m] / 1) * (a + 1);
		}
	}
}

int main() {
int num_case = 0;
	getFactorsSmart();
	cin >> num_case;
	for (int i = 0; i < num_case; i++) {
		// memset(cache, -1, sizeof(int)*10002);
		int sol = 0;
		int n, lo, hi;
		cin >> n >> lo >> hi;
		
		for (int i = lo; i <= hi; ++i) {
			if (factors[i] == n)
				sol++;
		}
		cout << sol << endl;
	}
	return 0;
}