#include<iostream>
#include<map>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

int C,N;

map<int, int> applicants;

int main() {

	scanf("%d", &C);

	for (int i = 0; i < C; ++i) {

		scanf("%d",&N);
		int sum = 0;

		for (int j = 0; j < N; ++j) {

			map<int, int>::iterator it_f, it_b;
			

			int p, q; scanf("%d%d", &p,&q);
			applicants[p] = q; //map 특성상 정렬 완료.
			it_f = it_b = applicants.find(p);

			while (it_b != applicants.begin()) {
				--it_b;
				if (it_b->second < q) {
					it_b = applicants.erase(it_b);
//					it_b = applicants.find(p);
				}

			}

			// index를 1씩 줄여가며 q가 작은 원소를 모두 지운다.

//index를 1씩 늘려가며 q가 큰 원소가 하나라도 있으면 지금 추가한 원소를 지운다.
			
			while (it_f != applicants.end() ) {
				if (it_f->second > q) {
					applicants.erase(p);
					break;
				}
				++it_f;
			}

			sum += applicants.size();
		
		}

		cout << sum << endl;
		applicants.clear();

	}
}