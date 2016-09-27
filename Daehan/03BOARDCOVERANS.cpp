#include <iostream>
#include <string>

using namespace std;

int insert(int **map, int row, int col, int free)
{

	//맨윗줄 맨왼쪽 구함
	int tx; //targetX
	int ty; //targetY
	for (int i = 1; i < row - 1; i++) {
		for (int j = 1; j < col - 1; j++) {
			if (map[i][j] == 1) {
				tx = j;
				ty = i;

				//exit
				i = row - 1;
				j = col - 1;
			}
		}
	}

	bool p1 = false; //패턴1 : 남, 동
	bool p2 = false; //패턴2 : 남, 남동
	bool p3 = false; //패턴3 : 동, 남동
	bool p4 = false; //패턴4 : 남, 남서

	if (map[ty + 1][tx] && map[ty][tx + 1]) p1 = true;
	if (map[ty + 1][tx] && map[ty + 1][tx + 1]) p2 = true;
	if (map[ty][tx + 1] && map[ty + 1][tx + 1]) p3 = true;
	if (map[ty + 1][tx] && map[ty + 1][tx - 1]) p4 = true;


	//만약 남은칸이 3이고, 채울 수 있는 형태이면, 1 반환
	if (free == 3) {
		if (p1 || p2 || p3 || p4)
			return 1;
		else
			return 0;
	}


	int count = 0;

	if (p1) {
		//채움
		map[ty][tx] = 0;
		map[ty + 1][tx] = 0;
		map[ty][tx + 1] = 0;
		//재귀호출
		count += insert(map, row, col, free - 3);
		//채운 것 취소
		map[ty][tx] = 1;
		map[ty + 1][tx] = 1;
		map[ty][tx + 1] = 1;
	}

	if (p2) {
		//채움
		map[ty][tx] = 0;
		map[ty + 1][tx] = 0;
		map[ty + 1][tx + 1] = 0;
		//재귀호출
		count += insert(map, row, col, free - 3);
		//채운 것 취소
		map[ty][tx] = 1;
		map[ty + 1][tx] = 1;
		map[ty + 1][tx + 1] = 1;
	}

	if (p3) {
		//채움
		map[ty][tx] = 0;
		map[ty][tx + 1] = 0;
		map[ty + 1][tx + 1] = 0;
		//재귀호출
		count += insert(map, row, col, free - 3);
		//채운 것 취소
		map[ty][tx] = 1;
		map[ty][tx + 1] = 1;
		map[ty + 1][tx + 1] = 1;
	}

	if (p4) {
		//채움
		map[ty][tx] = 0;
		map[ty + 1][tx] = 0;
		map[ty + 1][tx - 1] = 0;
		//재귀호출
		count += insert(map, row, col, free - 3);
		//채운 것 취소
		map[ty][tx] = 1;
		map[ty + 1][tx] = 1;
		map[ty + 1][tx - 1] = 1;
	}

	return count;
}

int main(void)
{
	int num;
	cin >> num;
	while (num--)
	{
		int row;
		int col;

		cin >> row >> col;
		row += 2;
		col += 2;
		//동적할당
		int **map = new int*[row];
		for (int i = 0; i < row; i++) {
			map[i] = new int[col];
			for (int j = 0; j < col; j++) {
				map[i][j] = 0;
			}
		}

		//입력받기
		for (int i = 0; i < row - 2; i++) {
			string str;
			cin >> str;
			for (int j = 0; j < col - 2; j++) {
				if (str[j] == '.') {
					map[i + 1][j + 1] = 1;
				}
			}
		}


		//자유영역 계산
		//만약 자유영역이 3의 배수가 아니면 기각
		int free = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] == 1)
					++free;
			}
		}

		int count;

		if (free == 0) {
			count = 1;
		}
		else if (free % 3 != 0) {
			count = 0;
		}
		else {
			count = insert(map, row, col, free);
		}
		cout << count << endl;

		for (int i = 0; i < row; i++) {
			delete[] map[i];
		}
		delete[] map;

	}
	return 0;
}
