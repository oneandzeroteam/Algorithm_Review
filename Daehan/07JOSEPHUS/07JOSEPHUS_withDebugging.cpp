#include<iostream>
#include<list>

using namespace std;

int main() {

	list<int> remnants;
	list<int>::iterator it;
	int numCases;
	cin >> numCases;

	for (int j = 0; j < numCases; ++j) {

		int numRem;
		int k;

		cin >> numRem
			>> k;

		for (int i = 0; i < numRem; ++i)
			remnants.push_back(i);
		
		it = remnants.begin();
		for (int cnt =0;  numRem > 2; ++it) {
			if (it == remnants.end())
				it = remnants.begin();
			if (cnt % (k-1) == 0) {
				it = remnants.erase(it);
				if (it == remnants.end())
					it = remnants.begin();
				--numRem;
			}
			++cnt; cout <<"cnt : "<<cnt<<endl;
			cout << *it << endl;
		}

		cout << "outputs: ";
		it = remnants.begin();
		cout << *it+1<<" "; ++it;
		cout << *it+1 << endl;
		
		remnants.clear();
		}
	}
