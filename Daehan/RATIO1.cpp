//timeover
#include<iostream>


using namespace std;

long long game, win, ratio;
const long long MAX_ITER_NUM = 2000000000;

long long calc(const long long& game, const long long& win){

	
	for (long long i = 0; i < MAX_ITER_NUM; ++i) {
		if (ratio + 1 == (win + i) * 100 / (game + i))
			return i;
	}


}

int main() {

	int C;
	cin >> C;

	while (C--) {

		cin >> game >> win;

		ratio = win * 100 / game;

		if (win * 100 / game >= 99)
			cout << -1 << endl;
		else
			cout << calc(game, win) << endl;

	}
}
