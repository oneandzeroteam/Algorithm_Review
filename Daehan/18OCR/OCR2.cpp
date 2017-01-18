#include<iostream>
#include<string.h>
#include<string>
#include<math.h>
#include<limits>
#include<vector>

using namespace std;

int m, q, n;

string strArr[501];
double nextStr[501][501];
double isStr[501][501];
int input[501];
vector<int> ans;

const double MINVAL = -numeric_limits<double>::max();


double dp[102][502];
int pickmat[102][502];

double solve(int order, int lastStr) {
	if (order == n)
		return 0;
	if (dp[order][lastStr] != 1)
		return dp[order][lastStr];

	double ret = MINVAL, comp;
	int pick=0;

	for (int thisMatch = 1; thisMatch <= m; ++thisMatch) {

		comp = nextStr[lastStr][thisMatch] + isStr[thisMatch][input[order]] + solve(order + 1, thisMatch);

		if (ret < comp) {
			ret = comp;
			pick = thisMatch;
		}
	}

	dp[order][lastStr] = ret;
	pickmat[order][lastStr] = pick;

	return ret;
}

void setAns(int order, int lastStr) {

	int i = pickmat[order][lastStr];
	ans.push_back(i);
	if (order < n - 1)
		setAns(order + 1, i);
}

int main() {

	
	cin >> m >> q;

	double temp;
	string tempStr;
	for (int i = 0; i < m; ++i)
		cin >> strArr[i+1];

	for (int i = 0; i < m; ++i) {
		cin >> temp;
		nextStr[0][i + 1] = log(temp);
	}
	
	for (int i = 0; i < m; ++i) 
		for (int j = 0; j < m; ++j) {
			cin >> temp;
			nextStr[i + 1][j + 1] = log(temp);
		}

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < m; ++j) {
			cin >> temp;
			isStr[i + 1][j + 1] = log(temp);
		}
	
	while(q--){
		
		cin >> n;

		for (int j = 0; j < n; ++j) {
			cin >> tempStr;
			for (int k = 0; k <= m; ++k) {
				if (strArr[k].compare(tempStr) == 0) {
					input[j] = k;
					break;
				}
			}

		}

		ans.clear();
		for (int j = 0; j < 102; ++j)
			for (int k = 0; k < 502; ++k) {
				dp[j][k] = 1;
				pickmat[j][k] = 0;
			}
		solve(0, 0);
		setAns(0, 0);

		for (int j = 0; j < ans.size(); ++j) {
			if (j != 0)
				cout << " " << strArr[ans[j]];
			else
				cout << strArr[ans[j]];
		}
		cout << endl;
	}

}