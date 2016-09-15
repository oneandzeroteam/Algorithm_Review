#include <stdio.h>
#include <string.h>

#pragma warning(disable:4996)

int n, m;
int edges[11][11];

int checkBoard[11];
int count;

void getPossibleCount() {
	/* pick p1 */
	int p1 = -1;
	for (int i = 0; i < n; i++) {
		if (checkBoard[i] == -1) {
			p1 = i;
			checkBoard[p1]++;
			break;
		}
	}

	// Finally, possible case was just found. count++
	if (p1 == -1) {
		count++;
		return;
	}

	/* pick p2 */
	for (int i = 0; i < n; i++) {
		if ((edges[p1][i] == 1) && (checkBoard[i] == -1)) {
			checkBoard[i]++;
			getPossibleCount();
			checkBoard[i]--;
		}
	}

	checkBoard[p1]--;
}

int main() {
	int C;
	scanf("%d", &C);

	for (int i = 0; i < C; i++) {
		scanf("%d %d", &n, &m);

		// get edges
		memset(edges, -1, sizeof(edges));
		for (int j = 0; j < m; j++) {
			int p1, p2;
			scanf("%d %d", &p1, &p2);

			edges[p1][p2] = edges[p2][p1] = 1;
		}

		// 
		memset(checkBoard, -1, sizeof(checkBoard));
		count = 0;
		getPossibleCount();
		printf("%d\n", count);
	}

	return 0;
}
