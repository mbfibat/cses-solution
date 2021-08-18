#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

struct Template_EdmondKarp
{
	int n, s, t;
	queue<int> q;
	vector<int> p;
	vector<vector<int>> adj;
	vector<vector<long long>> c, f;

	void init(int _n, int _s, int _t)
	{
		n = _n, s = _s, t = _t;
		adj.resize(n + 1);
		c.resize(n + 1);
		f.resize(n + 1);
		p.resize(n + 1);
		for (int i = 0; i <= n; i++)
		{
			c[i].resize(n + 1);
			f[i].resize(n + 1);
			for (int j = 0; j <= n; j++)
				c[i][j] = f[i][j] = 0;
		}
	}

	void add_edge(int u, int v, long long _c)
	{
		adj[u].push_back(v);
		c[u][v] = _c;
		adj[v].push_back(u);
		//c[v][u] = _c; //Uncomment if edge is undirected
	}

	bool find_path()
	{
		for (int i = 0; i < p.size(); i++)
			p[i] = -1;
		queue<int> q;
		q.push(s);
		p[s] = 0;
		while (!q.empty())
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
		return p[t] != -1;
	}

	long long ans = 0;
	void upd_path()
	{
		int cur = t;
		long long mn = 1e18;
		while (cur != s)
		{
			mn = min(mn, c[p[cur]][cur] - f[p[cur]][cur]); 
			cur = p[cur];
		}
		cur = t;
		while (cur != s)
		{
			f[p[cur]][cur] += mn;
			f[cur][p[cur]] -= mn;
			cur = p[cur];
		}
		ans += mn;
	}
	
}EK; // init -> add_edge -> while(find_path()) upd_path() -> ans is the maximum flow

int n;
string s[101];
vector<int> new_adj[202];
bool vis[202];

void dfs(int u)
{
	vis[u] = true;
	for (int v : new_adj[u])
		if (!vis[v])
			dfs(v);
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> s[i]; 
		s[i] = '*' + s[i];
	}
	EK.init(2 * n + 2, 0, 2 * n + 1);
	for (int i = 1; i <= n; i++)
	{
		EK.add_edge(0, i, 1);
		EK.add_edge(i + n, 2 * n + 1, 1);
	}
	for (int i = 1; i <= n; i++)	
		for (int j = 1; j <= n; j++)
			if (s[i][j] == 'o')
				EK.add_edge(i, j + n, 1);
	while(EK.find_path())
		EK.upd_path();
	cout << EK.ans << '\n';
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			if (s[i][j] != 'o') continue;
			if (EK.f[i][j + n]) new_adj[j + n].push_back(i);
			else new_adj[i].push_back(j + n);
		}	
	for (int i = 1; i <= n; i++)								
	{
		bool ok = true;
		for (int j = 1; j <= n; j++)
			if (EK.f[i][j + n])
				ok = false;
		if (ok)
			dfs(i);
	}	
	vector<ii> ans;
	for (int i = 1; i <= n; i++)
	{
		bool ok = false;
		for (int j = 1; j <= n; j++)
			if (EK.f[i][j + n])
			{
				ok = true;
				if (vis[j + n])
					ans.push_back(ii(j, 2));
			}
		if (ok && !vis[i])
			ans.push_back(ii(i, 1));
	}
	sort(ans.begin(), ans.end());
	for (ii p : ans)
		cout << p.second << ' ' << p.first << '\n';
}