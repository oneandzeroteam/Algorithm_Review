#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> slice(const vector<int>& v, int a, int b) {

	return vector<int>(v.begin() + a, v.begin() + b);

}

void printPostOrder(const vector<int>& preorder, const vector<int>& inorder) {

	const int N = preorder.size();

	if (preorder.empty()) return;

	const int root = preorder[0];

	const int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();

	printPostOrder(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	printPostOrder(slice(preorder, L+1, N), slice(inorder, L+1, N));

	cout << root << ' ';
}

int main() {

	int numCase;
	cin >> numCase;

	for (int i = 0; i < numCase; ++i) {
		int numNode;
		cin >> numNode;

		vector<int> preorder, inorder;


		for (int j = 0; j < numNode; ++j) {
			int k; cin >> k;
			preorder.push_back(k);
		}
		for (int j = 0; j < numNode; ++j) {
			int k; cin >> k;
			inorder.push_back(k);
		}
		

		printPostOrder(preorder, inorder);
		cout << endl;

	}


}

