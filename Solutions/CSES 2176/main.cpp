#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n, k;
int f[1001][501];
bool g[1001][501];

int dp(int pos, int p) {
	if (p == 0) return 1;
	if (pos <= 0) return 0;
	int col = -(p - 1);
	if (pos % 2) col += (pos - 1) / 4 * 2 + 1;
	else col += (pos - 1) / 4 * 2 + 2;
	if (col < 0) return 0;	   

	if (g[pos][p]) return f[pos][p];
	int cur = dp(pos - 2, p);
	(cur += 1LL * dp(pos - 2, p - 1) * col % mod) %= mod;
	g[pos][p] = 1;
	return f[pos][p] = cur;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	int ans = 0;
	for (int s1 = 0; s1 <= k; s1++) {
		int s2 = k - s1;
		if (s1 <= n && s2 <= n)
			(ans += 1LL * dp(2 * n - 1, s1) * dp(2 * n - 2, s2) % mod) %= mod;
	}
	cout << ans;
}