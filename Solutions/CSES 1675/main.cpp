#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m;
vector<int> adj;

int par[100001];

int anc(int x) {
	if (par[x] == x) return x;
	return par[x] = anc(par[x]);
}

void join(int x, int y) {
	par[anc(x)] = anc(y);
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) par[i] = i;
	vector<iii> E;
	for (int i = 1; i <= m; i++) {
		int u, v, c; cin >> u >> v >> c;
		E.push_back(iii(c, ii(u, v)));
	}
	sort(begin(E), end(E));

	long long ans = 0;
	for (int i = 0; i < E.size(); i++) {
		int u = E[i].second.first, v = E[i].second.second;
		if (anc(u) != anc(v)) {
			join(u, v);
			ans += E[i].first;
		}
	}
	for (int i = 1; i <= n; i++)
		if (anc(i) != anc(1)) {
			cout << "IMPOSSIBLE";
			return 0;
		}
	cout << ans;
}