#include <stdio.h>
#include <stdbool.h>
#define N 10

int num_of_people, num_of_pairs, num_of_cases, c_idx, m_idx;
bool matched[N] = { 0 };
bool relation_matrix[N][N] = { 0 };

int calculate_cases(int cnt, int total, int* way) {
	int i, j;
	if (cnt == total) return 1;

	//매칭 시킬 학생 선택 : i
	for (i = 0; i < num_of_people; i++)
		if (matched[i] == 0) break; 

	for (j = i + 1; j < num_of_people; j++) {

		if (matched[j] == 1) continue; // 짝이 이미 있으면 패스
		if (relation_matrix[i][j] == 1 && relation_matrix[j][i] == 1)
		{
			matched[i] = matched[j] = 1;
			if (1 == calculate_cases(cnt + 2, total, way))
				(*way)++;
			matched[i] = matched[j] = 0;

		}

	}

	return 0;
}

int main(void) {
	int i, j;
	scanf("%d", &num_of_cases);
	for (c_idx = 0; c_idx < num_of_cases; c_idx++) {

		scanf("%d %d", &num_of_people, &num_of_pairs);

		//친구 관계 행렬 설정
		for (i = 0; i < num_of_people; i++)
			for (j = 0; j < num_of_people; j++)
				relation_matrix[i][j] = 0;

		for (m_idx = 0; m_idx < num_of_pairs; m_idx++) {

			int i, j;
			scanf("%d %d", &i, &j);
			relation_matrix[i][j] = 1;
			relation_matrix[j][i] = 1;

		}

		// 매칭 행렬 설정
		for (i = 0; i < 10; i++) matched[i] = 0;
		int way = 0;
		calculate_cases(0, num_of_people, &way);
		printf("%d\n", way);

	}



	return 0;
}
