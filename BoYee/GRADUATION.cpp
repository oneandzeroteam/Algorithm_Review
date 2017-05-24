#include <iostream>
#include <string.h>
#include <limits.h>
#include <stdio.h>

using namespace std;
#define INF 987654321

int m, k, n, l;
int pre[12];
int classes[10];
int cache[10][1<<12];

int MIN(int a, int b)
{
	if(a > b)
		return b;
	else
		return a;
}

void print_go(void)
{
	cout << "pre:"<<endl;
	for(int i =0;i<12;i++)
	{
		printf("%08x\n",pre[i]);
	}


	cout << "classes:"<<endl;
	for(int i =0;i<10;i++)
	{
		printf("%08x\n",classes[i]);
	}

}

int bitCount(int n)
{
	if(n == 0) return 0;
	//check last bit only.. and recursive call
	return n%2 + bitCount(n/2);
}

int least_semester(int semester, int taken)
{
	int ret;
//	printf("count taken : %d, %x\n",bitCount(taken),taken );
	if(bitCount(taken) >= k) // 다 들었다!
	{
	//	printf("possible branch!\n");
		return 0;
	}
	if(semester == m) // 학기 다 끝남..
	{
	//	printf("semester: %d\n",semester);
		return INF;
	}
//	int& ret = cache[semester][taken];
//	if(ret != -1) return ret;
//		ret = INF;

	ret  = INF;

	//열리는 과목 중에서 안들은것
	int canTake = (classes[semester] & ~taken);

	for(int i =0; i<n;i++)
	{
		// i 번째 과목을 들을 수 있는지 && i 번째 과목을 다 들었는지
		if( (canTake & (1 << i)) && ((taken & pre[i]) != pre[i]) )
		{
			canTake = canTake & ~ (1 << i);
		}
	}

	//printf("cantake : %x", canTake);
	int take;
	for(take = canTake; take > 0; take = (take -1) & canTake)
	{
		// l 과목 초과하여 듣는 경우
		if(bitCount(take) > l) continue;
	//	printf("before ret %d /",ret);
		ret = MIN(ret, least_semester( semester + 1, taken | take) + 1 );
	//	printf("after ret %d\n",ret);
	}

//	printf("before ret %d /",ret);
	// 이번 학기에는 아무것도 듣지 않는다.
	ret = MIN(ret, least_semester(semester + 1, taken));
//	printf("after ret %d\n",ret);

//	printf("cantake : %x, take : %d, ret: %d\n",canTake ,take ,ret);
	return ret;
}

int main (void)
{

	int testCase;

	cin >> testCase;
	while(testCase--)
	{
		memset(pre,0,sizeof(pre));
		memset(classes,0,sizeof(classes));
		memset(cache, -1, sizeof(cache));
		// n 전공 과목의 수 k 들어야 할 과목의 수 m 학기의 수 l 한 학기에 들을 수 있는 최대 과목의 수
		cin >> n >> k >> m >> l;

		// 해당 과목의 선수 과목 개수, 과목 번호
		int temp_n = 0;
		while(temp_n != n)
		{
			int pre_num;
			cin >> pre_num;
			int temp_pre = pre_num;
			while(temp_pre--)
			{
				int aa;
				cin >> aa;
				pre[temp_n] |= 1<<aa;
			}
			temp_n++;
		}

		int temp_m = 0;
		while(temp_m != m)
		{
			int semester_course_num;
			cin >> semester_course_num;
			int temp_semester_course_num = semester_course_num;
			while(temp_semester_course_num--)
			{
				int aa;
				cin >> aa;
				classes[temp_m] |= 1<<aa;
			}
			temp_m++;
		}

		//test
		//print_go();
		int all = least_semester(0, 0);
		if(all == INF)
		{
			cout <<  "IMPOSSIBLE"<< endl;
		}
		else
			cout << all << endl;
	}
	return 0;
}
