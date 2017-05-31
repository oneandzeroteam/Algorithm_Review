#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <stdio.h>

using namespace std;
const int MAX_N = 100000;


vector<int> child[MAX_N];



struct RMQ{
	// 배열의 크기
	int n;
	// 각 구간의 최소치
	vector<int> rangeMin;
	RMQ(const vector<int>& array)
	{
		n = array.size();
		rangeMin.resize( n * 4 );
		// validate
//		cout << "height: ";
//		for(int i=0;i<n;i++)
//			printf("%d ",array[i]);
//		cout << endl;

		init(array, 0, n-1, 1);

		// validate
//		cout << "rangeMin: ";
//		for(int i=0;i<n*4;i++)
//			printf("%d ",rangeMin[i]);
//		cout << endl;

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

	//array[index] = new value로 바뀌었을때. node를 루트로 하는 구간 트리를 갱신하고 구간 최소치를 반환한다.
	int update(int index, int newValue, int node, int nodeleft, int noderight)
	{
		//index가 노드가 표현하는 구간과 상관이 없다.
		if(index < nodeleft || index > noderight)	return	rangeMin[node];

		//트리의 리프 노드까지 내려온 경우
		if(nodeleft == noderight)	return rangeMin[node] = newValue;

		int mid = (nodeleft + noderight) / 2;
		return min(update(index,newValue,node*2,nodeleft, mid), update(index, newValue, node*2+1, mid, noderight));
	}

//	void printrangeMin(void)
//	{
//		cout << "rangeMin: ";
//		for(int i=0;i<n*4;i++)
//			cout << rangeMin[i] << " ";
//		cout << endl;
//	}
};

int main(void)
{
	int T;
	vector<int> height;
	scanf("%d", &T);
	while(T--)
	{
		height.clear();
		int N, Q;
		int temp;
		scanf("%d %d",&N,&Q);
		height.resize(N);

		for(temp=0;temp<N;temp++)
		{
			//원래 등산로에 있는 표지판의 수 N개에 쓰인 고도 height
			scanf("%d",&height[temp]);
		}

		// validate
//		cout << "height: ";
//		for(int i=0;i<N;i++)
//			printf("%d ",height[i]);
//		cout << endl;

		// make RMQ
		struct RMQ *minRMQ = new RMQ(height);
		for(int i=0;i<N;i++)
			height[i] = -height[i];
		struct RMQ *maxRMQ = new RMQ(height);

		for(temp=0;temp<Q;temp++)
		{
			// 개방을 고려하고 있는 등산로의 시작 표지판, 끝 표지판.
			int start, end;
			scanf("%d %d",&start, &end);
			// start - end 사이의 최대 - 최소 값을 찾아야 한다.
			int MIN = minRMQ->query(start, end);
			int MAX = maxRMQ->query(start, end);
			printf("%d\n",-MAX-MIN);
		}
	}
}
