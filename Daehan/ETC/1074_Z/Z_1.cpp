#include<iostream>
#include<cmath>
using namespace std;

size_t counter = 0;

void fill_array(unsigned** arr, size_t start_y, size_t start_x, size_t length) {
	if (length == 2) {
		arr[start_y][start_x] = counter;
		++counter;
		arr[start_y][start_x+1] = counter;
		++counter;
		arr[start_y+1][start_x] = counter;
		++counter;
		arr[start_y+1][start_x+1] = counter;
		++counter;
		return;
	}


	fill_array(arr, start_y, start_x, length / 2);
	fill_array(arr, start_y, start_x + length / 2, length / 2);
	fill_array(arr, start_y + length / 2, start_x, length / 2);
	fill_array(arr, start_y + length / 2, start_x + length / 2, length / 2);

}

int main() {

	size_t N, r, c;
	cin >> N >> r >> c;

	size_t length = pow(2, N);
	unsigned **arr = new unsigned*[length];
	for (size_t i = 0; i < length; ++i) {
		arr[i] = new unsigned[length];
	}

	fill_array(arr, 0, 0, length);
	cout << arr[r][c] << endl;

	for (size_t i = 0; i < length; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
}