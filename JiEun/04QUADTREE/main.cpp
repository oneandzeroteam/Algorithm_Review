#include <string>
#include <stdio.h>
#include <iostream>

using namespace std;
int tc,i=0;
string img;

string reverse(string :: iterator& str) {
	char head = *str;
	++str;
	if (head == 'b' || head == 'w')
		return string(1, head); //BaseCase
	string upperLeft = reverse(str);
	string upperRight = reverse(str);
	string lowerLeft = reverse(str);
	string lowerRight = reverse(str);
	return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	scanf("%d", &tc);
	cin >> img;
	for (;;) {
		string :: iterator str = img.begin();
		string result = reverse(str);
		cout << result << endl;
		++i;
		if (i = tc) break;
	} 
}