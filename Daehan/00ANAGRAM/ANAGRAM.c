/*
/*PASSWORD_PROBLEM @ Algospot
/*You can copy, distribute or publish all these things as they are,
/*but are not allowed to modify for redistribution purpose.
/*All rights reserved. PeterDaehanKim.
/*Created at 9/16/2016
/*Link : https://www.algospot.com/judge/problem/read/ANAGRAM
/**************************************************************************/

#include <stdio.h>
#include <string.h>
#pragma warning (disable:4996)

int PassedVer(char*, char*);
void GetAlphabetic(char *, char*);

int main(void)
{
	int n, i;
	char str1[10][100] = { 0 }, str2[10][100] = { 0 }; //초기화



	scanf("%d", &n);// 테스트 케이스 개수를 받는다. 10개 이상이면 에러남.

	for (i = 0; i < n; i++)
	{
		scanf("%s %s", str1[i], str2[i]);

	}


	//검사
	for (i = 0; i < n; i++)
	{
		if (PassedVer(str1[i], str2[i])) printf("Yes\n");
		else printf("No.\n");

	}


	return 0;
}

int PassedVer(char* str1, char* str2) {

	char tempstr[2][100];

	if (!strcmp(str1, str2) || (strlen(str1) != strlen(str2))) return 0; //두 문장이 아예 같으면 잘못된 암호 생성이므로 false
																		 //문장 길이가 다르면 false
	else {
		//문장 길이가 같으면 알파벳 순서로 스트링을 정리한 후 같은지 비교한다.
		GetAlphabetic(str1, tempstr[0]);
		GetAlphabetic(str2, tempstr[1]);

		if (!strcmp(tempstr[0], tempstr[1])) return 1;
		else return 0;
	}

}

void GetAlphabetic(char *original_str, char* str_gotten) {

	char temp;
	char tempstr[100];
	int i, j;

	strcpy(tempstr, original_str);
	for (i = 0; i < 100; i++) { //버블 소트
		for (j = 0; j < 99; j++)
			if (tempstr[j] < tempstr[j + 1]) {
				temp = tempstr[j];
				tempstr[j] = tempstr[j + 1];
				tempstr[j + 1] = temp;
			}
	}

	strcpy(str_gotten, tempstr);
}