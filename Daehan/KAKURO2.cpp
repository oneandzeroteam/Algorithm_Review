#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int map[21][21];
int Q;

struct query
{
	int y, x, d, sum, visit;
	int cnt;

	query(int Y, int X, int D, int S) : y(Y), x(X), d(D), sum(S), visit(0), cnt(0) {}

	void push(int idx)
	{
		visit |= 1 << idx;
		sum -= idx;
		cnt--;
	}

	void pop(int idx)
	{
		visit ^= 1 << idx;
		sum += idx;
		cnt++;
	}
};

vector<query> hint;
int hintIdx[21][21][2];

vector<pair<int, int> > dot;

bool complete;

void solve(int pos)
{
	if (complete)
		return;
	if (pos == dot.size())
	{
		complete = true;
		return;
	}

	//x,y좌표를 각각 reference type으로 잡는다
	const int& y = dot[pos].first;
	const int& x = dot[pos].second;

	query& hintH = hint[hintIdx[y][x][1]]; // (y,x)의 세로힌트
	query& hintW = hint[hintIdx[y][x][0]]; // (y,x)의 가로힌트

	int visit = hintH.visit | hintW.visit;  // visit은 지금까지 채운 숫자들의 집합을 bit mask로 표현함.

	for (int i = 1; i <= 9 && hintH.sum >= i && hintW.sum >= i; i++)
	{// 원소 i가 이미 들어가 있다면
		if ((visit & (1 << i)) == 0)
		{
			
			if (hintH.cnt == 1 && hintH.sum != i)
				continue;
			if (hintW.cnt == 1 && hintW.sum != i)
				continue;

			hintH.push(i);
			hintW.push(i);

			map[y][x] = i;
			solve(pos + 1);

			if (complete)
				return;

			hintH.pop(i);
			hintW.pop(i);
		}
	}
}

int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		hint.clear();
		dot.clear();
		complete = false;

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
				if (map[i][j] == 1)// dot은 빈칸만 집어넣음.
					dot.push_back(make_pair(i, j));
			}
		}

		cin >> Q;
		for (int i = 0; i < Q; i++)
		{
			int y, x, d, s;
			cin >> y >> x >> d >> s;
			hint.push_back(query(y - 1, x - 1, d, s));
		}
		// 힌트 벡터에 들어가있는 힌트들을 순회하면서 각각 몇개의 빈칸을 홀드하고 있는지 센다.
		for (int i = 0; i < Q; i++)
		{
			int y = hint[i].y;
			int x = hint[i].x;
			if (hint[i].d == 0)
				for (int j = x + 1; map[y][j] == 1; j++)
				{
					hintIdx[y][j][0] = i;
					hint[i].cnt++;
				}
			else
				for (int j = y + 1; map[j][x] == 1; j++)
				{
					hintIdx[j][x][1] = i;
					hint[i].cnt++;
				}
		}
		//맵 채우기
		solve(0);

		//맵 출력
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << map[i][j] << " ";
			cout << '\n';
		}
	}
	return 0;
}
