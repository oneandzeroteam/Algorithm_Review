#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <stdio.h>

using namespace std;
const int MAX_N = 100000;

vector<int> child[MAX_N];
int no2serial[MAX_N], serial2no[MAX_N];
// locTrip 각 노드가 트리에 처음 등장하는 위치, depth 각 노드의 깊이
int locTrip[MAX_N], depth[MAX_N];
int nextSerial;

struct RMQ{
	// 배열의 크기
	int n;
	// 각 구간의 최소치
	vector<int> rangeMin;
	RMQ(const vector<int>& array)
	{
		n = array.size();
		rangeMin.resize(n*4);
		// ?? explanation..
		init(array, 0, n-1, 1);
	}
	// node 가 array[left, right] 구간의 최소치를 표현할 때
	// node 를 루트로 하는 서브트리를 최소화하고, 이 구간의 최소치를 반환한다.
	int init(const vector<int>& array, int left, int right, int node)
	{
		if(left == right)
			return rangeMin[node] = array[left];
		int mid = (left + right) / 2;
		int leftMin = init(array, left, mid, node*2);
		int rightMin = init(array, mid+1, right, node*2+1);
		return rangeMin[node] = min(leftMin, rightMin);
	}

	// node가 표현하는 범위 array[nodeleft, noderight]가 주어질 때
	// 이 범위와 우리가 최소갑을 찾는 범위 array[left, right]의 교집합의 최소치를 구한다.
	int query(int left, int right, int node, int nodeleft, int noderight)
	{
		if(right < nodeleft || left > noderight)
			return INT_MAX;
		if(left <= nodeleft && right >= noderight)
			return rangeMin[node];
		int mid = (nodeleft + noderight) / 2;
		return min(query(left, right, node*2, nodeleft, mid),
				query(left, right, node*2+1, mid+1, noderight));
	}

	//query를 외부에서 호출하기 위한 인터페이스
	int query(int left, int right){
		return query(left, right, 1, 0, n-1);
	}

};

// 깊이 d인 here 노드 이하를 탐색한다.
void traverse(int here, int d, vector<int>& trip)
{
//cout << here << " ";
	no2serial[here] = nextSerial;
	serial2no[nextSerial] = here;
	nextSerial++;
	depth[here] = d;

	locTrip[here] = trip.size();
	trip.push_back(no2serial[here]);

	for(unsigned int i = 0; i< child[here].size(); i++)
	{
		traverse(child[here][i], d+1, trip);
		// 되돌아 올때도 trip에 추가.
		trip.push_back(no2serial[here]);
	}
}

int distance( struct RMQ* rmq, int u, int v) {
	int lu = locTrip[u] , lv = locTrip[v];
	if(lu > lv) swap(lu, lv) ;
	int lca = serial2no [rmq->query(lu, lv)];
	return depth[u] + depth[v] - 2 * depth[lca];
}

int main(void)
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		int N, Q;
		scanf("%d %d",&N,&Q);
		for(int i=1;i<N;i++)
		{
			int temp1;
			scanf("%d", &temp1);
			child[temp1].push_back(i);
		}

		//prepare RMQ
		nextSerial = 0;
		vector<int> trip;
		traverse(0, 0, trip);
		struct RMQ *myRMQ = new RMQ(trip);

		//debugging print no2serial and serial2no
//		cout << "\n serial2no:";
//		for(int i=0;i<N;i++)
//			cout << serial2no[i] << " ";
//		cout << endl;
//
//		cout << "\n no2serial:";
//		for(int i=0;i<N;i++)
//			cout << no2serial[i] << " ";
//		cout << endl;
//
//		cout << "\n depth:";
//		for(int i=0;i<N;i++)
//			cout << depth[i] << " ";
//		cout << endl;
//
//		cout << "\n locTrip:";
//		for(int i=0;i<N;i++)
//			cout << locTrip[i] << " ";
//		cout << endl;
//
//		cout << "\n trip:";
//		for(int i=0;i<2*N-1;i++)
//			cout << trip[i] << " ";
//		cout << endl;

		for(int i=0;i<Q;i++)
		{
			int start,end;
			scanf("%d %d", &start,&end);
			printf("%d\n",distance(myRMQ, start, end));

		}

		//clear... must do this
		for(int i=0;i<N;i++)
			child[i].clear();

	}
}
