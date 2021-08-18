#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, q;
int a[200001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	Tree< pair<int, int> > s;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		s.insert(make_pair(a[i], i));		
	}

	while (q--) {
		char c; cin >> c;
		if (c == '!') {
			int p, x; cin >> p >> x;
			s.erase(make_pair(a[p], p));
			a[p] = x;
			s.insert(make_pair(a[p], p));
		}
		else {
			int l, r; cin >> l >> r;
			cout << s.order_of_key(make_pair(r + 1, 0)) - s.order_of_key(make_pair(l, 0)) << '\n';
		}
	}
}