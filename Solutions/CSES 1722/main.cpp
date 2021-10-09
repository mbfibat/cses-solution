#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

int n = 2;

ll k;

ll f[2][2], g[2][2];

void mul(ll a[2][2], ll b[2][2])
{
	ll c[2][2];
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
	if (k == 0) return cout << 0, 0;
	else if (k == 1) return cout << 1, 0;
	k--;
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
	ll ans = g[0][0];
	cout << ans;
}