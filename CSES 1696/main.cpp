#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int m, n, k;

int S, T;
vector<int> adj[2001];
int c[2001][2001], f[2001][2001];

int p[2001];
bool aug_path()
{
	for (int i = S; i <= T; i++)
		p[i] = -1;
	queue<int> q;
	q.push(S);
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
	return (p[T] != -1);
}

void trace()
{
	int cur = T;
	while(cur != S)
	{
		f[p[cur]][cur]++;
		f[cur][p[cur]]--;
		cur = p[cur];
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> m >> n >> k;
	S = 0, T = m + n + 1;
	for (int i = 1; i <= k; i++)
	{
		int u, v;
		cin >> u >> v;

		adj[S].push_back(u);
		c[S][u] = 1;

		adj[u].push_back(m + v);
		c[u][m + v] = 1;

		adj[m + v].push_back(u);

		adj[m + v].push_back(T);
		c[m + v][T] = 1;
	}
	while(aug_path())
		trace();

	vector<ii> ans;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (f[i][m + j])
				ans.push_back(ii(i, j));
	cout << ans.size() << '\n';
	for (ii p : ans)
		cout << p.first << ' ' << p.second << '\n';				 
}