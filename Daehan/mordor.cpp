#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int MAX_INT = numeric_limits<int>::max();

struct RMDQ {
    int n;
    
    //최소 차이와 그 차이를 갖게 하는 min,max를 저장.
    vector<vector<int>> rangeMax;
    RMDQ(const vector<int>& array){
        n = array.size();
        rangeMax.resize(n*4);   
        for(int i =0; i<n*4; ++i){
            rangeMax[i].resize(3);
        }
        init(array,0,n-1,1);
    }
    
    vector<int> init(const vector<int>& array, int left, int right, int node){
        if(left == right) {
            rangeMax[node][0] = 0;
            rangeMax[node][1] = rangeMax[node][2] = array[left];
            return rangeMax[node];
        }
        
        int mid = (left+right)/2;
        vector<int> leftMax = init(array,left,mid,node*2);
        vector<int> rightMax = init(array,mid+1,right,node*2+1);
        
        int min_element = min(leftMax[1],rightMax[1]);
        int max_element = max(leftMax[2],rightMax[2]);
        int diff = max_element - min_element;
        
        rangeMax[node][0] = diff;
        rangeMax[node][1] = min_element;
        rangeMax[node][2] = max_element;
        
        return rangeMax[node];
    }

    void print(){
        for(int i=0; i<4*n; ++i){
            for(int j=0; j<3; ++j){
             cout << rangeMax[i][j] << ' ';
            }
            cout << endl;
        }
    }
    
    vector<int> query(int left, int right, int node, int nodeLeft, int nodeRight){
        if(left > nodeRight || right < nodeLeft){
            vector<int> ret = {-1,MAX_INT,-1};
            return ret;
        }
        
        if(left <= nodeLeft && nodeRight <= right)
            return rangeMax[node];

        int mid = (nodeLeft + nodeRight)/2;
        vector<int> leftMax = query(left,right,node*2,nodeLeft,mid);
        vector<int> rightMax = query(left,right,node*2+1, mid+1, nodeRight);

        int min_element = min(leftMax[1],rightMax[1]);
        int max_element = max(leftMax[2],rightMax[2]);
        int diff = max_element - min_element;

        vector<int> ret(3);
        ret[0] = diff;
        ret[1] = min_element;
        ret[2] = max_element;

        return ret;
    }
    
    //interface
    int query(int left, int right){
        return query(left, right, 1, 0, n-1)[0];
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
        RMDQ rmdq(array);
//        rmdq.print();
        while(q--){
            int a, b;
            scanf("%d%d",&a,&b);
//            cin >> a >> b;
            cout << rmdq.query(a, b) << endl;
        }
    }

}
