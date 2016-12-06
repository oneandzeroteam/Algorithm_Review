#include<iostream> // ´ä ¾È³ª¿È
#define MOD 20090711
using namespace std;

typedef int KeyType;
long long cache[200000];

struct Node {

	KeyType key;

	int priority;
	long long size;

	Node *left, *right;

	Node() : key(NULL), priority(rand()), size(1), left(NULL), right(NULL) {}
	Node(const KeyType& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}

	void setLeft(Node* newLeft) { left = newLeft; calcSize(); }
	void setRight(Node* newRight) { right = newRight; calcSize(); }
	Node* getLeft() { return left; }
	Node* getRight() { return right; }
	KeyType getKey() { return key; }
	void setKey(int _key) { key = _key; }
	void calcSize() {
		size = 1;
		if (left) size += left->size;
		if (right) size += right->size;
	}
	long long getSize() { return size; }

};

typedef pair<Node*, Node*> NodePair;

NodePair split(Node* root, KeyType key) {
	if (root == NULL) return NodePair(NULL, NULL);
	if (root->key < key) {
		NodePair rs = split(root->right, key);
		root->setRight(rs.first);
		return NodePair(root, rs.second);
	}

	NodePair ls = split(root->left, key);
	root->setLeft(ls.second);
	return NodePair(ls.first, root);
}

Node* insert(Node* root, Node* node) {
	if (root == NULL) return node;
	if (root->priority < node->priority) {
		NodePair splitted = split(root, node->key);
		node->setLeft(splitted.first);
		node->setRight(splitted.second);
		return node;
	}
	else if (node->key < root->key)
		root->setLeft(insert(root->left, node));
	else
		root->setRight(insert(root->right, node));
	return root;
}



Node* kth(Node* root, int k) {
	int leftSize = 0;
	if (root->left != NULL) leftSize = root->left->size;
	if (k <= leftSize) return kth(root->left, k);
	if (k == leftSize + 1) return root;
	return kth(root->right, k - leftSize - 1);
}


struct RNG {
	long long val;
	int a, b;
	RNG(int _a,int _b):a(_a),b(_b),val(1983){}

	long long next() {
		return val=(val*(long long)a + b) % MOD;
	}

};

long long A(long long n,int a, int b) {
	

	if (n == 0) return 1983;
	if (cache[n] != -1) return cache[n];
	else
		return cache[n] = (A(n - 1,a,b)*a + b)%MOD;
}

int main() {
	memset(cache, -1, 200000);
	
	int c;
	cin >> c;

	for (int i = 0; i < c; ++i) {
		int a, b;
		long long N;

		cin >> N >> a >> b;
		
		RNG rng(a,b);
		Node root(1983);

		Node* values = new Node[N-1];
		Node* newroot;
		long long sum = 1983;
		for (long long j = 0; j < N-1; ++j) {
			values[j].setKey(A(j+1,a,b));
			newroot=insert(&root, values + j);
			Node* temp = kth(newroot, ceil(newroot->getSize() / 2.0));
			sum += temp->getKey();
			if (sum >= MOD) sum %= MOD;
		}
		cout << sum << endl;


		delete[] values;

	}

}