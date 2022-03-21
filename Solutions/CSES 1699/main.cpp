#include <bits/stdc++.h>

using namespace std;

int n, m;
int vis[200001];
vector<int> adj[200001];
vector<int> adj2[200001];

int V = 0;
vector<int> vi;

void dfs1(int u) {
	V++;
	vis[u] = true;
	for (int v : adj2[u])
		if (!vis[v])
			dfs1(v);
	vi.push_back(u);
}

bool dfs2(int u) {
	vis[u] = 2;
	bool ok = false;
	for (int v : adj[u]) {
		if (vis[v] == 1)
			ok = ok || dfs2(v);
		else if (vis[v] == 2)
			ok = true;
	}
	vis[u] = 3;
	return ok;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj2[u].push_back(v);
		adj2[v].push_back(u);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			V = 0;
			dfs1(i);
			bool ok = false;
			while (!vi.empty()) {
				int u = vi.back();
				if (vis[u] == 1)
					ok = ok || dfs2(u);
				vi.pop_back();
			}
			if (ok) ans += V;
			else ans += (V - 1);
		}
	cout << ans;
}