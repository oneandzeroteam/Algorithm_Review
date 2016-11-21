#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main() {

	stack<char> b;


	int numCases;
	cin >> numCases;

	for (int i = 0; i < numCases; ++i) {

		string input;
		cin >> input;

		for (unsigned int j = 0; j < input.size(); ++j) {
			if(input[j] == '(' || input[j] == '{' || input[j] == '[')
				b.push(input[j]);
			else {
				if ((b.top() == '(' && input[j]==')') || (b.top() == '{' && input[j] == '}')|| (b.top() == '[' && input[j] == ']')) b.pop();
				else { 
					cout << "No" << endl; 
					break;
				}
			}
		}
		if (b.empty()) cout << "Yes" << endl;

//		for (int j = 0; j < input.size(); ++j) {
//			cout << b.top();
//			b.pop();
//		} µð¹ö±ë¿ë
		while (!b.empty())
			b.pop(); // clear b
	}
}