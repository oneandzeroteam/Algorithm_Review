#include<iostream>
#include<string>
using namespace std;

int main() {

	int numCases;
	cin >> numCases;

	for (int i = 0; i < numCases; ++i) {

		bool case_1 = false;
		bool case_2 = false;

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
					cout << "NO" << endl;
					case_1 = true;
					break;//닫는 괄호가 더 많은 경우
				}
				else if ((*b.rbegin() == '(' && input[j] == ')') || (*b.rbegin() == '{' && input[j] == '}') || (*b.rbegin() == '[' && input[j] == ']')) {
					
					b.erase(b.end() - 1);
//					cout << b << endl;
				}
				else {
					cout << "NO" << endl;
					case_2 = true;//짝이 맞지 않는 잘못된 괄호가 온 경우
					break;
				}
			}
		}
		if (b.size() == 0 && !case_1 && !case_2) 
			cout << "YES" << endl;
		else {
			if(case_1 || case_2) continue;
			else cout << "NO" << endl;
		}
		b.clear();
			}
	}
