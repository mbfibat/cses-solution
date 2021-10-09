#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m;

multiset<int> S;
int par[100001], sz[100001];

int anc(int x) {
	if (par[x] == x) return x;
	return par[x] = anc(par[x]);
}

void join(int x, int y) {
	if (anc(x) == anc(y)) return;
	S.erase(S.find(sz[anc(x)]));
	S.erase(S.find(sz[anc(y)]));
	sz[anc(y)] += sz[anc(x)];
	S.insert(sz[anc(y)]);
	par[anc(x)] = anc(y);
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		par[i] = i; sz[i] = 1;
		S.insert(1);
	}
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		join(u, v);
		cout << S.size() << ' ' << (*S.rbegin()) << '\n';
	}
}