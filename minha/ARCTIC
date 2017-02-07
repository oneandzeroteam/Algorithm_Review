#include <iostream>
#include <cstdio> 
#include <cstring>
#include <cmath> 

#include <set> 
#include <queue>

using namespace std; 

typedef struct {
	double x, y;
} point_t;

const int MAX_V = 100;
const double MAX_DIST = 1000.0; 

int n; 

double d[MAX_V][MAX_V];

point_t pt[MAX_V];

double getDist(point_t p1, point_t p2)
{
	double x = p1.x - p2.x;
	double y = p1.y - p2.y; 

	return sqrt(x*x + y*y);
}

//거리 dist 이하인 기지들만을 연결했을 때, 모든 기지가 연결되는지 여부를 반환한다. 
bool decision(double dist)
{
	queue<int> q;		// 방문한 nodes/기지들 들어갈 queue 
	set<int> vset;		// nodes/기지들 집합 
	pair <set <int>::iterator, bool> visited; 

	q.push(0); 
	vset.insert(0); 
	
	while (!q.empty()) 
	{
		int here = q.front(); 
		q.pop(); 
		
		for (int there = 0; there < n; there++) 
		{	

			if (there != here && d[here][there] <= dist) 
			{
				visited = vset.insert(there);
				if (visited.second == true)  
				{
					q.push(there); // 방문한 기지/nodes 삽입  
				}
				if (vset.size() == n) //모든 기지들/nodes 방문함 
				{
					return true; 
				}
			}
		}
	}
	
	return false; 
}

//모든 기지를 연결할 수 있는 최소의 dist 를 반환한다. 
int main()
{
	int c; 
	cin >> c;

	while (c--)
	{
		cin >> n; 
		for (int i = 0; i < n; i++)
		{
			cin >> pt[i].x >> pt[i].y; 
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = i; j < n; j++)
			{
				double dist = getDist(pt[i], pt[j]);
				d[i][j] = dist; 
				d[j][i] = dist; 
			}
		}
		double lo = 0, hi = MAX_DIST;
		double mid, ans = 0.0; 

		while (hi > lo + 0.0001)
		{	
			mid = (lo + hi) / 2;
			//전파의 출력이 mid  값인 경우, 모든 노드들이 연락을 주고 받을 수 있다. 
			//mid 이 가능하다면, 더 좋은 (작은) 답을 찾는다. 
			if (decision(mid)) {
				hi = mid;
				ans = mid;
			}
			//mid 이 불가능하다면, 더 큰 답을 찾는다. 
			else {
				lo = mid;
			}
		}

		cout << fixed; 
		cout.precision(2);
		cout << ans << endl; 
	}

	return 0;
}
