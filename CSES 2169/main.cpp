#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n;
iii a[200001];

int cntIn[200001], cntOut[200001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		a[i].first = i;
		cin >> a[i].second.first >> a[i].second.second;
	}

	auto cmp1 = [&](const iii& lhs, const iii& rhs) -> bool {
		if (lhs.second.second != rhs.second.second) return lhs.second.second < rhs.second.second;
		return lhs.second.first > rhs.second.first;
	};
	sort(a + 1, a + 1 + n, cmp1);

	Tree<ii> t1;
	for (int i = 1; i <= n; i++) {
		cntIn[a[i].first] = (int)t1.size() - t1.order_of_key(ii(a[i].second.first, 0));
		t1.insert(ii(a[i].second.first, i));
	}

	auto cmp2 = [&](const iii& lhs, const iii& rhs) -> bool {
		if (lhs.second.second != rhs.second.second) return lhs.second.second > rhs.second.second;
		return lhs.second.first < rhs.second.first;
	};
	sort(a + 1, a + 1 + n, cmp2);

	Tree<ii> t2;
	for (int i = 1; i <= n; i++) {
		cntOut[a[i].first] = t2.order_of_key(ii(a[i].second.first, 1e9));
		t2.insert(ii(a[i].second.first, i));
	}

	for (int i = 1; i <= n; i++)
		cout << cntIn[i] << ' ';
	cout << '\n';	
	for (int i = 1; i <= n; i++)	
		cout << cntOut[i] << ' ';
}