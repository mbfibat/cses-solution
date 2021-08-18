#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> adj[100001];

int d[100001], pre[100001];

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

	d[1] = 1;
	
	queue<int> q;
	q.push(1);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int v : adj[u])
			if (!d[v]) {
				d[v] = d[u] + 1;
				pre[v] = u;
				q.push(v);
			}
	}
	if (!d[n]) {
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	cout << d[n] << '\n';

	vector<int> ans; 
	int cur = n;
	while (cur) {
		ans.push_back(cur);
		cur = pre[cur];
	}
	for (auto it = ans.rbegin(); it != ans.rend(); it++)
		cout << *it << ' ';
}