#include <iostream>
#include<vector>
#include <cmath>
#include<algorithm>

using namespace std;

int gcd(int a, int b){
    if(b < a)
        return gcd(b,a);


    if(b%a == 0)
        return a;
    while(b % a != 0) {
        int r = b % a;
        b=a;
        a=r;
    }

    return a;

}

void solve(const vector<int>& recipe, const vector<int>& put,const int& n){
    int gcd_num=1000;
    for(int i=0; i<n-1; ++i){
        gcd_num = min(gcd_num, gcd(recipe[i],recipe[i+1])) ;
    }

    vector<int> target = vector<int>(recipe.begin(),recipe.end());
    for(int i=0; i<n; ++i)
        target[i] /= gcd_num;

    float maxRatio=0.0;

    for(int i=0; i<n; ++i)
        maxRatio = max(maxRatio, put[i]/(float)target[i]);

    int ratio = max(gcd_num,(int)ceil(maxRatio));

    for(int i=0; i<n; ++i){
        target[i] *= ratio;
        cout << target[i] - put[i] << " ";
    }
    cout << endl;

}

int main() {

    int C;
    cin >> C;

    while(C--){

        int n;
        cin >> n;

        vector<int> recipe(n), put(n);

        for(int i=0; i<n; ++i) cin >> recipe[i];
        for(int i=0; i<n; ++i) cin >> put[i];


        solve(recipe,put,n);

    }

}
