#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int a[200001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	Tree<pair<int, int>> cur;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pair<int, int> p = make_pair(a[i], i);
		cur.insert(p);
		if (i > k) cur.erase(cur.find(make_pair(a[i - k], i - k)));
		if (i >= k) cout << cur.find_by_order((k - 1) / 2) -> first << ' ';
	}
}