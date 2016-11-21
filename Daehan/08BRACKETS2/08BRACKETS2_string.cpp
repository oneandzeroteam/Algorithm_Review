#include<iostream>
#include<string>
using namespace std;

int main() {

	int numCases;
	cin >> numCases;

	for (int i = 0; i < numCases; ++i) {

		bool isMatched = true;
		string b = "";
		string input;
		cin >> input;

		for (unsigned int j = 0; j < input.size(); ++j) {
			if (input[j] == '(' || input[j] == '{' || input[j] == '[') {
			b += input[j];
//			cout << b << endl;
		}
			else {
				if (b.size() == 0) {
					cout << "No" << endl;
					isMatched = false;
					break;

				}
				else if ((*b.rbegin() == '(' && input[j] == ')') || (*b.rbegin() == '{' && input[j] == '}') || (*b.rbegin() == '[' && input[j] == ']')) {
					
					b.erase(b.end() - 1);
//					cout << b << endl;
				}
				else {
					cout << "No" << endl;
					break;
				}
			}
		}
		if (b.size() == 0 && isMatched) cout << "Yes" << endl;

		b.clear();
			}
	}