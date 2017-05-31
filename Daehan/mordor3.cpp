#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int MAX_INT = numeric_limits<int>::max();

struct RMQ {
    int n;
    
    //최소 차이와 그 차이를 갖게 하는 min,max를 저장.
    vector<int> rangeMin;
    vector<int> rangeMax;
    
    RMQ(const vector<int>& array){
        n = array.size();
        vector<int> i_array(n);
        for(int i=0; i<n; ++i)
            i_array[i] = -array[i];
        rangeMin.resize(n*4);
        rangeMax.resize(n*4);
        init(rangeMin,array,0,n-1,1);
        init(rangeMax,i_array,0,n-1,1);
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
        int max = -query(rangeMax,left,right,1,0,n-1);

        return max-min;
    }
};

int main() {
    
    int c;
    cin >> c;
    while(c--){
        int n,q;
        scanf("%d%d",&n,&q);
//        cin >> n >> q;
        vector<int> array(n);
        for(int i =0; i<n; ++i) {
            scanf("%d",&array[i]);
//            cin >> array[i];
        }
        RMQ rmdq(array);
//        rmdq.print();
        while(q--){
            int a, b;
            scanf("%d%d",&a,&b);
//            cin >> a >> b;
            cout << rmdq.query(a, b) << endl;
        }
    }

}
