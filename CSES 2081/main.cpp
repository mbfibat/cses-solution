#include <bits/stdc++.h>

using namespace std;

int n, k1, k2;
vector<int> adj[200001];

int sz;
bool mark[200001];
int nChild[200001];

void calChild(int u, int p) {
	nChild[u] = 1;
	for (int v : adj[u])
		if (!mark[v] && v != p) {
			calChild(v, u);
			nChild[u] += nChild[v];
		}
}

int findCtr(int u, int p) {
	for (int v : adj[u])
		if (!mark[v] && v != p && nChild[v] > sz / 2)
			return findCtr(v, u);
	return u;
}
                  
int BIT[200001];
void updBIT(int x, int v) {
	for (; x <= 200000; x += x & (-x)) BIT[x] += v;
}
int queryBIT(int x) {
	int ans = 0;
	for (; x > 0; x -= x & (-x)) ans += BIT[x];
	return ans;
}

long long ans = 0;

void query(int u, int p, int d) {
	if (d > k2) return;
	if (d >= k1) ans += queryBIT(k2 - d);
	else ans += queryBIT(k2 - d) - queryBIT(k1 - d - 1);
	if (k1 <= d && d <= k2) ans++;

	for (int v : adj[u]) 
		if (!mark[v] && v != p)
			query(v, u, d + 1);
}

void upd(int u, int p, int d) {
	if (d > k2) return;
	updBIT(d, 1);
	for (int v : adj[u])
		if (!mark[v] && v != p)
			upd(v, u, d + 1);
}

void del(int u, int p, int d) {
	if (d > k2) return;
	updBIT(d, -1);
	for (int v : adj[u])
		if (!mark[v] && v != p)
			del(v, u, d + 1);
}

void solve(int c) {
	for (int v : adj[c])
		if (!mark[v]) {
			query(v, c, 1);
			upd(v, c, 1);
		}
	for (int v : adj[c])
		if (!mark[v])
			del(v, c, 1);
}

void decompose(int u) {
	calChild(u, -1);
	sz = nChild[u];
	int c = findCtr(u, -1);
	solve(c);
	mark[c] = true;
	for (int v : adj[c])
		if (!mark[v])
			decompose(v);		
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k1 >> k2;
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	decompose(1);
	cout << ans;
}