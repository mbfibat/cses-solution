#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
int n, m;

int f[1000][1 << 10][10];
bool g[1000][1 << 10][10];

int dp(int y, int mask, int x) {
	if (y >= m) return (mask == (1 << n) - 1);
	if (x >= n) return dp(y + 1, mask, 0);
	if (g[y][mask][x]) return f[y][mask][x];

	int cur = 0;
	if (!y || (mask >> x & 1))
		(cur += dp(y, mask & (~(1 << x)), x + 1)) %= mod;
	if (y && !(mask >> x & 1))
		(cur += dp(y, mask | (1 << x), x + 1)) %= mod;
	if (x != n - 1 && (!y || ((mask >> x & 1) && (mask >> (x + 1) & 1)))) 
		(cur += dp(y, mask | (1 << x) | (1 << (x + 1)), x + 2)) %= mod;

	g[y][mask][x] = true;
	return f[y][mask][x] = cur;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	cout << dp(0, 0, 0);
}