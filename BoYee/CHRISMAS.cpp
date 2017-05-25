#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N,K;
int *psum;
long long*count;
int *ret;
int *prev;

int MAX(int a , int b)
{
	if( a > b)
		return a;
	else
		return b;
}

int check(void)
{
	const int MOD = 20091101;
	int ret=0;
	count = (long long*)calloc( K,sizeof(long long) );

	for(int i =0;i<N+1;i++)
	{
		count[psum[i]]++;
	}

	for (int i =0;i<K;i++)
	{
		if(count[i] >= 2)
		{
			// (a + b + c + d + e) mode k  ==  (((((a mod k) + b ) mod k + c ) mod k + d ) mod k + e ) mod k
			ret= (ret + count[i] * (count[i] - 1) / 2) % MOD;
		}
	}

	free(count);
	return ret;
}

int check2(void)
{
	//ret[i] 첫 번째 상자부터 i 번째 상자까지 고려했을 때 끊어 구매 가능한 최대 횟수.
	//prev[s] 는 psum 이 s 였던 마지막 위치.
	ret = (int *) calloc( N+1, sizeof( int ) );
	prev = (int *) malloc( sizeof(int) * K );
	for(int i = 0; i<K;i++) prev[i] = -1;

	for(int i = 0; i<N+1;i++)
	{
		//cout << i << endl;
		// i 상자 skip
		if(i>0)
			ret[i] = ret[i-1];
		else
			ret[i] = 0;

		int loc = prev[psum[i]];
		// 만약 이전에 psum[i]를 본 적이 있다면, 가장 최근의 위치가 prev[psum[i]]에 저장되어 있을 것이다.
		// prev[psum[i]]+1 부터 i까지 쭉 사보자.
		// prev[psum[i]] 까지 최대 횟수는 ret[prev[psum[i]]]에 저장되어 있을 것.
		if(loc != -1)
		{
			// ret[i] 은 i번째 고려하지 않은 경우.
			ret[i] = MAX(ret[i], ret[loc] + 1);

		}
		prev[psum[i]] = i;
	}

	int result = ret[N];
	free(ret);
	free(prev);
		return result;

}

int main(void)
{
	int testCase;
	std::cin >> testCase;
	while(testCase--)
	{

		std::cin >> N >> K;
		//printf("N: %d K: %d\n",N,K);
		psum = (int *)malloc( sizeof(int)*(N+1));

		//make psum
		int temp;
		psum[0] = 0;
		std::cin >> temp;
		psum[1] = temp % K;


		for(int i = 2; i< N+1; i++)
		{	std::cin >> temp;	psum[i] = (psum[i-1] + temp) % K;	}


		std::cout << check() << " " << check2() <<std::endl;

		free(psum);

	}

	return 0;
}
