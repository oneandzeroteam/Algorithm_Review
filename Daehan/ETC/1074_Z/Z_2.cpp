#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> quarter_point_is_in;

void make_stack(size_t y, size_t x, int N) {

	if (N < 1)
		return;

//	cout << "y,x = " << y << "," << x << endl;
	size_t length = pow(2, N - 1);
//	cout << "length =" << length << endl;
	
	if (y >= length && x >= length) {
//		cout << "q4" << endl;
		quarter_point_is_in.push_back(3);
		make_stack(y - length, x - length, N - 1);

	}
	if (y >= length && x < length) {
//		cout << "q3" << endl;
		quarter_point_is_in.push_back(2);
		make_stack(y - length, x, N - 1);
	}
	if (y < length && x < length) {
//		cout << "q1" << endl;
		quarter_point_is_in.push_back(0);
		make_stack(y, x, N - 1);
	}
	if (y < length && x >= length) {
//		cout << "q2" << endl;
		quarter_point_is_in.push_back(1);
		make_stack(y, x - length, N - 1);
	}

	



}

int main() {

	size_t r, c;
	int N;

	while (scanf("%d %d %d",&N,&r,&c) != EOF) {
//		cin >> N >> r >> c;


		make_stack(r, c, N);

		/*
			for (size_t i = 0; i < quarter_point_is_in.size(); ++i) {
				cout << quarter_point_is_in[i] << " ";
			}
			cout << endl;
			*/

		size_t sol = 0;
		int cnt = 1;
		while (N--) {
			sol += quarter_point_is_in[N] * cnt;
			cnt *= 4;
		}

		cout << sol << endl;
		quarter_point_is_in.clear();
	}

}