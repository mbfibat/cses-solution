#include <bits/stdc++.h>

using namespace std;

int n, k;
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
                  
map<int, int> cnt;
long long ans = 0;

void query(int u, int p, int d) {
	if (d > k) return;
	if (cnt.count(k - d))
		ans += cnt[k - d];
	for (int v : adj[u]) 
		if (!mark[v] && v != p)
			query(v, u, d + 1);
}

void upd(int u, int p, int d) {
	if (d > k) return;
	cnt[d]++;
	for (int v : adj[u])
		if (!mark[v] && v != p)
			upd(v, u, d + 1);
}

void solve(int c) {
	cnt.clear();
	cnt[0] = 1;
	for (int v : adj[c])
		if (!mark[v]) {
			query(v, c, 1);
			upd(v, c, 1);
		}
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

	cin >> n >> k;
	for (int i = 1; i <= n - 1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	decompose(1);
	cout << ans;
}