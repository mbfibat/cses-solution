#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> S;
bool vis[200001];
int nxt[200001];
vector<int> r_nxt[200001];

int c, top;
int id[200001], v[200001];
int n_nxt[200001];

void dfs1(int u)
{
	vis[u] = true;
	if (!vis[nxt[u]])
		dfs1(nxt[u]);
	S.push(u);
}

void dfs2(int u)
{
	c++;
	id[u] = top;
	vis[u] = true;
	for (int v : r_nxt[u])
		if (!vis[v])
			dfs2(v);
		else if (id[v] != top)
			n_nxt[id[v]] = top;
}

int f[200001], g[200001];

int cal(int u)
{
	if (!n_nxt[u] || n_nxt[u] == u)
		return v[u];
	if (g[u])
		return f[u];
	int ans = v[u] + cal(n_nxt[u]);
	g[u] = 1;
	return f[u] = ans;					
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		nxt[i] = x;
		r_nxt[x].push_back(i);
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
			c = 0;
			top++;
			dfs2(u);
			v[top] = c;
		}
	}
	for (int i = 1; i <= n; i++)
		cout << cal(id[i]) << ' ';
}