#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

int cache[1000][100];
int volume[100];
int need[100];
string name[100];
int num_item, max_capacity;
vector<string> picked;


int pack(int capacity, int item) {
	//기저사례
	if (capacity == 0 || item == num_item)
		return 0;

	int& ret = cache[capacity][item];

	if (ret != -1) return ret;

	ret = pack(capacity, item + 1);

	if(volume[item] <= capacity){

		ret = max(pack(capacity - volume[item], item + 1) + need[item], pack(capacity, item + 1));

	}
	return ret;

}

void reconstruct(int capacity, int item, vector<string>& picked) {
	if (item == num_item) return;

	if (pack(capacity, item) == pack(capacity, item + 1))
		reconstruct(capacity, item + 1, picked);
	else {
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}	
}

int main() {

	int C;
	cin >> C;

	while (C--) {
		memset(cache, -1, sizeof(cache));

		cin >> num_item >> max_capacity;

		for (int i = 0; i < num_item; ++i) {
			cin >> name[i] >> volume[i] >> need[i];
		}
		reconstruct(max_capacity, 0, picked);
		cout << pack(max_capacity, 0) << " " << picked.size() << endl;
		for (unsigned i = 0; i < picked.size(); ++i)
			cout << picked[i] << "\n";

		picked.clear();
	}

}