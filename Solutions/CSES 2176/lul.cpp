#include <bits/stdc++.h>
 
using namespace std;
 
const int mod = 1e9 + 7;
 
int n, k;
int f[511][511][511];
bool g[501][501][501];
 
int dp(int pos, int col, int rem) {
	if (!rem) return f[pos][col][rem] = 1;
	if (pos > n) return f[pos][col][rem] = 0;
	if (n - pos + 1 < rem) return f[pos][col][rem] = 0;
	if (g[pos][col][rem])
		return f[pos][col][rem];
	// Put 0
	int cur = dp(pos + 2, col + 2, rem);
	// Put 1
	if (pos == n)
		(cur += 1LL * dp(pos + 2, col + 1, rem - 1) * col % mod) %= mod;
	else
		(cur += 1LL * dp(pos + 2, col + 1, rem - 1) * col % mod * 2 % mod) %= mod;
	// Put 2
	if (pos != n && col >= 2 && rem >= 2)
		(cur += 1LL * dp(pos + 2, col, rem - 2) * col % mod * (col - 1) % mod) %= mod;
	g[pos][col][rem] = true;
	return f[pos][col][rem] = cur;
}
 
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cin >> n >> k;
	/*
	for (int pos = 1; pos <= n; pos++)
		for (int col = n; col >= 0; col--)
			for (int rem = n; rem >= 0; rem--) {
				int &cur = f[pos][col][rem];
				if (!rem) cur = 1;
				else if ((n - pos + 1 < rem)) cur = 0;
				else {
					cur = f[pos + 2][col][rem]; // Put 0
					if (col >= 1 && rem >= 1) { // Put 1
						if (pos == n) 
							(cur += 1LL * f[pos + 2][col - 1][rem - 1] * col % mod) %= mod;
						else
							(cur += 1LL * f[pos + 2][col - 1][rem - 1] * col % mod * 2 % mod) %= mod;	
					}
					if (pos != n && col >= 2 && rem >= 2)
						(cur += 1LL * f[pos + 2][col - 2][rem - 2] * col % mod * (col - 1) % mod) %= mod;
				}
			}
	*/
 
	int ans = 0;
	for (int s1 = 0; s1 <= k; s1++) {
		int s2 = k - s1;
		if (s1 <= n && s2 <= n)
			(ans += 1LL * dp(1, 1, s1) * dp(2, 2, s2) % mod) %= mod;
	}
	cout << ans;
}