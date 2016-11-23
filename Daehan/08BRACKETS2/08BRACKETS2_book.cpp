#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool wellMatched(const string& formula) {

	const string opening("({["), closing(")}]");

	stack<char> openStack;

	for (int i = 0; i < formula.size(); ++i)
		if (opening.find(formula[i]) != -1) {
			openStack.push(formula[i]);
//			cout << openStack.top() << " :pushed" << endl;
		}
		else {

			if (openStack.empty()) return false;
			
			if (opening.find(openStack.top()) != closing.find(formula[i])) return false;
//			cout << openStack.top() << " :popped" << endl;
			openStack.pop();
		}

		return openStack.empty();
}

int main() {

	cout << ('[' == ']') << endl;

	int numCase;

	cin >> numCase;

	for (int i = 0; i < numCase; ++i){
	
		string input;
		cin >> input;

		(wellMatched(input)) ? cout << "YES" : cout << "NO";
		cout << endl;
	}


}