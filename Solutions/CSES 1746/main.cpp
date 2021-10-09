#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n, m;
int a[100001];

int f[2][101];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];

	if (a[1]) f[1][a[1]] = 1;
	else for (int j = 1; j <= m; j++) f[1][j] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= m; j++) f[i & 1][j] = 0;
		for (int j = 1; j <= m; j++) {
			if (!a[i])
				for (int k = max(1, j - 1); k <= min(m, j + 1); k++)
					(f[i & 1][k] += f[(i - 1) & 1][j]) %= mod;
			else if (abs(a[i] - j) <= 1) 
				(f[i & 1][a[i]] += f[(i - 1) & 1][j]) %= mod;
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= m; i++) (ans += f[n & 1][i]) %= mod;
	cout << ans;
}