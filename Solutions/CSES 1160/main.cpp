#include <bits/stdc++.h>

using namespace std;

int n, q;
stack<int> S;
bool vis[200001];
int nxt[200001];
vector<int> r_nxt[200001];

void dfs1(int u)
{
	vis[u] = true;
	if (!vis[nxt[u]])
		dfs1(nxt[u]);
	S.push(u);
}

int c, top;
int id[200001], v[200001];
vector<int> n_nxt[200001];

int pos_in_cycle[200001];
vector<int> pos[200001];
bool is_root[200001];

void dfs2(int u)
{
	pos_in_cycle[u] = pos[top].size();
	pos[top].push_back(u);
	c++;
	id[u] = top;
	vis[u] = true;
	for (int v : r_nxt[u])
		if (!vis[v])
			dfs2(v);
		else if (id[v] != top)
		{
			is_root[id[v]] = false;
			n_nxt[top].push_back(id[v]);
		}	
}

int z = 0;
int h[200001];
int r[200001];
int st[200001], ed[200001];

void build(int u, int cur_r)
{
	vis[u] = true;
	r[u] = cur_r;
	st[u] = ++z;
	for (int v : n_nxt[u])
	{
		h[v] = h[u] + 1;
		build(v, cur_r);
	}	
	ed[u] = ++z;
}

bool check(int a, int b)
{
	return (st[b] <= st[a] && ed[a] <= ed[b]);
}

int f[200001], g[200001];

int find_e(int u)
{
	if (id[u] == r[id[u]])
		return u;
	if (g[u])
		return f[u];
	g[u] = 1;
	return f[u] = find_e(nxt[u]);
}

int find_d(int a, int b) // ordered, a and b is in same cycle
{
	int l = pos_in_cycle[a], r = pos_in_cycle[b];
	//cerr << a << ' ' << b << ' ' << l << ' ' << r << '\n';
	if (l >= r) return l - r;
	return (pos[id[a]].size() - r + l);
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		nxt[i] = x;
		r_nxt[x].push_back(i);
	}
	for (int i = 1; i <= n; i++)      
		if (!vis[i])
			dfs1(i);
	memset(vis, false, sizeof vis);
	for (int i = 1; i <= 200000; i++)
		is_root[i] = true;
	while(!S.empty())
	{
		int u = S.top();
		S.pop();
		if (!vis[u])
		{
			c = 0;
			top++;
			dfs2(u);
			v[top] = c;
		}
	}
	memset(vis, false, sizeof vis);
	for (int i = 1; i <= n; i++)
		if (is_root[id[i]] && !vis[id[i]])
			build(id[i], id[i]);
//	for (int i = 1; i <= n; i++)
//		cerr << '!' << i << ' ' << id[i] << '\n';
	while(q--)
	{
		int a, b;
		cin >> a >> b;
		if (a == b) 
		{
			cout << 0 << '\n';
			continue;
		}	
		if (!check(id[a], id[b])) cout << -1 << '\n';
		else if (id[b] != r[id[b]]) cout << h[id[a]] - h[id[b]] << '\n';
		else
		{
			int c = find_e(a);
			cout << h[id[a]] + find_d(c, b) << '\n';
		}
	}
}