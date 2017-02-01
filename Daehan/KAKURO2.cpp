#include<iostream>
#include<vector>

using namespace std;

// 카쿠로 판의 크기
int N; 

//힌트의 개수
int Q;


struct query {

	int visit, cnt, y, x, sum, d;

	//힌트 초기화
	query(int Y,int X,int D,int S): y(Y), x(X), sum(S), d(D), visit(0), cnt(0){}

	void push(int idx) {

		visit |= 1 << idx;
		cnt--;
		sum -= idx;

	}

	void pop(int idx) {

		visit ^= 1 << idx;
		cnt++;
		sum += idx;

	}

};

//입력되는 Q개의 힌트를 담을 벡터
vector<query> hint;

// hintIdx[y][x][d] : (y,x)에 해당되는 d 타입 힌트의 인덱스. hint에 저장되어 있다.
int hintIdx[21][21][2];

// 맵 저장할 배열
int map[21][21];
//빈칸 저장하는 벡터
vector<pair<int, int>> dot;

// 카쿠로 퍼즐이 만들어졌다면 true.
bool complete;

void solve(int pos) {

	if (complete) return;
	if (pos == dot.size()) { complete = true; return; }


	const int& y = dot[pos].first;
	const int& x = dot[pos].second;

	query& hintH = hint[hintIdx[y][x][1]];
	query& hintW = hint[hintIdx[y][x][0]];

	int visit = hintH.visit | hintW.visit;

	for (int i = 1; i <= 9 && hintH.sum >= i && hintW.sum >= i; ++i) {
		//만일 i가 visit에 없으면
		if ((visit & (1 << i)) == 0) {


			// 빈칸이 하나 남았을 때 처리하는 방법.
			if (hintH.cnt == 1 && hintH.sum != i)
				continue;
			if (hintW.cnt == 1 && hintW.sum != i)
				continue;

			// 재귀호출
			hintH.push(i);
			hintW.push(i);

			map[y][x] = i;

			solve(pos + 1);
			if (complete) return;

			hintH.pop(i);
			hintW.pop(i);


		}

	}

}

int main() {

	int T;
	cin >> T;

	while (T--) {
		hint.clear();
		dot.clear();
		complete = false;

		cin >> N;

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> map[i][j];
				if (map[i][j] == 1)
					dot.push_back(make_pair(i, j));
			}
		}

		cin >> Q;

		for (int i = 0; i < Q; ++i) {
			int y, x, d, s;
			cin >> y >> x >> d >> s;
			// map은 0,0 부터 시작했으므로 hint도 입력되는 값에서 각각 1씩 뺀다. 그 이유는 문제의 조건에 hint의 y,x좌표가 1이상이라고 명시되어 있기 때문.
			hint.push_back(query(y - 1, x - 1, d, s));

		}

		//hintIdx, cnt 채워넣기
		for (int i = 0; i < Q; ++i) {

			query& h = hint[i];
			int& y = h.y;
			int& x = h.x;
			int& d = h.d;

			//세로힌트인 경우
			if (d == 1) {
				for (int j = y + 1; map[j][x] == 1; ++j) {
					h.cnt++;
					hintIdx[j][x][1] = i;
				}
			}
			//가로힌트인 경우
			else {
				for (int j = x + 1; map[y][j] == 1; ++j) {
					h.cnt++;
					hintIdx[y][j][0] = i;
				}
			}

		}

		//맵을 그린다.
		solve(0);


		//맵을 출력한다.
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << map[i][j] << " ";
			}
			cout << "\n";
		}


	}
}