#include <iostream>
#include <float.h>
#include <queue>
#include <stdio.h>
#include <vector>
#include <list>

using namespace std;

typedef struct node{
	int num;
	double weight;
	bool operator>(const node& other) const {return weight > other.weight;};
} node;

double min_dist(vector<list<node> > &nodelist, int num_vertex);


//void Print (const vector<double>& v){
//  //vector<int> v;
//  for (int i=0; i<v.size();i++){
//    cout << v[i] << endl;
//  }
//}
//
//void Print_list ( vector<list<node> >& v )
//{
//		for (int i=0; i<v.size();i++){
//			list<node>::iterator iter;
//			for(iter = v[i].begin() ; iter != v[i].end(); iter++)
//			{
//				cout << (*iter).num << " "<<(*iter).weight << "/ ";
//			}
//			cout << endl;
//		}
//}

int main(void)
{
	int num_case;

	cin >> num_case;

	while(num_case--)
	{
		int num_edge, num_vertex;
		cin >> num_vertex >> num_edge;
//		cout << "num_edge: " << num_edge << endl;
//		cout << "num_vertex: " << num_vertex << endl;
		vector<list<node> > nodelist(num_vertex);
		while(num_edge--)
		{
	//		cout<< "get input!"<<endl;

			int src,dst;
			double weight;

			cin >> src >> dst >> weight;
			nodelist[src].push_back({dst,weight});
			nodelist[dst].push_back({src,weight});
		}
	//	Print_list(nodelist );
		printf("%10lf\n", min_dist(nodelist, num_vertex));
	}
}


double min_dist(vector<list<node> > &nodelist, int num_vertex)
{
	//make weight table
	vector<double> dist(num_vertex, DBL_MAX);
	priority_queue<node, vector<node>, greater<node> > que;

	que.push({0,1.0});

	while(!que.empty())
	{
//		cout << "\nnew pop starting.." << endl;

		node curr = que.top();
		que.pop();
//		cout << "que pop:" << curr.num << endl;

//		if(curr.weight > dist[curr.num])
//			continue;

		list<node>::iterator iter;
		for(iter = nodelist[curr.num].begin();  iter != nodelist[curr.num].end() ; iter++)
		{
//			cout << "current node lists: " << (*iter).num << endl;
			if(curr.weight * (*iter).weight < dist[(*iter).num])
			{
				dist[(*iter).num] = curr.weight * (*iter).weight;
				que.push({(*iter).num, dist[(*iter).num] });
//				cout << "insert node to que: "<<(*iter).num << endl;
			}
		}
//		Print(dist);

	}

	return dist[num_vertex - 1];

}
