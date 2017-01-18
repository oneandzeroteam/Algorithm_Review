#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm> //max
#include <vector>
#include <string>  

using namespace std;

int c, n, capacity; //테스트케이스, 물건갯수, 용량 입력받기
string name[100]; int volume[100], need[100]; //물건 정보
int cache[1001][100];

int pack(int capacity, int item) { //최대가중치를 구하기 pack(capacity, 0) 
	if (item == n) return 0;
	int& ret = cache[capacity][item];
	if (ret != -1) return ret;
	ret = pack(capacity, item + 1);// 물건을 담지 않을 경우 
	if (capacity >= volume[item]) 	// 물건을 담는 경우 
		ret = max(ret, pack(capacity - volume[item], item + 1) + need[item]);
	return ret;
}

void reconstruct(int capacity, int item, vector<string>& picked) { //선택된 아이템구하기 reconstruct(capacity, 0, picked); 
	if (item == n) return;
	if (pack(capacity, item) == pack(capacity, item + 1))
		reconstruct(capacity, item + 1, picked);
	else { //아이템이 선택되었을 때. 
		picked.push_back(name[item]);
		reconstruct(capacity - volume[item], item + 1, picked);
	}
}

int main() {
	scanf("%d", &c);
	while (c--) {
		scanf(" %d %d", &n, &capacity);
		for (int j = 0; j < n; ++j)
			cin >> name[j] >> volume[j] >> need[j];
		memset(cache, -1, sizeof(cache)); //cache배열 초기화
		vector<string> picked;
		reconstruct(capacity, 0, picked); //선택된 아이템 picked vector에 담기
		cout << pack(capacity, 0) <<" "<< picked.size() << endl; // maxCapacity와 maxItemNum갯수 출력
		for (int j = 0; j < picked.size(); ++j)
			cout << picked[j] << endl; // 선택된 아이템들 이름 출력
	}
	return 0;
}


