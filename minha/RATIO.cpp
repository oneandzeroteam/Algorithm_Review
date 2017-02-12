#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//최대 판 횟수 
int long long L = 200000000;

int N, M;

// 승률 구하는 함수 
int ratio(long long G, long long W)
{
	return (W * 100) / G;
}

//몇 판을 해야 승률이 1% 오를까 구하는 함수 
int neededgames(long long games, long long won)
{
	//불가능한 경우를 미리 걸러낸다
	if (ratio(games, won) == ratio(games + L, won + L))
		return -1;

	long long lo = 0, hi = L;
	long long mid;
	while (lo + 1 < hi) 
	{
		mid = (lo + hi) / 2;
		//만약 현재 승률이 (+mid한것보다 높거나 같다면 
		if (ratio(games, won) >= ratio(games + mid, won + mid))
			lo = mid;
		//만약 현재 승률이 (+mid)판한것보다 낮다면 
		else if (ratio(games, won) < ratio(games + mid, won + mid))
			hi = mid;
	}
	return hi;
}

int main()
{
	//input 1. 테스트 케이스 수 
	int cases;
	cin >> cases;

	for (int cc = 0; cc < cases; ++cc)
	{
		//input 2. N: 현재 게임 횟수
		//input 3. M: 현재 이긴 게임 횟수  
		cin >> N >> M;
		//outpu 1. 승률 1% 올리려면 몇판 더 해야하는지 
		cout << neededgames(N, M) << endl;
	}
}

