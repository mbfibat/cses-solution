#include <bits/stdc++.h>

using namespace std;

int n, m;

stack<int> S;
bool vis[200001];
vector<int> adj[200001], re_adj[200001];

void dfs1(int u) {
	vis[u] = true;
	for (int v : adj[u])
		if (!vis[v])
			dfs1(v);
	S.push(u);
}

int id[200001];
vector<int> new_adj[200001];
int deg_in[200001], deg_out[200001];

void dfs2(int u, int cur_id) {
	id[u] = cur_id;
	for (int v : adj[u]) {
		if (!id[v]) 
			dfs2(v, cur_id);
		else if (id[v] < id[u])
			new_adj[id[v]].push_back(id[u]);			
	}
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs1(i);
	
	int cnt = 0;
	while (!S.empty()) {
		int u = S.top(); S.pop();
		if (!id[u])
			dfs2(u, ++cnt);
	}		

	for (int i = 1; i <= cnt; i++) {
		sort(new_adj[i].begin(), new_adj[i].end());
		new_adj[i].resize(unique(new_adj[i].begin(), new_adj[i].end()) - new_adj[i].begin());
	}		

	for (int u = 1; u <= cnt; u++)
		for (int v : new_adj[u]) {
			deg_in[v]++;
			deg_out[u]++;
		}

	vector<int> st, ed;
	for (int i = 1; i <= cnt; i++) {
		if (deg_in[i] == 0)
			st.push_back(i);
		if (deg_out[i] == 0)
	}			
}