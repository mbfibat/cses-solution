#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, q;
int a[200001];
vector<int> adj[200001];

int top = 0;
int f[200001];
int st[200001], ed[200001];

void dfs(int u, int p, int cur)
{
	st[u] = ++top;
	f[u] = cur;
	for (int v : adj[u])
		if (v != p)
			dfs(v, u, cur + a[v]);
	ed[u] = top;
}

int bit[200001];

void upd(int x, int val)
{
	for (; x <= 200000; x += x & (-x))
		bit[x] += val;
}

int query(int x)
{
	int ans = 0;
	for (; x > 0; x -= x & (-x))
		ans += bit[x];
	return ans;	
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1, a[1]);
	while (q--)
	{
		int t; cin >> t;
		if (t == 1)
		{
			int u, val; cin >> u >> val;
			int diff = val - a[u];
			upd(st[u], diff);
			upd(ed[u] + 1, -diff);
			a[u] = val;
		}
		else
		{
			int u; cin >> u;
			cout << f[u] + query(st[u]) << '\n';
		}
	}
}