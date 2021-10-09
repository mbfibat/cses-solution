#include <bits/stdc++.h>

using namespace std;

int n, q;
int a[200001];	
vector<int> adj[200001];

struct LowestCommonAncestor
{
	int par[200001][21], h[200001];
	void dfs(int u, int p)
	{
		for (int v : adj[u])
			if (v != p)
			{
				h[v] = h[u] + 1;
				par[v][0] = u;
				dfs(v, u);
			}
	}

	void init()
	{
		for (int i = 1; i <= n; i++)
			for (int j = 0; j <= 20; j++)
				par[i][j] = -1;
		dfs(1, -1);
		for (int j = 1; j <= 20; j++)
			for (int i = 1; i <= n; i++)
				par[i][j] = par[par[i][j - 1]][j - 1];
	}

	int cal_LCA(int u, int v)
	{
		if (h[u] > h[v]) swap(u, v);
		for (int j = 20; j >= 0; j--)
			if (par[v][j] != -1 && h[par[v][j]] >= h[u])
				v = par[v][j];
		if (u == v) return u;
		for (int j = 20; j >= 0; j--)
			if (par[u][j] != -1 && par[v][j] != -1 && par[u][j] != par[v][j])
			{
				u = par[u][j];
				v = par[v][j];
			}
		return par[u][0];				
	}
}LCA;
	
struct HeavyLightDecomposition
{                         
	int head[200001], nChild[200001], nxt[200001];
	void dfs(int u, int p)
	{
		nChild[u] = 1;
		nxt[u] = -1;
		int mx = 0;
		for (int v : adj[u])
			if (v != p)
			{
				dfs(v, u);
				nChild[u] += nChild[v];
				if (nChild[v] > mx)
				{
					mx = nChild[v];
					nxt[u] = v;
				}
			}	
	}

	int pos[200001], org_id[200001], top = 0;
	void build_hld(int u, int cur_h, int p)
	{
		head[u] = cur_h; pos[u] = ++top; org_id[top] = u;
		if (nxt[u] != -1)
			build_hld(nxt[u], cur_h, u);
		for (int v : adj[u])
			if (v != nxt[u] && v != p)
				build_hld(v, v, u);					
	}

	int Seg[800001];
	
	void build_Seg(int node, int l, int r)
	{
		if (l == r)
		{
			Seg[node] = a[org_id[l]];
			return;
		}
		int mi = (l + r)/2;
		build_Seg(node * 2, l, mi);	
		build_Seg(node * 2 + 1, mi + 1, r);	
		Seg[node] = max(Seg[node * 2], Seg[node * 2 + 1]);
	}

	void init()
	{
		dfs(1, -1);
		build_hld(1, 1, -1);		
		build_Seg(1, 1, n);
	}

	void upd_Seg(int node, int l, int r, int p, int val)
	{
		if (l == r)
		{
			Seg[node] = val;
			return;
		}
		int mi = (l + r)/2;
		if (p <= mi)
			upd_Seg(node * 2, l, mi, p, val);
		else	
			upd_Seg(node * 2 + 1, mi + 1, r, p, val);
		Seg[node] = max(Seg[node * 2], Seg[node * 2 + 1]);
	}

	void upd(int p, int val)
	{
		//a[p] = val;
		upd_Seg(1, 1, n, pos[p], val);
	}

	int query_Seg(int node, int l, int r, int ll, int rr)
	{
		assert(ll <= rr);
		if (r < ll || rr < l)
			return 0;
		if (ll <= l && r <= rr)
			return Seg[node];
		int mi = (l + r)/2;
		int a = query_Seg(node * 2, l, mi, ll, rr);
		int b = query_Seg(node * 2 + 1, mi + 1, r, ll, rr);
		return max(a, b);
	}

	void query(int a, int b)
	{
		int l = LCA.cal_LCA(a, b);
		int ans = 0;

		while(head[a] != head[l])
		{
//			cerr << "A: " << a << '\n';
			ans = max(ans, query_Seg(1, 1, n, pos[head[a]], pos[a]));
			a = LCA.par[head[a]][0];
		}
//		cerr << "A: " << ans << ' ' << a << '\n';
		ans = max(ans, query_Seg(1, 1, n, pos[l], pos[a]));
//		cerr << "AAA: " << pos[l] << ' ' << pos[a] << ' ' << ans << ' ' << a << '\n';

		while(head[b] != head[l])
		{
			ans = max(ans, query_Seg(1, 1, n, pos[head[b]], pos[b]));
			b = LCA.par[head[b]][0];

		}
		ans = max(ans, query_Seg(1, 1, n, pos[l], pos[b]));

		cout << ans << ' ';
	}

}HLD;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n - 1; i++)
	{
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	LCA.init();
	HLD.init();

	while (q--)
	{
		int type, u, v;
		cin >> type >> u >> v;
		if (type == 1)
			HLD.upd(u, v);
		else
			HLD.query(u, v);
	}
}