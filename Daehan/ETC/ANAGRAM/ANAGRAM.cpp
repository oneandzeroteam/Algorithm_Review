#include <iostream>
#include <string>
#include <vector>

using namespace std;

//string a와 b가 같은 문자들을 가지고 있는지 체크한다.
bool verify(const string& a, const string& b){
    if(a == b) return false;
    if(a.size() != b.size()) return false;

    int len = a.size();
    vector<int> a_char(150,0), b_char(150,0);
    for(int i =0; i<len; ++i){
        int ch1 =a[i] - '0';
        int ch2 =b[i] - '0';

        a_char[ch1]++;
        b_char[ch2]++;
    }

    if(a_char == b_char) return true;

    return false;
}

int main() {

    int T;
    cin >> T;
    while(T--){

        string st1, st2;
        cin >> st1 >> st2;

        if(verify(st1,st2))
            cout << "Yes" << endl;
        else
            cout << "No." << endl;
    }

}
