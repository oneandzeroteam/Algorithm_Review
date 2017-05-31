#include <iostream>
#include <algorithm>

using namespace std;


int maxDist(const vector<int>& array,int from, int to){
    auto idx = minmax_element(array.begin()+from, array.begin()+to+1);
    int ret = *(idx.second)-*(idx.first);
    return ret;

}

int main() {

    int c;
    cin >> c;
    while(c--){
        int n,q;
        scanf("%d%d",&n,&q);
        vector<int> array(n);
        for(int i =0; i<n; ++i) {
            scanf("%d",&array[i]);
        }
        while(q--){
            int a, b;
            scanf("%d%d",&a,&b);

            cout << maxDist(array,a,b)<<endl;

        }
    }

}
