#include <bits/stdc++.h>

using namespace std;

const int N = 200001;

int n, q;
int a[N];

struct Node {
	int mx = -1;
	Node *l = nullptr, *r = nullptr;
	Node(){} 
};

Node *root = nullptr;

void build(Node *cur, int l, int r) {
	if (l == r) {
		cur -> mx = a[l];
		return;
	}
	cur -> l = new Node;
	cur -> r = new Node;
	int mi = (l + r)/2;
	build(cur -> l, l, mi);
	build(cur -> r, mi + 1, r);
	cur -> mx = max(cur -> l -> mx, cur -> r -> mx);
}

void query(Node *cur, int l, int r, int k) {
	if (k > cur -> mx) return void(cout << 0 << ' ');
	if (l == r) {
		cur -> mx -= k;
		return void(cout << l << ' ');
	}	
	int mi = (l + r) / 2;
	if (k <= cur -> l -> mx)
		query(cur -> l, l, mi, k);
	else
		query(cur -> r, mi + 1, r, k);
	cur -> mx = max(cur -> l -> mx, cur -> r -> mx);	
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	root = new Node();
	build(root, 1, n);

	while (q--) {
		int k; cin >> k;
		query(root, 1, n, k);
	}
}