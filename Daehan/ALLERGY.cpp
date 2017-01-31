#include<iostream>
#include<vector>
#include<string>

using namespace std;


int num_food, num_people;
int best;

vector<int> canEat[50], eaters[50];
string name[50];

void search(vector<int>& edible, int chosen) {

	if (chosen >= best) return;

	int first = 0;
	//먹을 음식이 없는 첫번째 친구를 찾는다.
	while (first < num_people && edible[first]>0) ++first;

	if (first == num_people) { best = chosen; return; }

	for (int i = 0; i < canEat[first].size(); ++i) {

		int food = canEat[first][i];
		//음식 하나를 만들고 edible 수정.
		for (int j = 0; j < eaters[food].size(); ++j)
			edible[eaters[food][j]]++;
		//재귀를 돌린다.
		search(edible, chosen + 1);

		//그 음식을 다시 뺌.
		for (int j = 0; j < eaters[food].size(); ++j)
			edible[eaters[food][j]]--;
	}

}


int main() {

	int T; cin >> T;

	while (T--) {

		cin >> num_people;
		cin >> num_food;

		//사람 이름 받음.
		for (int i = 0; i < num_people; ++i)
			cin >> name[i];

		for (int i = 0; i < num_food; ++i) {
			int k; cin >> k;
			for (int j = 0; j < k; ++j) {
				string temp;
				cin >> temp;
				for (int l = 0; l < num_people; ++l)
					// canEat 배열 초기화
					if (temp == name[l]) {
						canEat[l].push_back(i);
						eaters[i].push_back(l);
					}
			}
		}

		//best는 사람 수를 넘지 못하므로 사람 수로 초기화
		best = num_people;

		
		//best 구하는 부분
		vector<int> edible(num_people,0);
		search(edible, 0);
		cout << best << endl;

		// 전역변수 초기화
		for (int i = 0; i < 50; ++i) {
			canEat[i].clear();
			eaters[i].clear();
		}
	}


}
