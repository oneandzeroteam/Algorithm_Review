#include<iostream>
#include<set>

using namespace std;


int solve(multiset<int>& str_len) {
	set<int>::iterator it;
	int size = str_len.size();
	int ret = 0;
	int temp = 0;
	for (int i = 0; i < size - 1; ++i) {
		it = str_len.begin();
		temp = *(it++) + *(it++); // first and second element
	
		str_len.erase(str_len.begin(), it);
		str_len.insert(temp);

		ret += temp;
	}

	return ret;
}

int main() {

	int case_num; cin >> case_num;

	while (case_num--) {
		multiset<int> str_len;
		int num_str; cin >> num_str;

		while (num_str--) {
			int temp; cin >> temp; str_len.insert(temp);
		}

		cout << solve(str_len) << endl;
	}

}