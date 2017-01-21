#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;

int micro[10000], eat[10000];
int num_lunchbox;

bool lessThan(pair<int, int> i, pair<int, int> j) { return (i.first > j.first); }

int minimize_lunchtime() {

	vector<pair<int, int>> micro_eat_pair;
	int edge = 0; // 밖으로 삐져나가는 부분
	int sum_micro = 0;

	for (int i = 0; i < num_lunchbox; ++i) {
		micro_eat_pair.push_back(make_pair(eat[i], micro[i]));
		sum_micro += micro[i];	// micro의 총합을 구함.
	}


	sort(micro_eat_pair.begin(), micro_eat_pair.end(), lessThan);
	// eat 기준으로 정렬되어 있음. greater<pair<int,int>>()

	micro_eat_pair.push_back(make_pair(0, 0)); // vector subscript out of range 에러 없애기 위해 추가


	int sum_micro2 = sum_micro - micro_eat_pair[0].second;
	
	//여기에서 최대를 구함.
	for (int i = 0; i < num_lunchbox; ++i) {
		if (micro_eat_pair[i].first >= sum_micro2) {
			edge = max(micro_eat_pair[i].first - sum_micro2, edge);
		}
		sum_micro2 -= micro_eat_pair[i + 1].second;
	}

	if (edge < micro_eat_pair[num_lunchbox - 1].first) edge = micro_eat_pair[num_lunchbox - 1].first;
	return sum_micro + edge;
}


int main() {

	int num_case;
	cin >> num_case;

	while (num_case--) {

		cin >> num_lunchbox;

		for (int i = 0; i < num_lunchbox; ++i) {
			cin >> micro[i];
		}
		for (int i = 0; i < num_lunchbox; ++i) {
			cin >> eat[i];
		}

		cout << minimize_lunchtime() << endl;

	}
}