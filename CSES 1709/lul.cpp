struct Template_EdmondKarp
{
	int n, s, t;
	queue<int> q;
	vector<vector<int>> adj, p;
	vector<vector<long long>> c, f;

	void init(int _n, int _s, int _t)
	{
		n = _n, s = _s, t = _t;
		adj.resize(n + 1);
		c.resize(n + 1);
		f.resize(n + 1);
		d.resize(n + 1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				c[i][j] = f[i][j] = 0;
	}

	void add_edge(int u, int v, long long _c)
	{
		adj[u].push_back(v);
		c[u][v] = c;
		adj[v].push_back(u);
		//c[v][u] = c; Uncomment if edge is undirected
	}

	bool find_path()
	{
		for (int i = 0; i < d.size(); i++)
			p[i] = 0;
		queue<int> q;
		q.push(s);
		p[s] = -1;
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			for (int v : adj[u])
				if (!p[v] && c[u][v] < f[u][v])
				{
					p[v] = u;
					q.push(v);
				}
		}
		return p[t];
	}

	long long ans = 0;
	void upd_path()
	{
		int cur = t;
		long long mn = 1e18;
		while (cur != s)
		{
			mn = min(mn, c[p[cur][cur]] - f[p[cur]][cur]); 
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
}EK; // init -> add_edge -> while(find_path()) upd_path() -> EK.ans is the maximum flow