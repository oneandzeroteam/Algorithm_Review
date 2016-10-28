#include<iostream>

using namespace std;

int main(){

	int num_testcase;
	cin >> num_testcase;
	for (int i = 0; i < num_testcase; i++) {
		//testcase 개수만큼 시행을 반복한다.
		int num_fence;
		cin >> num_fence;
		int* fence_height; 
		fence_height = new  int[num_fence];

		for (int i = 0; i < num_fence; i++)
			cin >> fence_height[i];

		int max_area=0;
		for (int i = 0; i < num_fence; ++i) {
			int max_width=1;
			int max_area_temp;
			for (int j = 1; j < num_fence - i; ++j)
				if (fence_height[i] <= fence_height[i + j])
					++max_width;
				else
					break;
			for (int j = 1; i - j >= 0; ++j)
				if (fence_height[i] <= fence_height[i - j])
					++max_width;
				else
					break;
			max_area_temp = max_width * fence_height[i];
			//cout << max_area_temp << " "; 디버깅용
			if (max_area_temp > max_area)
					max_area = max_area_temp;
		}

		cout << max_area << endl;


		delete[] fence_height;


	}

}


