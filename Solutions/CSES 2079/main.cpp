#include <bits/stdc++.h>

using namespace std;

int n;
int nChild[200001];
vector<int> adj[200001];

void dfs(int u, int p)
{
	nChild[u] = 1;
	for (int v : adj[u])
		if (v != p)
		{
			dfs(v, u);
			nChild[u] += nChild[v];
		}	
}

int find_c(int u, int p)
{
	for (int v : adj[u])
		if (v != p && nChild[v] > n/2)
			return find_c(v, u);
	return u;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(1, -1);
	cout << find_c(1, -1);
}