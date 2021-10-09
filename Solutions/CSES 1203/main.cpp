#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> ii;

int n, m;
int d1[100001], dn[100001];
vector<ii> adj[100001], r_adj[100001];

void dijkstra()
{
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	for (int i = 1; i <= n; i++)
		d1[i] = 1e18;
	d1[1] = 0;
	pq.push(ii(0, 1));
	while(!pq.empty())
	{
		int du = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (du != d1[u])
			continue;
		for (int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].first, w = adj[u][i].second;
			if (du + w < d1[v])
			{
				d1[v] = du + w;
				pq.push(ii(d1[v], v));
			}
		}
	}
	for (int i = 1; i <= n; i++)
		dn[i] = 1e18;
	dn[n] = 0;
	pq.push(ii(0, n));
	while(!pq.empty())
	{
		int du = pq.top().first;
		int u = pq.top().second;
		pq.pop();
		if (du != dn[u])
			continue;
		for (int i = 0; i < r_adj[u].size(); i++)
		{
			int v = r_adj[u][i].first, w = r_adj[u][i].second;
			if (du + w < dn[v])
			{
				dn[v] = du + w;
				pq.push(ii(dn[v], v));
			}
		}
	}	 
}

bool cmp(const int &a, const int &b)
{
	return d1[a] < d1[b];
}

int pos[100001];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back(ii(v, w));
		r_adj[v].push_back(ii(u, w));
	}
	dijkstra();
	vector<int> gud;
	for (int i = 1; i <= n; i++)
		if (d1[i] + dn[i] == d1[n])
			gud.push_back(i);
	sort(gud.begin(), gud.end(), cmp);
	for (int i = 0; i < gud.size(); i++)
		pos[gud[i]] = i;
	int mx = 0;
	vector<int> ans;
	for (int i = 0; i < gud.size(); i++)
	{
		int u = gud[i];
		if (mx == i)
			ans.push_back(u);
		for (int i = 0; i < adj[u].size(); i++)
		{
			int v = adj[u][i].first, w = adj[u][i].second;
			if (d1[u] + w + dn[v] == d1[n])
				mx = max(mx, pos[v]);
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (int p : ans)
		cout << p << ' ';
}