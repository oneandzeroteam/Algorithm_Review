/*
/*PASSWORD_PROBLEM @ Algospot
/*You can copy, distribute or publish all these things as they are,
/*but are not allowed to modify for redistribution purpose.
/*All rights reserved. PeterDaehanKim.
/*Created at 9/21/2016
/**************************************************************************/

#include <stdio.h>
#include <math.h>
#pragma warning(disable:4996)

int find_index_of_min_in_array(double arr[],int index[])
{
	double temp = arr[0];
	int i, cnt=0;
	
	for (i = 0; i < 100; i++){
		if (arr[i] < temp){	
			temp = arr[i];
		}
	}
	//미니멈 값이 temp에 들어가 있다.

	for (i = 0; i < 100; i++) {
		if (fabs(temp - arr[i])<0.001) {
			index[cnt] = i;
			cnt++;
		}
	}
	//미니멈 값을 갖는 인덱스들을 모두 찾아 index array에 작은 순서대로 기록하고 개수를 세서 반환한다.

	return cnt;
}
//이 함수는 배열을 받아 최솟값의 개수를 반환하고, 두번째 인자로 들어간 배열에 최솟값의 인덱스들을 반환한다.

int set_direction(double arr[], int index, int num_artist) {

	int i;

	if (index == 0) return 1;
	else if (arr[index - 1] < arr[index + num_artist]) return 0;//왼쪽
	else if (arr[index - 1] > arr[index + num_artist]) return 1;//오른쪽
	else {//두 어레이가 같으면 한쪽이 커질때까지 스캔해서 작은 쪽 방향을 리턴
		for (i = 2; i < 100; i++) {
			if (arr[index - i] > arr[index + num_artist + i - 1])  return 1;
			else if (arr[index - i] < arr[index + num_artist + i - 1]) return 0;

		}			//만약 어레이의 끝에 도달하면 더 긴쪽 방향을 리턴
	}
}
//이 함수는 배열과 아티스트 수를 받아 평균을 구할 방향을 설정한다.(오른쪽 1, 왼쪽 0)

void get_aver_ext(double aver[], double cost_for[], double aver_ext[], int num_artist) {
	int i, j;
	int num_min_aver;
	int min_idx[100];

	num_min_aver = find_index_of_min_in_array(aver, min_idx);
	//aver의 min의 개수를 조사한다.

	for (i = 0; i < num_min_aver; i++) {
		int direction_right;
		double new_aver;

		direction_right = set_direction(cost_for, min_idx[i], num_artist);
		//min_idx[i]에 대해 방향 설정
		for (j = 0; j < 100; j++) {
			//여기에서 aver_ext[min_idx[i]]를 계산하는 것.
			if (direction_right) {
				if (aver_ext[min_idx[i]] < cost_for[min_idx[i] + num_artist + j]) break;
				else {//new_aver에 더 작은 평균값을 찾아 넣고 그것을 aver_ext에 옮긴다.
					new_aver = aver_ext[min_idx[i]] * (num_artist + j);
					new_aver += cost_for[min_idx[i] + num_artist + j];
					new_aver /= (double)(num_artist + j + 1);
					aver_ext[min_idx[i]] = new_aver;
				}
			}
			else {
				if (aver_ext[min_idx[i]] < cost_for[min_idx[i] - j - 1]) break;
				else {//new_aver에 더 작은 평균값을 찾아 넣고 그것을 aver_ext에 옮긴다.
					if (min_idx[i] - j == 0) break; // 맨 앞일 경우 루프 탈출.
					new_aver = aver_ext[min_idx[i]] * (num_artist + j);
					new_aver += cost_for[min_idx[i] - j - 1];
					new_aver /= (num_artist + j + 1);
					aver_ext[min_idx[i]] = new_aver;
				}
			}
		}


	}
}
//이 함수는 aver_ext를 완성한다. 
	
int main(void) {

	int num_testcase;
	int num_day[100];
	int num_artist[100];
	double cost_for[100][100]; //case개수 , 데이터 개수로 100 by 100이다.
	double aver[100][100];
	double aver_ext[100][100];
	int i,k;
	int min_idx[100][100] = { 0 };//aver 배열의 min index 정의, 0으로 초기화.
	int min_idx_ext[100][100] = { 0 };


	scanf("%d", &num_testcase);
	//테스트 케이스의 수를 받는다.
	
	for (k = 0; k < num_testcase; k++) {
		scanf("%d %d", &num_day[k], &num_artist[k]);
		//가능한 날수와 최소 아티스트 수를 받는다.
		getchar();

		for (i=0 ; i < 100; i++)
			cost_for[k][i] = 10000;
		for (i = 0; i < num_day[k]; i++)
			scanf("%lf", &cost_for[k][i]);
		//각각의 날짜의 공연비용을 스캔하고, 99까지의 나머지 공간에는 큰 수를 집어넣는다.

		for (i = 0; i <= num_day[k] - num_artist[k] + 1; i++)
		{
			double average_of_costs = 0.0;
			int j;
			for (j = 0; j < num_artist[k]; j++)
				average_of_costs += cost_for[k][i+j];
			average_of_costs /= (double)num_artist[k];
			aver[k][i] = average_of_costs;

		}
		for (i = num_day[k] - num_artist[k] + 1; i < 100; i++) aver[k][i] = 10000;
		//L개의 평균을 aver 배열에 담고 나머지 공간에는 큰 수를 집어넣는다.
		

		for (i = 0; i < 100; i++) aver_ext[k][i] = aver[k][i];
		//aver_ext 배열은 일단 aver과 같게 만든 후 나중에 수정.

		get_aver_ext(aver[k], cost_for[k], aver_ext[k], num_artist[k]);

		find_index_of_min_in_array(aver_ext[k], min_idx_ext[k]);
	}
	

	for (k = 0; k < num_testcase; k++)
		printf("%lf\n", aver_ext[k][min_idx_ext[k][0]]);

	return 0;
}