#include <bits/stdc++.h>

using namespace std;

int n, x;
int h[101], s[101], k[101];

int f[101][100001], g[101][100001];

int dp(int pos, int rem)
{
	if (pos > n)
		return 0;
	if (g[pos][rem])
		return f[pos][rem];
	int cur = dp(pos + 1, rem);
	int amount = min(rem / h[i], k[i]);
	cur = max(cur, dp(pos + 1, rem - min(rem / h[i])));
	g[pos][rem] = 1;
	return f[pos][rem] = cur;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> h[i];
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	for (int i = 1; i <= n; i++)
		cin >> k[i];
	cout << dp(1, x);
}

3 4
2 3