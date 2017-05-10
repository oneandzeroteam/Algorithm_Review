#include <iostream>
#include <vector>
#include <list>
#include <limits.h>
#include <queue>

using namespace std;

typedef struct node{
	int num;
	int weight;
	bool operator>(const node& other) const {return weight> other.weight;}
} node;


void Print (const vector<int>& v){
  //vector<int> v;
  for (int i=0; i<v.size();i++){
    //cout << v[i] << endl;
  }
}

void Print_list ( vector<list<node> >& v )
{
		for (int i=0; i<v.size();i++){
			list<node>::iterator iter;
			for(iter = v[i].begin() ; iter != v[i].end(); iter++)
			{
				//cout << (*iter).num << " "<<(*iter).weight << "/ ";
			}
			//cout << endl;
		}
}

vector<int> extinguishfire(vector<list<node> >& reachable, vector<int>& firestations,vector<int>& accidents,int num_vertex )
{
	vector<int> result(num_vertex,INT_MAX);
	priority_queue<node, vector<node>, greater<node> > pq;
	pq.push({num_vertex,0});

	while(!pq.empty())
	{
		node me = pq.top();
		pq.pop();

		list<node>::iterator iter;
		for(iter = reachable[me.num].begin(); iter != reachable[me.num].end() ; iter++)
		{
			if(me.weight + (*iter).weight < result[(*iter).num])
			{
				result[(*iter).num] = me.weight + (*iter).weight;
				pq.push({(*iter).num, result[(*iter).num]});
			}
		}

		Print(result);
	}

	return result;
}


int main(void)
{
	int num_case;
	cin >> num_case;
	//cout << "case :" << num_case << endl;
	while(num_case--)
	{
		int num_result;
		int num_vertex, num_edge, num_firestation, num_accident;
		cin >> num_vertex >> num_edge >> num_accident >> num_firestation;
		//cout << "echo " << num_vertex << "/ " <<num_edge<< "/ " <<num_accident<< "/ " <<num_firestation << "/ " << endl ;
		vector<list<node> > reachable(num_vertex+1);
		vector<int> firestations;
		vector<int> accidents;

		while(num_edge--)
		{
			int src, dst, weight;
			cin >> src >> dst >> weight;
			//cout << "echo: " << src << "/" << dst << "/" << weight << endl;
			reachable[src-1].push_back({dst-1, weight});
			reachable[dst-1].push_back({src-1, weight});
		}
		//cout << "push edge complete" << endl;

		int temp = num_accident;
		while (temp--)
		{
			int where;
			cin >> where;
			accidents.push_back(where-1);
		}
		temp = num_firestation;
		while (temp--)
		{
			int where;
			cin >> where;
			firestations.push_back(where-1);
		}

		// trick!
		for(int i =0; i<num_firestation; i++)
		{
			reachable[num_vertex].push_back({firestations[i], 0});
		}


		Print_list(reachable);

		// run dijkstra
		vector<int> result = extinguishfire(reachable,firestations, accidents, num_vertex );
		int sum = 0;
		// add
		for(int i =0;i<num_accident;i++)
		{
				sum += result[accidents[i]];
		}
		cout << sum << endl;
	}

}
