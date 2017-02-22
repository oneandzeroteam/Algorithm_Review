#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;


// Ten Million
const int TM = 1000*1000*10;
// minFactor[i] = i의 가장 작은 소인수(i가 소수인 경우 자기 자신)
int minFactor[TM + 1];
// minFactorPower[i] = i의 소인수분해에는 minFactor[i]의 몇 승이 포함되어 있는가?
int minFactorPower[TM + 1];

//factors[i] = i가 가진 약수의 수
int factors[TM+1];

void eratosthenes2() {
	// 1은 항상 예외 처리
	minFactor[0] = minFactor[1] = -1;
	// 모든 숫자를 처음에는 소수로 표시해 둔다.
	for (int i = 2; i <= TM; ++i)
		minFactor[i] = i;
	//에라토스테네스의 체를 수행한다.
	int sqrtn = int(sqrt(TM));
	for(int i = 2; i <= sqrtn; ++i) {
		if(minFactor[i] == i) {
			for(int j = i*i; j <= TM; j += i){
				// 아직 약수를 본 적 없는 숫자인 경우 i를 써둔다.
				if(minFactor[j] == j){
					minFactor[j] = i;
				}
			}			
		}
	}
}

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

void getFactorsBrute() {
	memset(factors, 0, sizeof(factors));
	for (int div = 1; div <= TM; ++div)
		for (int multiple = div; multiple <= TM; multiple += div)
			factors[multiple] += 1;
}

int main() {
int num_case = 0;
	//memset(minFactor, 1, sizeof(int)*(TM+1));
	eratosthenes2();
	getFactorsSmart();
	
	cin >> num_case;
	for (int i = 0; i < num_case; i++) {
		
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
