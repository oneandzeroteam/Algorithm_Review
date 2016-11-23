#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool matched(const string& input) {

	stack<char> b;

	for (unsigned int j = 0; j < input.size(); ++j) {
		if (input[j] == '(' || input[j] == '{' || input[j] == '[')
			b.push(input[j]);
		else {
			if (b.empty()) return false;
			bool cond = (b.top() == '(' && input[j] == ')') || (b.top() == '{' && input[j] == '}') || (b.top() == '[' && input[j] == ']');
			if (!cond) return false;
			b.pop();
				}
			}
	return b.empty();
		}


int main() {

	int numCases;
	cin >> numCases;

	for (int i = 0; i < numCases; ++i) {
		string input;
		cin >> input;
		matched(input) ? cout << "YES" : cout << "NO";
		cout << endl;
	}
}