#include <bits/stdc++.h>

using namespace std;

int n, q;

char c[1001][1001];
int BIT[1001][1001];

void update(int x, int y, int val) {
	for (; x <= n; x += x & (-x)) {
		int yy = y;
		for (; yy <= n; yy += yy & (-yy))
			BIT[x][yy] += val;
	}
}

int query(int x, int y) {
	int ans = 0;
	for (; x > 0; x -= x & (-x)) {
		int yy = y;
		for (; yy > 0; yy -= yy & (-yy))
			ans += BIT[x][yy];
	}
	return ans;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
			if (c[i][j] == '*')
				update(i, j, 1);
		}

	while (q--) {
		int t; cin >> t;
		if (t == 1) {
			int x, y; cin >> x >> y;
			if (c[x][y] == '*') {
				update(x, y, -1);
				c[x][y] = '.';
			}
			else {
				update(x, y, 1);
				c[x][y] = '*';
			}	
		}
		else {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1) << '\n';
		}
	}
}