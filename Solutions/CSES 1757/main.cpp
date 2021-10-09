#include <bits/stdc++.h>

using namespace std;

int n, m;
int deg[100001];
vector<int> adj[100001], ans;

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
		adj[v].push_back(u);
		deg[u]++;
	}	

	priority_queue<int> pq;
	for (int i = 1; i <= n; i++)
		if (!deg[i])
			pq.push(i);
	while(!pq.empty())
	{
		int u = pq.top();
		pq.pop();
		ans.push_back(u);
		for (int v : adj[u])
		{
			deg[v]--;
			if (!deg[v])
				pq.push(v);
		}	
	}
	reverse(ans.begin(), ans.end());
	for (int u : ans)
		cout << u << ' ';
}