#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <iomanip> 

using namespace std;
double bases[101][2];
int connect[101];
double solution = 0;
int num_case, num_base = 0;

/* value는 반올림하고자 하는 실수값 */
/* pos는 반올림하고자 하는 소수점 자리수 */
double round( double value, int pos )
{
      double temp;
      temp = value * pow( 10, pos );  // 원하는 소수점 자리수만큼 10의 누승을 함
      temp = floor( temp + 0.5 );          // 0.5를 더한후 버림하면 반올림이 됨
      temp *= pow( 10, -pos );           // 다시 원래 소수점 자리수로
      return temp;
} 

double distance(double x1, double y1, double x2, double y2) {
	return(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}

int solve(int base) {
	double minimum = 100;
	int minimum_index = -1;
	connect[base] = 1;
	for (int i = 0; i < num_base; i++) {
		if(connect[i] == 0) {
			double temp_distance = distance(bases[base][0],bases[base][1],bases[i][0],bases[i][1]);
			if(minimum > temp_distance) {
				minimum_index = i;
				minimum = temp_distance;
			}
		}
	}
	if(minimum_index != -1) {
		connect[minimum_index] = 1;
		if(solution < minimum)
			solution = minimum;
		solve(minimum_index);
	}
	else
		return 0;
}

int main() {
	
	cin >> num_case;
	for (int i = 0; i < num_case; i++) {
		memset(connect, 0, sizeof(int) * 101);	

		cin >> num_base;
		
		for(int j = 0; j < num_base; j++)
			cin >> bases[j][0] >> bases[j][1];

		solve(0);
		solution = round(solution,2);
		cout << fixed;
		cout.precision(2);
		cout << setiosflags(ios::showpoint) << solution; 
		//cout << solution << endl;

		return 0;
		

	}
}
