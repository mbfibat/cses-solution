#include <bits/stdc++.h>

using namespace std;

int x, n;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> x >> n;

	set<int> s;
	s.insert(0), s.insert(x);
	multiset<int> ans; ans.insert(x);
	for (int i = 1; i <= n; i++) {
		int p; cin >> p;

		auto nxt = s.upper_bound(p);
		auto pre = s.lower_bound(p); pre--;
		ans.erase(ans.find((*nxt) - (*pre)));
		ans.insert((*nxt) - p);
		ans.insert(p - (*pre));
		s.insert(p);

		cout << (*ans.rbegin()) << ' ';
	}
}