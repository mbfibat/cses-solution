#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> ii;
 
int n, D;
int h[200001];
vector<int> adj[200001];

int pos = 0;
int arr[400001], val[400001];
int rmq[400001][21];
int st[200001], ed[200001];
 
void dfs(int u, int p) {
	st[u] = ++pos;
	val[st[u]] = u;
	arr[pos] = st[u];
	for (int v : adj[u]) {
		if (v == p) continue;
		h[v] = h[u] + 1;
		dfs(v, u);
	}
	ed[u] = pos;
	if (p) arr[++pos] = st[p]; 
}
 
int cal_lca(int u, int v) {
	int l = st[u], r = st[v];
	if (l > r) swap(l, r);
	int d = (r - l + 1);
	int k = log2(d);
	int ans = min(rmq[l][k], rmq[r - (1 << k) + 1][k]);
//	cerr << ans << ' ';
	return val[ans];
}
 
int dist(int u, int v) {
	int l = cal_lca(u, v);
//	cerr << '!' << u << ' ' << v << ' ' << l << '\n';
	return h[u] + h[v] - 2 * h[l];
}
 
int cur_sz = 0;
int sz[200001];
bool done[200001];
int d[200001], par_c[200001];
 
void cal_sz(int u, int p) {
	sz[u] = 1;
	for (int v : adj[u])
		if (!done[v] && v != p) {
			cal_sz(v, u);
			sz[u] += sz[v];
		}
}
 
int find_c(int u, int p) {
	for (int v : adj[u])
		if (!done[v] && v != p && sz[v] > cur_sz / 2)
			return find_c(v, u);
	return u;
}
 
void build_c(int u, int p) {
	cal_sz(u, 0);
	cur_sz = sz[u];
	int c = find_c(u, 0);
	done[c] = true;
	par_c[c] = p;
//	cerr << u << ' ' << c << ' ' << p << '\n';
	for (int v : adj[c])
		if (!done[v])
			build_c(v, c);
}
 
int query(int u) {
	int mn = 1e9, org = u;
	while (u) {
		mn = min(mn, dist(org, u) + d[u]);
		u = par_c[u];
	}
	return mn;
}
 
void update(int u) {
	int org = u;
	while (u) {
		d[u] = min(d[u], dist(org, u));
		u = par_c[u];
	}
}
 
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cin >> n >> D;
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	h[1] = 1;
	dfs(1, 0);
	for (int i = 1; i <= pos; i++) rmq[i][0] = arr[i];
	for (int j = 1; j <= 20; j++)
		for (int i = 1; i + (1 << j) - 1 <= pos; i++)
			rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
 
	vector<ii> ord;
	for (int i = 1; i <= n; i++) ord.emplace_back(h[i], i);
	sort(ord.begin(), ord.end(), greater<ii>());
 
	build_c(1, 0);                   
 
	for (int i = 1; i <= n; i++) d[i] = 1e9;
	vector<int> ans;
	for (auto& [h, u] : ord)
		if (query(u) >= D) {
			update(u);
			ans.push_back(u);
		}		
 
	cout << ans.size() << '\n';
	for (int u : ans) cout << u << ' ';
}