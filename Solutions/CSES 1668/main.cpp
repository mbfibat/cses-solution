#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100001];

int col[100001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (col[i]) continue;
    	col[i] = 1;
    	queue<int> q; q.push(i);

    	while(!q.empty()) {
    		int u = q.front(); q.pop();
    		for (int v : adj[u]) {
    			if (!col[v]) {
    				col[v] = 3 - col[u];
    				q.push(v);
    			}
    			else if (col[v] == col[u]) {
    				cout << "IMPOSSIBLE";
    				return 0;
    			}	
    		}
    	}
	}
	for (int i = 1; i <= n; i++)
		cout << col[i] << ' ';
}