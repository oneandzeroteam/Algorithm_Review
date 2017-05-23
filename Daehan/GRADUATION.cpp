#include <iostream>
#include <algorithm>
#include <cstring>

#define MAXN 12
using namespace std;

const int INF =987654321;
int n, k, m, l;
int prerequisite[MAXN];

int classes[10];
int cache[10][1<<MAXN];

//이번 학기가 semester이고 지금까지 들은 과목의 집합이 taken일 때 k개 이상의 과목을 모두 들으려면 몇 학기나 더 있어야 하는가?
//불가능한 경우 inf를 반환한다.
int graduate(int semester, int taken) {
    // k개 이상의 과목을 이미 들은 경우.
    if(__popcntd(taken) >= k) return 0;
    //m 학기가 전부 지난 경우.
    if(semester == m) return INF;
    //메모이 제이션.
    int& ret = cache[semester][taken];
    if(ret!= -1) return ret;
    ret = INF;
    //이번 학기에 들을 수 있는 과목중 아직 듣지 않은 과목들을 찾는다.
    int canTake = (classes[semester] & ~ taken);
    //선수 과목을 다 듣지 않은 과목들을 걸러낸다.
    for(int i =0; i<n; ++i)
        if((canTake & (1 << i)) && (taken & prerequisite[i]) != prerequisite[i])
            canTake &= ~(1<<i);
    //이 부분이 완전 탐색.
    for(int take = canTake; take > 0; take = ((take-1) & canTake)){
        //한 학기에 l개의 과목만 들을 수 있다.
        if(__popcntd(take) > l) continue;
        ret = min(ret, graduate(semester+1, taken | take) + 1);

    }

    ret = min(ret, graduate(semester+1, taken));
    return ret;
}

int main() {

    int C;
    cin >> C;
    while(C--){
        //cache 초기화.
        memset(cache,-1,sizeof(cache));
        //classes와 prerequisite은 empty-set으로 초기화해야 한다. 즉, 0
        memset(classes,0,sizeof(classes));
        memset(prerequisite,0,sizeof(prerequisite));

        cin >> n >>k >> m >> l;
        for(int i=0; i<n; ++i){
            int numPre; cin >> numPre;
            while(numPre--){
                int j; cin >> j;
                //i번째 과목은 j번째 과목이 선수과목.
                prerequisite[i] |= (1u << j);
            }
        }

        for(int i =0; i<m; ++i){
            int numClass; cin >> numClass;
            while(numClass--){
                int j; cin >> j;
                //i번째 학기에는 j번째 과목이 개설됨.
                classes[i] |= (1u << j);
            }
        }
        int sol = graduate(0,0);
        if(sol < m)
            cout << sol << endl;
        else
            cout << "IMPOSSIBLE" << endl;

    }

}
