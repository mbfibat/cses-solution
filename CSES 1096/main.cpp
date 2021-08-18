#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int n = 6;

ll k;

ll z[6];
ll f[6][6], g[6][6];

void mul(ll a[6][6], ll b[6][6])
{
	ll c[6][6];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			c[i][j] = 0;
			for (int k = 0; k < n; k++)
				(c[i][j] += (a[i][k] * b[k][j])%mod) %= mod;
		}	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = c[i][j];
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> k;
	z[0] = 1;
	for (int i = 1; i < n; i++)
	{
		z[i] = 1;
		for (int j = 1; j <= 6; j++)
			if (i - j >= 0)
				z[i] += z[i - j];
	}
	if (k <= 6)
		return cout << z[k - 1], 0;
	k -= 6;
	for (int j = 0; j < n; j++)
		f[0][j] = 1;
	for (int i = 1; i < n; i++)
		f[i][i - 1] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j) g[i][j] = 1;
			else g[i][j] = 0;
		}	
	while(k)
	{
		if (k & 1) mul(g, f);	
		mul(f, f);
		k /= 2;		
	}
	ll ans = 0;
	for (int i = 0; i < n; i++)
		(ans += g[0][i] * z[n - 1 - i]) %= mod;
	cout << ans;
}