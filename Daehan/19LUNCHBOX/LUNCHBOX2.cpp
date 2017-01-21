#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int num_lunchbox;
int eat[10000], micro[10000];

int heat() {

	vector<pair<int, int>> order;

	for (int i = 0; i < num_lunchbox; ++i) {
		order.push_back(make_pair(-eat[i], i));
	}

	sort(order.begin(), order.end());

	int begin_to_eat = 0, total_time =0;
	for (int i = 0; i < num_lunchbox; ++i) {
		int box = order[i].second;
		int micro_time = micro[box];
		begin_to_eat += micro_time;
		total_time = max(total_time, begin_to_eat + eat[box]);
	}

	return total_time;
}

int main() {
	int num_case;
	cin >> num_case;

	while (num_case--) {

		cin >> num_lunchbox;

		for (int i = 0; i < num_lunchbox; ++i)
			cin >> micro[i];

		for (int i = 0; i < num_lunchbox; ++i)
			cin >> eat[i];

		cout << heat() << endl;

	}

}