#include <bits/stdc++.h>

using namespace std;

int n, m;
int p[2501], d[2501];
vector<int> adj[2501];

int ans = 1e9;

void solve(int s)
{
	queue<int> q;
	q.push(s);
	for (int i = 1; i <= n; i++)
		d[i] = 1e9;
	d[s] = 0;	
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v : adj[u])
		{
			if (d[v] == 1e9)
			{
				d[v] = d[u] + 1;
				p[v] = u;
				q.push(v);
			}
			else if (p[v] != u && p[u] != v)
				ans = min(ans, d[u] + d[v] + 1);
		}
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
		solve(i);
	cout << ((ans == 1e9) ? -1 : ans);
}