#include <iostream>
#include <list>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <stdio.h>

using namespace std;

typedef struct my_node{
	double x;
	double y;
} my_node;

//
//
//void Print_list ( vector<list<my_node> >& v )
//{
//		for (int i=0; i<v.size();i++){
//			list<my_node>::iterator iter;
//			cout << "from: " << i << endl;
//			for(iter = v[i].begin() ; iter != v[i].end(); iter++)
//			{
//
//				cout << (*iter).x << " "<<(*iter).y <<"/ ";
//			}
//			cout << endl;
//		}
//}
//void Print (const vector<my_node>& v){
//  //vector<int> v;
//  for (int i=0; i<v.size();i++){
//    cout << v[i].x << " " << v[i].y << "/ ";
//  }
//  cout << endl;
//}


// A utility function to find the vertex with minimum key value, from
// the set of vertices not yet included in MST
int minKey(double key[], bool mstSet[], int buildings_num)
{
   // Initialize min value
   int min = INT_MAX, min_index;

   for (int v = 0; v < buildings_num; v++)
     if (mstSet[v] == false && key[v] < min)
         min = key[v], min_index = v;

   return min_index;
}

double calcdistance(my_node a1, my_node a2)
{
	return sqrt( pow( a1.x - a2.x, 2 )+ pow( a1.y - a2.y, 2 ) );
}

double calculate(double cables[501][501], vector<my_node>& buildings, int buildings_num, int cables_num)
{
	double sum;

	int parents[501];
	double key[501];
	bool mstSet[501];

    // Initialize all keys as INFINITE
    for (int i = 0; i < buildings_num; i++)
       key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parents[0] = -1;

    for(int count = 0; count < buildings_num -1; count ++)
    {
    	// find the building which is not included in MST and has minimum key value...
    	int u = minKey(key, mstSet, buildings_num);
    	mstSet[u] = true;


    	for(int v=0; v<buildings_num;v++)
    	{
    		if( mstSet[v] == false && cables[u][v] < key[v] )
    		{
    			parents[v] = u;
    			key[v] = cables[u][v];
    		}
    	}
    }

    sum=0;
    for(int i = 1; i<buildings_num;i++)
    {
    	sum += cables[i][parents[i]];
    }
    return sum;
}

int main(void)
{
	int n;

	cin >> n;

	while(n--)
	{
		int buildings_num, cables_num;
		cin >>	buildings_num;
		cin >> 	cables_num;
		vector<my_node> buildings(buildings_num);
		double cables[501][501];
	//	cout << "building number: " << buildings_num << endl;
	//	cout << "cable number: " << cables_num << endl;

		int temp = 0;
		while(temp < buildings_num)
		{
			cin >> buildings[temp].x;
			temp++;
		}

		temp = 0;
		while(temp < buildings_num)
		{
			cin >> buildings[temp].y;
			temp++;
		}

		for(int i = 0;i<buildings_num;i++)
			for(int j = 0;j<buildings_num;j++)
			{
				double length = calcdistance(buildings[i], buildings[j]);
				cables[i][j] = length;
				cables[j][i] = length;
			}

		temp = cables_num;
		while(temp--)
		{
			int x,y;
			cin >> x;
			cin >> y;
			cables[x][y] = 0;
			cables[y][x] = 0;
		}

		double result = calculate(cables, buildings, buildings_num, cables_num);
		printf("%f\n",result);

	}

	return 0;
}
