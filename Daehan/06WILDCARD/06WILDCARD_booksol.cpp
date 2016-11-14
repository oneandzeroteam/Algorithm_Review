#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool match(const string& w, const string& s){

	unsigned int pos = 0;
	while (pos < s.size() && pos < w.size() && (w[pos] ==
		'?' || w[pos] == s[pos])) 
		++pos;

	if (pos == w.size())
		return pos == s.size();

	if (w[pos] == '*')
		for (unsigned int skip = 0; pos + skip <= s.size(); ++skip) 
			if (match(w.substr(pos + 1), s.substr(pos + skip)))
				return true;
	
	return false;
}

int main() {

	int numTestcase;

	cin >> numTestcase;

	for (int i = 0; i < numTestcase; ++i) {

		int numInput;
		string wildcard;
		
		cin >> wildcard
			>> numInput;

		string* input = new string[numInput];

		for (int j = 0; j < numInput; ++j) 
			cin >> input[j];

		sort(input, input + numInput);

		for (int k = 0; k < numInput; ++k) 
			if (match(wildcard, input[k]))
				cout << input[k] << endl;
		
		delete[] input;
	}
}