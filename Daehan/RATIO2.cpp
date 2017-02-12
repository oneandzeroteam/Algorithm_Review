#include<iostream>

using namespace std;

long long game, win, ratio;
long long ret;
const long long MAX_ITER_NUM = 2000000000;


int calc(const long long& game, const long long& win) {

	int lo = -1;
	int hi = MAX_ITER_NUM+1;
	
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (ratio + 1 <= (win + mid) * 100 / (game + mid))
			hi = mid;
		else //if (ratio + 1 > (win + mid) * 100 / (game + mid))
			lo = mid;

	}

	return hi;
}

int main() {

	int C;
	cin >> C;

	while (C--) {

		cin >> game >> win;

		ratio = win * 100 / game;

		if (win*100/game >= 99)
			cout << -1 << endl;
		else
			cout << calc(game, win) << endl;

	}
}
