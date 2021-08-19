#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n;
ii a[200001];

int pos[200001], ans[200001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;

	for (int i = 1; i <= n; i++) pos[i] = i;
	sort(pos + 1, pos + 1 + n, [&] (const int &lhs, const int &rhs) -> bool {
		return a[lhs].first < a[rhs].first;		
	});

	int cur = 0;
	set<ii> s;
	for (int i = n; i >= 1; i--) {
		int p = pos[i];
		auto it = s.lower_bound(ii(a[p].second + 1, 0));
		if (it == s.end()) {
			ans[p] = ++cur;
		}
		else {
			ans[p] = it -> second;
			s.erase(it);
		}	
		s.insert(ii(a[p].first, ans[p]));
	}

	cout << cur << '\n';
	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}