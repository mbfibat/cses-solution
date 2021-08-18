#include <bits/stdc++.h>

using namespace std;

int n, m;
int anc[100001];

int root(int u) {
	if (anc[u] == u) return u;
	return anc[u] = root(anc[u]);
}

void join(int x, int y) {
	anc[root(x)] = root(y);
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		anc[i] = i;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		join(u, v);
	}

	vector<int> ans;
	for (int i = 1; i <= n; i++)
		ans.push_back(root(i));
	sort(ans.begin(), ans.end());
	ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
	
	cout << (int)ans.size() - 1 << '\n';
	for (int i = 0; i < (int)ans.size() - 1; i++)
		cout << ans[i] << ' ' << ans[i + 1] << '\n';
}