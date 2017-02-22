#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int minFactor[10000000];
int factorPower[10000000];
const int N = 10000000;

void preprocess(){
    // 에라토스테네스의 체 생성
    minFactor[0] = minFactor[1] = -1;

    int sqrtn = int(sqrt(N));

    for(int i=2; i<N; ++i) {
        minFactor[i] = i;
        factorPower[i]=1;
    }
    for(int i=2; i<sqrtn; ++i){

        if(minFactor[i] == i)
            for(int j=i*i; j<N; j += i){
                if(minFactor[j] == j) {
                    minFactor[j] = i;
                    int num_i =0;
                    int temp_j =j;
                    while(temp_j % i == 0) {
                        ++num_i;
                        temp_j /= i;
                    }
                    factorPower[j] = num_i;
                }

            }

    }

}

int num_divisor(int n){
    //int의 약수의 개수 반환

    if(n == 1) return 1;

    return num_divisor(n/minFactor[n])/factorPower[n]*(factorPower[n]+1);
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
