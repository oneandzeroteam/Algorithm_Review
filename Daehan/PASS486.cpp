//timeover
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int minFactor[10000000];
const int N = 10000000;

void preprocess(){
    // 에라토스테네스의 체 생성
    minFactor[0] = minFactor[1] = -1;

    int sqrtn = int(sqrt(N));

    for(int i=2; i<N; ++i)
        minFactor[i] = i;

    for(int i=2; i<sqrtn; ++i){

        if(minFactor[i] == i)
            for(int j=i*i; j<N; j += i){
                if(minFactor[j] == j)
                    minFactor[j] = i;
            }

    }

}

int num_divisor(int n){
    //int의 약수의 개수 반환

    vector<int> factor;

    while(n > 1){
        factor.push_back(minFactor[n]);
        n /= minFactor[n];
    }

    factor.push_back(-1);
    int cnt=2;
    int ret =1;
    for(int i=0; i<factor.size()-1; ++i){

        if(factor[i] == factor[i+1]){

            ++cnt;
        }
        else{
            ret *= cnt;
            cnt =2;
        }

    }

    return ret;
}


int main(){

    preprocess();
    int C;
    cin >> C;

    while(C--){

        int n, lo, hi;
        cin >> n >> lo >> hi;

        int sol=0;
        for(int i = lo; i<= hi; ++i){
            if(num_divisor(i) == n)
                ++sol;
        }

        cout << sol << endl;

    }


}
