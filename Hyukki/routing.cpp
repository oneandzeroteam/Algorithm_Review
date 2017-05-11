#include<iostream>
#include<iomanip>
#include<vector>
#include<float.h>
#include<list>
#include<queue>
using namespace std;

typedef struct info{
double noise;
int nodeNum;

bool operator>(const info& other) const { return noise > other.noise; }
}info;

double minNoise(vector<list<info> >& noiseList, int nComputer);

int main(){
int testCase;
cin >> testCase;

while(testCase--){
int nComputer, nLine;
cin >> nComputer >> nLine;

vector<list<info> > noiseList(nComputer);
for(int i=0; i<nLine; i++){
int src, dst;
double noise;
cin >> src >> dst >> noise;
noiseList[src].push_back({noise, dst});
noiseList[dst].push_back({noise, src});
}

cout<<fixed<<setprecision(10)<<minNoise(noiseList, nComputer)<<endl;
}

return 0;
}
double minNoise(vector<list<info> >& noiseList, int nComputer){
vector<double> reachNoise(nComputer, DBL_MAX);

reachNoise[0] = 1;

priority_queue<info, vector<info>, greater<info> > pq;
pq.push({1.0, 0});

while(!pq.empty()){
info curr = pq.top();
pq.pop();

if(curr.noise > reachNoise[curr.nodeNum])
continue;

list<info>::iterator iter;
for(iter = noiseList[curr.nodeNum].begin(); iter != noiseList[curr.nodeNum].end(); iter++){
if( curr.noise * iter->noise < reachNoise[iter->nodeNum]){
reachNoise[iter->nodeNum] = curr.noise * iter->noise;
pq.push({reachNoise[iter->nodeNum], iter->nodeNum});
}
}
}

return reachNoise[nComputer-1];
}
