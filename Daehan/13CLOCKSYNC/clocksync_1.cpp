#include<iostream>
#include<vector>
#include<algorithm>
#define SWITCHES 10
#define CLOCKS 16
#define INF 10000
using namespace std;

char linked[SWITCHES][CLOCKS + 1] = {
	//If a switch is linked to a clock, mark 'x' otherwise '.'
	"xxx.............",
	"...x...x.x.x....",
	"....x.....x...xx",
	"x...xxxx........",
	"......xxx.x.x...",
	"x.x...........xx",
	"...x..........xx",
	"....xx.x......xx",
	".xxxxx..........",
	"...xxx...x...x.."
};

// checks if clocks are aligned, that is, all clocks point to 12.
bool areAligned(const vector<int>& clocks) {
	bool ret = false;
	for (unsigned i = 0; i < clocks.size(); ++i)
		if (clocks[i] != 12) return ret;
	return true;
}

// push the button 'swtch' to let clocks go.
void push(vector<int>& clocks, int swtch) {
	for (int clock = 0; clock < CLOCKS; ++clock)
		if (linked[swtch][clock] == 'x') {
			clocks[clock] += 3;
			if (clocks[clock] == 15) 
				clocks[clock] = 3;
		}
}
/*
int solve(vector<int>& clocks, int swtch) {
	int ret = 0; 
	if (areAligned(clocks)) return ret;
	
	for (int i = 0; i < SWITCHES; ++i) {
		++ret;
		push(clocks, i);
		if (areAligned(clocks))
			return ret;
	}
}

*/

// Recursion part. Go through all switches till pushed 3 times. There is 4^10 cases to see.
int solve(vector<int>& clocks, int swtch) {
	if (swtch == SWITCHES) 
		return areAligned(clocks) ? 0 : INF;
	// if no match occurs, ret becomes INF and the program will print out '-1'
	int ret = INF;
	for (int cnt = 0; cnt < 4; ++cnt) {
		ret = min(ret, cnt + solve(clocks, swtch + 1));
		push(clocks, swtch);
	}
	return ret;
}

int main() {
	int C;
	cin >> C;

	for (int i = 0; i < C; ++i) {
		vector<int> clocks(16);
		for (unsigned j = 0; j < 16; ++j)
			cin >> clocks[j];
		int sol = solve(clocks, 0);
		if (sol < 0 || sol > 30) cout << -1 << endl;
		else cout << sol << endl;
	}
}