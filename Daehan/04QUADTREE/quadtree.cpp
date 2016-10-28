#include<iostream>
#include<string>

using namespace std;

string str_in;
string::iterator it;


string reverse() {

	char ch = (*it);
	++it;

	if (ch == 'w') {
		
		return "w";

	}
		
	if (ch == 'b') {

		return "b";
	}


	string q1 = reverse();
	string q2 = reverse();
	string q3 = reverse();
	string q4 = reverse();

	return "x" + q3 + q4 + q1 + q2;
}



int main() {

	str_in.reserve(1002);
	int case_num;
	cin >> case_num;

	for (int k = 0; k != case_num; k++) {
		cin >> str_in;
		it = str_in.begin();

		cout << reverse().c_str() << endl;
		str_in.clear();
	}
}