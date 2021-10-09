#include <bits/stdc++.h>

using namespace std;
const string filename = "test";

typedef pair<int, int> ii;

int n, m;        
vector<int> adj[501];

int c[1001][1001], f[1001][1001];

int ans;

int p[501];
bool aug_path()
{
	for (int i = 1; i <= n; i++)
		p[i] = -1;
	queue<int> q;
	q.push(1);
	p[1] = 0;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v : adj[u])
			if (p[v] == -1 && f[u][v] < c[u][v])
			{
				p[v] = u;
				q.push(v);
			}	
	}
	return (p[n] != -1);
}

void trace()
{
	int cur = n;
	while(cur != 1)
	{
		f[p[cur]][cur]++;
		f[cur][p[cur]]--;
		cur = p[cur];
	}
}

bool vis[1001];

void bfs()
{
	vector<ii> ans;
	queue<int> q;
	q.push(1);
	vis[1] = true;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v : adj[u])
			if (!vis[v] && f[u][v] < c[u][v])
			{
				vis[v] = true;
				q.push(v);				
			}
	}
	for (int u = 1; u <= n; u++)
		for (int v : adj[u])
			if (vis[u] && !vis[v])
				ans.push_back(ii(u, v));
	cout << ans.size() << '\n';
	for (ii p : ans)
		cout << p.first << ' ' << p.second << '\n';
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v;
		c[u][v] = c[v][u] = 1;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	while(aug_path())
		trace();
	bfs();
}