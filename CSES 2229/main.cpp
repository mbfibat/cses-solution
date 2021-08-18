#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n, k;

int f[2][125001], psum[125001];

// f[pos][rem] += f[pos + 1][rem - i] (i = 0 -> min(n - pos, rem));

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	f[(n + 1) & 1][0] = 1;
	for (int i = 0; i <= k; i++)
		psum[i] = 1;

	for (int i = n; i >= 1; i--) {
		for (int j = 0; j <= k; j++)
			f[i & 1][j] = 0;
		for (int j = 0; j <= k; j++) {
			int tmp = j - min(n - i, j);
			if (!tmp) f[i & 1][j] = psum[j];
			else f[i & 1][j] = ((psum[j] - psum[tmp - 1]) % mod + mod) % mod;
		}
		psum[0] = f[i & 1][0];
		for (int j = 1; j <= k; j++)
			psum[j] = (psum[j - 1] + f[i & 1][j]) % mod;
	}

	cout << f[1][k];
}