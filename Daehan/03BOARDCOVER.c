/***********************************************/
/*Boardcover @ Algospot
/*You can copy, distribute or publish all these things as they are,
/*but are not allowed to modify for redistribution purpose.
/*All rights reserved. PeterKim. 
/*Contact : kdh5852@gmail.com
/*Created at : 9/24/2016
/************************************************/


#include <stdio.h>
#include <stdbool.h>
#pragma warning(disable:4996)

int search(bool map[][6], int empty_space) {

	int way=0;
	int i, j;
	int x, y;

	bool block1 = false;
	bool block2 = false;
	bool block3 = false;
	bool block4 = false;


	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++) {
			if (!(map[i][j])) {
				x = i; y = j;

				i = 4; j =4;
			}
		}

	if (map[x][y + 1] == 0 && map[x + 1][y + 1] == 0) block1 = true;
	if (map[x+1][y] == 0 && map[x + 1][y -1] == 0) block2 = true;
	if (map[x+1][y] == 0 && map[x + 1][y + 1] == 0) block3 = true;
	if (map[x+1][y] == 0 && map[x][y + 1] == 0) block4 = true;


	if (empty_space % 3 != 0) return 0;
	if (empty_space == 3) {
		if (block1 || block2 || block3 || block4) return 1;
		else return 0;
	}
	// if you can fit a block at the first place, 
	// then do it and recur the function.



	//첫번째 블럭을 끼울 수 있으면 끼우고 재귀를 돌려라.
	if (block1) {

		map[x][y] = 1;
		map[x][y + 1] = 1;
		map[x + 1][y + 1] = 1;

		way += search(map, empty_space - 3);

		map[x][y] = 0;
		map[x][y + 1] = 0;
		map[x + 1][y + 1] = 0;

	}

	//두번째 블럭을 끼울 수 있으면 끼우고 재귀를 돌려라.
	if (block2) {

		map[x][y] = 1;
		map[x][y + 1] = 1;
		map[x -1][y - 1] = 1;

		way += search(map, empty_space - 3);

		map[x][y] = 0;
		map[x][y + 1] = 0;
		map[x - 1][y - 1] = 0;

	}
	//세번째 블럭을 끼울 수 있으면 끼우고 재귀를 돌려라.
	if (block3) {

		map[x][y] = 1;
		map[x+1][y + 1] = 1;
		map[x + 1][y] = 1;

		way += search(map, empty_space - 3);

		map[x][y] = 0;
		map[x+1][y + 1] = 0;
		map[x + 1][y] = 0;

	}
	//네번째 블럭을 끼울 수 있으면 끼우고 재귀를 돌려라.
	if (block4) {

		map[x][y] = 1;
		map[x][y + 1] = 1;
		map[x + 1][y] = 1;

		way += search(map, empty_space - 3);

		map[x][y] = 0;
		map[x][y + 1] = 0;
		map[x + 1][y] = 0;

	}



	return way;
}

int main(void) {
	
	bool map[6][6];

	int i,j;
	int way;

	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
			map[i][j] = false;
	//일단 6x6 맵이 다 비어있다고 가정해보자. 
	
	way = search(map, 36);
	
	printf("%d", way);


	return 0;
}
