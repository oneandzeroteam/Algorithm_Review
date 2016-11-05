#include<iostream> // now it operates!
#include<string>
#include<algorithm>

using namespace std;

int dist[101][101];

int levenshtein(string& input1, string& input2) {

	dist[0][0] = 0;
	for (unsigned int i = 1; i <= input1.length(); ++i)
		if (input1[i - 1] == '*')
			dist[i][0] = dist[i - 1][0];
		else
			dist[i][0] = dist[i - 1][0] + 1;
	for (unsigned int j = 1; j <= input2.length(); ++j)
		dist[0][j] = j;

	for (unsigned int j = 1; j <= input2.length(); ++j) {
		for (unsigned int i = 1; i <= input1.length(); ++i) {
			if (input1[i - 1] == '*')
				dist[i][j] = min(dist[i - 1][j - 1], min(dist[i][j - 1], dist[i - 1][j]));
			else if (input1[i - 1] == '?')
				dist[i][j] = min(dist[i - 1][j - 1], min(dist[i][j - 1] + 1, dist[i - 1][j] + 1));
			else if (input1[i - 1] == input2[j - 1])
				dist[i][j] = dist[i - 1][j - 1];
			else
				dist[i][j] = min(dist[i - 1][j - 1] + 1, min(dist[i][j - 1] + 1, dist[i - 1][j] + 1));
		}
	}

	return dist[input1.length()][input2.length()];
}

int main() {
	int numTestcase;
	cin >> numTestcase;
	for (int i = 0; i < numTestcase; ++i) {
		string wildcard;
		int numExample;
		cin >> wildcard >> numExample;
		string* example = new string[numExample];

		for (int j = 0; j < numExample; ++j) {
			cin >> example[j];
		}

		sort(example, example + numExample);

		for (int j = 0; j < numExample; ++j)
			if (levenshtein(wildcard, example[j]) == 0)
				cout << example[j] << endl;

		delete[] example;
	}
	return 0;
}