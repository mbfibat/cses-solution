#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll inf = 1000000000000000001;

int n, m, k;

ll f[100][100], g[100][100];

void mul(ll a[100][100], ll b[101][100])
{
	ll c[100][100];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			c[i][j] = inf;
			for (int k = 0; k < n; k++)
				if (a[i][k] != inf && b[k][j] != inf)
					c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
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

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			f[i][j] = inf;

	for (int i = 1; i <= m; i++)
	{
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--, v--;
		f[u][v] = min(f[u][v], w);
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (i == j) g[i][j] = 0;
			else g[i][j] = inf;
		}	
	while(k)
	{
		if (k & 1) mul(g, f);	
		mul(f, f);
		k /= 2;		
	}
	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cerr << g[i][j] << ' ';
		cerr << '\n';
	}
	*/	
	cout << ((g[0][n - 1] == inf) ? -1 : g[0][n - 1]);	
}