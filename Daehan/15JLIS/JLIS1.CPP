#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

int A[100], B[100];
int cache[101][101];
size_t m,n;
const long long NEGINF = numeric_limits<long long>::min();


int jlis(size_t indexA, size_t indexB) {
	int& ret = cache[indexA + 1][indexB + 1];
	if (ret != -1) return ret;

	ret = 2; // Given A[indexA] != B[indexB], we have at least 2 as ret.
	long long a = (indexA == -1) ? NEGINF : A[indexA];
	long long b = (indexB == -1) ? NEGINF : B[indexB];

	long long maxElement = max(a, b);

	for (size_t nextA = indexA + 1; nextA < m; ++nextA)
		if (maxElement < A[nextA])
			ret = max(ret, jlis(nextA, indexB) + 1);

	for (size_t nextB = indexB + 1; nextB < n; ++nextB)
		if (maxElement < B[nextB])
			ret = max(ret, jlis(indexA, nextB) + 1);
	
	return ret;
}


int main() {

	int C;
	cin >> C;
	while (C--) {

		memset(cache, -1, sizeof(int) * 101 * 101);

		cin >> m >> n;

		for (size_t i = 0; i < m; ++i)
			cin >> A[i];

		for (size_t i = 0; i < n; ++i)
			cin >> B[i];

		cout << jlis(-1, -1) - 2 << endl;
	}
}