#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int p[200001];

int anc(int x) {
	if (p[x] == x) return x;
	return p[x] = anc(p[x]);
}

void join(int x, int y) {
	p[anc(x)] = anc(y);
}

int n, m, q;
vector<iii> Edge;

int h[200001];
int par[200001][21], val[200001][21];
vector<ii> adj[200001];

void dfs(int u, int pr) {
	for (int i = 0; i < adj[u].size(); i++) {
		int v = adj[u][i].first, c = adj[u][i].second;
		if (v == pr) continue;
		par[v][0] = u; val[v][0] = c;
		h[v] = h[u] + 1;
		dfs(v, u);
	}
}

void init() {
	for (int i = 1; i <= n; i++)
		if (!h[anc(i)])	{
			h[anc(i)] = 1;
			dfs(anc(i), -1);
		}	
	for (int j = 1; j <= 20; j++)
		for (int i = 1; i <= n; i++) {
			par[i][j] = par[par[i][j - 1]][j - 1];
			val[i][j] = max(val[i][j - 1], val[par[i][j - 1]][j - 1]);
		}			
}

int cal_d(int u, int v) {
	if (anc(u) != anc(v)) return -1;
	int ans = 0;
	if (h[u] > h[v]) swap(u, v);
	for (int j = 20; j >= 0; j--)
		if (h[par[v][j]] >= h[u]) {
			ans = max(ans, val[v][j]);
			v = par[v][j];
		}
	if (u == v) return ans;
	for (int j = 20; j >= 0; j--)
		if (par[u][j] != par[v][j]) {
			ans = max(ans, max(val[u][j], val[v][j]));
			u = par[u][j];
			v = par[v][j];
		}
	ans = max(ans, max(val[u][0], val[v][0]));
	return ans;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) p[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		Edge.push_back(iii(i, ii(u, v)));
	}
	sort(Edge.begin(), Edge.end());
	for (int i = 0; i < Edge.size(); i++) {
		int c = Edge[i].first;
		int u = Edge[i].second.first, v = Edge[i].second.second;
		if (anc(u) != anc(v)) {
			join(u, v);
			adj[u].push_back(ii(v, c));
			adj[v].push_back(ii(u, c));
//			cerr << u << ' ' << v << ' ' << c << '\n';
		}
	}

	init();

	for (int i = 1; i <= q; i++) {
		int u, v; cin >> u >> v;
		cout << cal_d(u, v) << '\n';
	}
}