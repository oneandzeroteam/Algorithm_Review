#include<iostream>
#include<map>

using namespace std;

map<int, int> coords;

int C;

bool isDominated(int x, int y) {
	map<int, int>::iterator it = coords.lower_bound(x);

	if (it == coords.end()) return false;

	return y < it->second;
}

void removeDominated(int x, int y) {
	map<int, int>::iterator it = coords.lower_bound(x);

	if (it == coords.begin()) return;

	--it;
	while (it != coords.begin()) {
		if (it->second > y) break;
		
		map<int, int>::iterator jt = it;
		--jt;
		coords.erase(it);
		it = jt;
	}
	if (it->second < y) coords.erase(it);

}

int registered(int x, int y) {
	if (isDominated(x, y)) return coords.size();
	removeDominated(x, y);
	coords[x] = y;
	return coords.size();
}

int main() {
	cin >> C;

	for (int i = 0; i < C; ++i) {
		int N, sum = 0;
		cin >> N;

		for (int j = 0; j < N; ++j) {
			int p, q; cin >> p >> q;
			sum += registered(p, q);
		}

		cout << sum << endl;
		coords.clear();
	}
}