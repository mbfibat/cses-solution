#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, m;
int w[100001];
vector<int> adj[100001], r_adj[100001];

bool vis[100001];
stack<int> S;

void dfs1(int u)
{
	vis[u] = true;
	for (int v : adj[u])
		if (!vis[v])
			dfs1(v);
	S.push(u);
}

int top = 0, sum = 0;
int col[100001], val[100001];
vector<int> new_adj[100001];

void dfs2(int u)
{
	sum += w[u];
	col[u] = top;
	vis[u] = true;
	for (int v : r_adj[u])
	{
		if (!vis[v])
			dfs2(v);
		else if (col[v] != col[u])
			new_adj[col[v]].push_back(col[u]);
	}			
}

int f[100001], g[100001];

int dp(int u)
{
	if (g[u])
		return f[u];
	int cur = 0;
	for (int v : new_adj[u])
		cur = max(cur, dp(v));
	cur += val[u];
	g[u] = 1;
	return f[u] = cur;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		r_adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs1(i);
	memset(vis, false, sizeof vis);
	while(!S.empty())
	{
		int u = S.top();
		S.pop();
		if (!vis[u])
		{
			sum = 0;
			top++;
			dfs2(u);
			val[top] = sum;
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++)
		res = max(res, dp(col[i]));
	cout << res;		 
}