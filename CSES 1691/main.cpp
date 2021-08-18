#include <bits/stdc++.h>
 
using namespace std;
 
int n, m;
set<int> adj[100001];
 
bool vis[100001];
 
void dfs(int u)
{
	vis[u] = true;
	for (auto v : adj[u])
		if (!vis[v])
			dfs(v);
}
 
bool check() // Euler cycle and stuff
{
	for (int i = 1; i <= n; i++)
		if (adj[i].size() % 2)
			return false;
	dfs(1);
	for (int i = 1; i <= n; i++)
		if (!vis[i] && adj[i].size())
			return false;
	return true;
}
 
vector<int> ans;
 
void find_Cycle(int u)
{
	while(!adj[u].empty())
	{
		int v = (*adj[u].begin());
		adj[u].erase(adj[u].begin());
		adj[v].erase(u);
		find_Cycle(v);
	}		
	ans.push_back(u);
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
		adj[u].insert(v);
		adj[v].insert(u);
	}
	if (!check()) return cout << "IMPOSSIBLE", 0;
	find_Cycle(1);
	reverse(ans.begin(), ans.end());
	for (int v : ans)
		cout << v << ' ';
}