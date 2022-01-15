#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, q;
int a[200001];

ll psum[31][200001];
int rmq[31][21][200001]; // rmq for value [2^k, 2^(k + 1)];

bool in_range(int x, int k) {
	return (1 << k) <= x && x < (1 << (k + 1));
}

int cal_min(int k, int l, int r) {
	int d = (r - l + 1);
	int j = log2(d);
	return min(rmq[k][j][l], rmq[k][j][r - (1 << j) + 1]);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	for (int k = 0; k <= 30; k++)
		for (int i = 1; i <= n; i++) {
			psum[k][i] = psum[k][i - 1];
			if (in_range(a[i], k)) psum[k][i] += a[i];
		}

	for (int k = 0; k <= 30; k++) {
		for (int i = 1; i <= n; i++) {
			if (in_range(a[i], k)) rmq[k][0][i] = a[i];
			else rmq[k][0][i] = 2e9;
		}				

		for (int j = 1; j <= 20; j++)
			for (int i = 1; i + (1 << j) - 1 <= n; i++)
				rmq[k][j][i] = min(rmq[k][j - 1][i], rmq[k][j - 1][i + (1 << (j - 1))]);				
	}

	for (int i = 1; i <= q; i++) {
		int l, r; cin >> l >> r;

		ll ans = 0;
		for (int k = 0; k <= 30; k++) {
			int val = cal_min(k, l, r);
			if (val == 2e9) continue;
			if (val > ans + 1) break;
			ans += (psum[k][r] - psum[k][l - 1]);
		}
		cout << ans + 1 << '\n';
	}
}