#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int tc,n,len,total;
int i, j;
int main() {
	scanf("%d", &tc);
	for (i = 0; i < tc; i++) {
		scanf("%d", &n);
		vector<int> length;
		for (j = 0; j < n; j++) {
			scanf("%d", &len);
			length.push_back(len);
		}
		total = 0; 
		for (j = 0; j < length.size()-1; j++) { // ※ sort가 for문안으로 들어가줘야함.
			sort(length.begin(), length.end());
			total += length[j+1] = length[j] + length[j + 1];
		}
		printf("%d\n", total);
	}
	return 0;
}