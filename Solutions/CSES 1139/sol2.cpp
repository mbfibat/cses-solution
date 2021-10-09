#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
int n;
int a[200001], h[200001], ans[200001], par[200001];

vector<int> adj[200001];
set<int> val[200001];

void dfs(int u, int p)
{
	for (int v : adj[u])
		if (v != p)
		{
			h[v] = h[u] + 1;
			dfs(v, u);
			par[v] = u;
		}	
}

vector<ii> ord;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 1; i++)	
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}	
	dfs(1, -1);
	for (int i = 1; i <= n; i++)
		ord.push_back(ii(h[i], i));
	sort(ord.begin(), ord.end(), greater<ii>());
	for (int i = 0; i < ord.size(); i++)
	{
		int u = ord[i].second, p = par[u];
		val[u].insert(a[u]);
		ans[u] = val[u].size();
		if (val[u].size() > val[p].size())
			val[u].swap(val[p]);
		while(!val[u].empty())
		{
			val[p].insert(*val[u].begin());
			val[u].erase(val[u].begin());
		}
	}
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}