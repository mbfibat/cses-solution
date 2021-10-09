#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100001];
int in[100001], out[100001];
vector<int> ans;

int cnt = 0;

void find_Path(int u)
{
	while(!adj[u].empty())
	{
		int v = adj[u].back();
		adj[u].pop_back();
		find_Path(v);
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
		adj[u].push_back(v);
		out[u]++, in[v]++;	
	}
	bool ok = true;
	for (int i = 2; i <= n - 1; i++)
		if (in[i] != out[i])
			ok = false;
	if (out[1] != in[1] + 1 || in[n] != out[n] + 1)
		ok = false;
	find_Path(1);
	if (ans.size() != m + 1)
		ok = false;
	if (!ok)
		return cout << "IMPOSSIBLE", 0;
	reverse(ans.begin(), ans.end());
	for (int v : ans)
		cout << v << ' ';
}