#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, ii> iv;

int p[100011], sz[100011];

int anc(int x) {
	if (p[x] == x) return x;
	return anc(p[x]);
}

iv join(int u, int v) {
	if (sz[anc(u)] > sz[anc(v)]) swap(u, v);
	int au = anc(u), av = anc(v), pu = p[au], szv = sz[av];
	sz[av] += sz[au];
	p[au] = av;
	return iv(ii(au, av), ii(pu, szv));
}

vector<ii> Seg[400011];

void update(int node, int l, int r, int ll, int rr, int u, int v) {	
	if (r < ll || rr < l) return;
	if (ll <= l && r <= rr) {
		Seg[node].push_back(ii(u, v));
		return;
	}
	int mi = (l + r)/2;
	update(node * 2, l, mi, ll, rr, u, v);
	update(node * 2 + 1, mi + 1, r, ll, rr, u, v);
	return;
}

void trav(int node, int l, int r, int c) {
//	cerr << '!' << node << ' ' << l << ' ' << r << ' ' << c << ' ' << Seg[node].size() << '\n';
	vector<iv> upd;
	for (int i = 0; i < Seg[node].size(); i++) {
		int u = Seg[node][i].first, v = Seg[node][i].second;
		if (anc(u) != anc(v)) {
			c--;
			upd.push_back(join(u, v));
		}
	}
	if (l == r) {
		cout << c << ' ';
		for (int i = 0; i < upd.size(); i++) {
			p[upd[i].first.first] = upd[i].second.first;			
			sz[upd[i].first.second] = upd[i].second.second;			
		}
		return;
	}
	int mi = (l + r)/2;
	trav(node * 2, l, mi, c);
	trav(node * 2 + 1, mi + 1, r, c);
	for (int i = 0; i < upd.size(); i++) {
		p[upd[i].first.first] = upd[i].second.first;			
		sz[upd[i].first.second] = upd[i].second.second;			
	}
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		sz[i] = 1;
	}	
	vector<iv> upd;
	map<ii, int> E;
	for (int i = 1; i <= m; i++) {
		int u, v; cin >> u >> v;
		if (u > v) swap(u, v);
		E[ii(u, v)] = 0;
	}
	for (int i = 1; i <= k; i++) {
		int t, u, v; cin >> t >> u >> v;
		if (u > v) swap(u, v);
		if (t == 1)
			E[ii(u, v)] = i;
		else {
			upd.push_back(iv(ii(u, v), ii(E[ii(u, v)], i - 1)));
			E.erase(E.find(ii(u, v)));
		}
	}
	for (auto it : E)
		upd.push_back(iv(ii(it.first.first, it.first.second), ii(it.second, k)));
	for (iv cur : upd) {
		int u = cur.first.first, v = cur.first.second, st = cur.second.first, ed = cur.second.second;
//		cerr << u << ' ' << v << ' ' << st << ' ' << ed << '\n';
		update(1, 0, k, st, ed, u, v);
	}
	trav(1, 0, k, n);
}