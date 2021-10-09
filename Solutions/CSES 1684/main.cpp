#include <bits/stdc++.h>

using namespace std;

int n, m;

vector<int> adj[200001], re_adj[200001];

void add_edge(int u, int v)
{
	adj[u].push_back(v);
	re_adj[v].push_back(u);
}

int r(int x)
{
	if (x <= m) return x + 100000;
	return x - 100000;
}

stack<int> S;

bool vis[200001];
void dfs1(int u)
{
	vis[u] = true;
	for (int v : adj[u])
		if (!vis[v])
			dfs1(v);
	S.push(u);
}

int c = 0;
int col[200001];
void dfs2(int u)
{
	vis[u] = true;
	col[u] = c;
	for (int v : re_adj[u])
		if (!vis[v])
			dfs2(v);
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		char c1, c2;
		int x1, x2;
		cin >> c1 >> x1 >> c2 >> x2;
		int u = ((c1 == '+') ? x1 : r(x1));
		int v = ((c2 == '+') ? x2 : r(x2));
		add_edge(r(u), v);
		add_edge(r(v), u);
	}
	for (int i = 1; i <= m; i++)
	{
		if (!vis[i]) dfs1(i);
		if (!vis[r(i)]) dfs1(r(i));
	}	
	memset(vis, false, sizeof vis);
	while(!S.empty())
	{
		int u = S.top();
		S.pop();
		if (!vis[u])
		{
			c++;
			dfs2(u);
		}	
	}
	for (int i = 1; i <= m; i++)
		if (col[i] == col[r(i)])
		{
			cout << "IMPOSSIBLE";
			return 0;
		}
	for (int i = 1; i <= m; i++)
		cout << ((col[i] < col[r(i)]) ? '-' : '+') << ' ';
}