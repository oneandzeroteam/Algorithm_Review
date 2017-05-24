#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
vector<int> d;

vector<int> partialSum(const vector<int>& a){
    vector<int> ret(a.size()+1);
    ret[0] = 0;
    for(int i =0; i<=a.size(); ++i){
        ret[i+1] = ret[i] +a[i];
        ret[i+1] %= k;
    }
    return ret;
}

int rangeSum(const vector<int>& psum, int a, int b){
    if(a==0) return psum[b];
    return psum[b]-psum[a-1];
}


int waysToBuy(const vector<int>& psum, int k){
    const int MOD = 20091101;
    int ret =0;

    vector<long long> count(k,0);
    for(int i =0; i<psum.size(); ++i)
        count[psum[i]]++;

    for(int i =0; i<k; ++i)
        if(count[i] >=2)
            ret = (ret + count[i] * (count[i] - 1) / 2) % MOD;

    return ret;
}

int maxBuys(const vector<int>& psum, int k){

    vector<int> ret(psum.size());
    //psum이 s였던 마지막 위치 prev[s]
    vector<int> prev(k,-1);

    ret[0] = 0;
    for(int i =0 ; i<psum.size(); ++i){
        if(i>0)
            ret[i] = ret[i-1];

        //나머지가 psum[i]인 마지막 위치 = loc
        int loc = prev[psum[i]];
        //loc가 한번 이상 바뀌었다면 그 위치에서 최대 구간 개수 + 1과
        // 직전까지의 최대 구간 개수를 비교해서 큰 것을 집어넣는다.
        if(loc != -1)
            ret[i] = max(ret[i], ret[loc] + 1);

        //나머지가 psum[i]인 마지막 위치를 갱신한다.
        prev[psum[i]] = i;
    }
    //맨 마지막 원소를 리턴한다.
    return ret.back();
}

int main() {

    int c;
    cin >> c;
    while(c--){

        cin >> n >> k;
        d = vector<int>(n);

        //인형의 개수 d_i를 받는다.
        for(int i =0; i<n; ++i)
            cin >> d[i];

        vector<int> sum(n+1);
        sum[0] = 0;
        for(int i=0; i < n; i++)
            sum[i+1] = (d[i] + sum[i]) % k;

        cout << waysToBuy(sum,k) << " ";
        cout << maxBuys(sum,k) << endl;

    }

}
