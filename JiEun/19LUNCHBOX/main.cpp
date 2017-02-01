#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;
int tc,cases,num,i;
int times[10001],eating[10001];
int pre_times, totalTime;

int main() {
	scanf("%d",&tc);
	for (cases = 0; cases < tc; cases++) {
		scanf("%d", &num);
		for (i = 0; i < num; i++) 
			scanf("%d", &times[i]);
		for (i = 0; i < num; i++) 
			scanf("%d", &eating[i]);
		vector<pair<int, int> > data;
		for (i = 0; i < num; i++)
			data.push_back(make_pair(eating[i], times[i]));
		sort(data.begin(), data.end());
		pre_times = data[num - 1].second;
		totalTime = 0;
		for (i = num - 1; i >= 0; i--) {
			totalTime = max(totalTime, pre_times + data[i].first);
			pre_times += data[i - 1].second;
		}
		printf("%d\n", totalTime);
	}
	return 0;
}
