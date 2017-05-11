#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

int n, l;
const double INF = 1e5;

double getMean(const vector<int>& v, int begin, int end){
    double mean=.0;
    for(int i = begin; i<end; ++i){
        mean += v[i];
    }
    mean /= (end - begin);
    return mean;
}

double getMinimumCost(vector<int>& v){

    double cost = INF;

    for(int length = l; length<=n; ++length){
        for(int begin = 0; begin <= n-length; ++begin){
            cost = min(getMean(v,begin,begin+length), cost);
        }
    }

    return cost;
}

int main() {

    int C;
    cin >> C;

    while(C--){
        cin >> n >> l;

        vector<int> costs(n);

        for(int i =0; i<n; ++i)
            cin >> costs[i];

        printf("%.11lf\n", getMinimumCost(costs));

    }
}
