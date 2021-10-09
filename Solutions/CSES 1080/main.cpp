#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

string s;

int comb[501][501];
int f[501][501], g[501][501];

int dp(int l, int r)
{
	if (l > r)
		return 1;
	if (r - l == 1)
		return s[l] == s[r];
	if (g[l][r])
		return f[l][r];
	int cur = 0;	
	for (int i = l + 1; i <= r; i++)
		if (s[l] == s[i] && ((i - l) % 2))
		{
			int cnt_l = (i - l - 1)/2;
			int cnt_r = (r - i)/2;
			(cur += dp(l + 1, i - 1) * dp(i + 1, r) % mod * comb[cnt_l + cnt_r + 1][cnt_r] % mod) %= mod;
		}
	g[l][r] = 1;
	return f[l][r] = cur;		
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i <= 500; i++)
		comb[i][0] = 1;
	for (int i = 1; i <= 500; i++)	
		for (int j = 1; j <= i; j++)
			comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j])%mod;

	cin >> s;
	cout << dp(0, s.size() - 1);
}