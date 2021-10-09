#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
int a[5001];

int f[5001][5001][3];
bool g[5001][5001][3];

int dp(int l, int r, int t) {
	if (l > r) return 0;
	if (g[l][r][t]) return f[l][r][t];

	int cur = -1e18;
	if (t == 1) {
		cur = max(cur, dp(l + 1, r, 3 - t) + a[l]);
		cur = max(cur, dp(l, r - 1, 3 - t) + a[r]);
	}
	else if (t == 2) {
		cur = dp(l + 1, r, 3 - t);
		cur = min(cur, dp(l, r - 1, 3 - t));
	}

	g[l][r][t] = true;
	return f[l][r][t] = cur;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	cout << dp(1, n, 1);
}