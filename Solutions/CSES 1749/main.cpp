#include <bits/stdc++.h>

using namespace std;

int n;
int a[200001], BIT[200001];

void upd(int x, int val) {
	for (; x <= n; x += x & (-x))
		BIT[x] += val;
}

int query(int x) {
	int ans = 0, pos = 0;
	for (int i = 20; i >= 0; i--) {
		if (pos + (1 << i) <= n && ans + BIT[pos + (1 << i)] < x) {
			ans += BIT[pos + (1 << i)];
			pos += (1 << i);
		}
	}	
	return pos + 1;	
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		upd(i, 1);
	}	
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		int p = query(x);
		cout << a[p] << ' ';
		upd(p, -1);
	}
}