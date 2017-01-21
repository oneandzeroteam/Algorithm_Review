#include<iostream>
#include<set>
#include<vector>

using namespace std;

int count_wins(const vector<int>& korean, const vector<int>& russian) {

	multiset<int> rating(korean.begin(), korean.end());
	int win = 0;
	for (int i = 0; i < russian.size(); ++i) {
		if (*rating.rbegin() < russian[i])
			rating.erase(rating.begin());
		else {
			rating.erase(rating.lower_bound(russian[i]));
			++win;
		}

	}

	return win;
}

int main() {
	int num_case;
	cin >> num_case;

	while (num_case--) {
		vector<int> korean, russian;
		int num_player; cin >> num_player;
		for (int i = 0; i < num_player; ++i) {
			int temp; cin >> temp;
			russian.push_back(temp);
		}
		for (int i = 0; i < num_player; ++i) {
			int temp; cin >> temp;
			korean.push_back(temp);
		}

		cout << count_wins(korean, russian) << endl;

	}
}