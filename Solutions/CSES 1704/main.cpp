#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[100001];
vector<int> leaves;

void dfs(int u, int p)
{
	if (adj[u].size() == 1)
		leaves.push_back(u);
	for (int v : adj[u])
		if (v != p)
			dfs(v, u);
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
	for (int i = 1; i <= n; i++)
		if (adj[i].size() > 1)
		{
			dfs(i, -1);
			break;
		}	
	cout << ((int)leaves.size() + 1)/2 << '\n';
	for (int i = 0; i < ((int)leaves.size() + 1)/2; i++)
		cout << leaves[i] << ' ' << leaves[i + (int)leaves.size()/2] << '\n';
}