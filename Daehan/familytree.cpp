#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX_INT = numeric_limits<int>::max();
const int MAX_N = 100000;
int n,q;

vector<int> child[MAX_N];
int no2serial[MAX_N], serial2no[MAX_N];

int locInTrip[MAX_N],depth[MAX_N];

int nextSerial;

struct RMQ {
    int n;

    //최소 차이와 그 차이를 갖게 하는 min,max를 저장.
    vector<int> rangeMin;

    RMQ(const vector<int>& array){
        n = array.size();
        vector<int> i_array(n);
        for(int i=0; i<n; ++i)
            i_array[i] = -array[i];
        rangeMin.resize(n*4);
        init(rangeMin,array,0,n-1,1);

    }

    int init(vector<int>& toInit,const vector<int>& array, int left, int right, int node){
        if(left == right) {
            return toInit[node]=array[left];
        }

        int mid = (left+right)/2;
        int leftMin = init(toInit,array,left,mid,node*2);
        int rightMin = init(toInit,array,mid+1,right,node*2+1);

        return toInit[node] = min(leftMin,rightMin);
    }


    int query(const vector<int>& toQuery,int left, int right, int node, int nodeLeft, int nodeRight){
        if(left > nodeRight || right < nodeLeft){
            return MAX_INT;
        }

        if(left <= nodeLeft && nodeRight <= right)
            return toQuery[node];

        int mid = (nodeLeft + nodeRight)/2;
        int leftMin = query(toQuery,left,right,node*2,nodeLeft,mid);
        int rightMin = query(toQuery,left,right,node*2+1, mid+1, nodeRight);

        return min(leftMin,rightMin);
    }


    //interface
    int query(int left, int right){

        int min = query(rangeMin,left,right,1,0,n-1);
        return min;
    }
};


void traverse(int here, int d, vector<int>& trip){
    no2serial[here] = nextSerial;
    serial2no[nextSerial] = here;
    ++nextSerial;

    depth[here] = d;

    locInTrip[here] = trip.size();
    trip.push_back(no2serial[here]);

    for(int i =0; i<child[here].size(); ++i){
        traverse(child[here][i],d+1,trip);
        trip.push_back(no2serial[here]);
    }
}

RMQ* prepareRMQ(){
    nextSerial =0;
    vector<int> trip;
    traverse(0,0,trip);
    return new RMQ(trip);
}

int distance(RMQ* rmq, int u, int v){
    int lu = locInTrip[u], lv = locInTrip[v];
    if(lu > lv) swap(lu,lv);
    //공통 조상의 실제 노드 반환.
    int lca = serial2no[rmq->query(lu,lv)];

    return depth[u]+depth[v]-2*depth[lca];

}

int main() {

    int c;
    scanf("%d",&c);
//    cin >> c;
    while(c--){

        scanf("%d%d",&n,&q);
//        cin >> n >> q;
        for(int i =1; i< n; ++i){
            int parent;
            scanf("%d",&parent);
//            cin >> parent;
            child[parent].push_back(i);
        }

        RMQ* rmq = prepareRMQ();


        for(int i =0; i<q; ++i) {
            int a, b;
            scanf("%d%d",&a,&b);
//            cin >> a >> b;
            printf("%d\n",distance(rmq,a,b));
//            cout << distance(rmq,a,b) << endl;
        }


        //Initialization.
        for(int i =0; i<n; ++i)
            child[i].clear();
        memset(no2serial,0,sizeof(int)*n);
        memset(serial2no,0,sizeof(int)*n);
        memset(locInTrip,0,sizeof(int)*n);
        memset(depth,0,sizeof(int)*n);

    }


}
