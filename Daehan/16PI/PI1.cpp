// NOT WORKING

#include<iostream>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;

string S; 
int cache[10000];
int INF = numeric_limits<int>::max();

/*
int pi(int position) {
	size_t strLen = S.size();
	int& ret = cache[position];

	if (ret != -1) return ret;
	if (strLen - position - 1 < 3)
		return INF;
	int nextLen = 1;
	
	while (nextLen++ < 4)
		return cache[position + nextLen] = min(cache[position + nextLen], pi(position + nextLen));
	

}
*/

int hardness(string S) {
	
	size_t len = S.size();
	int nums[5];
	
	for (size_t i = 0; i < len; ++i) {
		char ch = S[i];
		nums[i] = atoi(&ch);
	}

	bool p1=true, p2=true, p3=true, p4=true; // 1. 숫자 같음, 2. 1씩 증가나 감소, 3. 번갈아가며, 4. 등차수열

	//p1
	for (size_t i = 0; i < len - 1; ++i)
		if (S[i] != S[i + 1]) {
			p1 = false;
			break; 
		}
	if (p1) return 1;


	//p2
	int diff = 1;
	for (size_t i = 1; i < len - 1; ++i)
		if (nums[i+1] - nums[i] != diff) {
			p2 = false;
			break;
		}
	if (p2) return 2;
	

	//p3
	for (size_t i = 0; i < len - 2; ++i)
		if (S[i] != S[i + 2]) {
			p3 = false;
			break;
		}
	if (p3) return 4;


	//p4
	diff = nums[1] - nums[0];
	for (size_t i = 1; i < len - 1; ++i)
		if (nums[i + 1] - nums[i] != diff) {
			p4 = false;
			break;
		}
	if (p4) return 5;
	
	return 10;
}

int main() {
	/*
	char a = '3';

	string b = "1234";

	char ch = b[2];
	cout << atoi(&ch)*2 << endl;
	*/
	cout << hardness("13131") << endl;

}