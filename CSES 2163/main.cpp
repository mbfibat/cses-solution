#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int n, k;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	Tree<int> cur;
	for (int i = 1; i <= n; i++) cur.insert(i);

	int pos = k % n;
	for (int i = n - 1; i >= 0; i--) {
		cout << *cur.find_by_order(pos) << ' ';
		cur.erase(cur.find_by_order(pos));
		if (i)
			pos = (pos + k) % i;
	}
}