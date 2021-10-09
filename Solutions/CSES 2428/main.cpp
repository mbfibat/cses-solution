#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k;
int a[200001];

set<int> s;
map<int, int> cnt;

void add(int x) {
	cnt[x]++;
	if (cnt[x] == 1) s.insert(x);
}

void del(int x) {
	cnt[x]--;
	if (!cnt[x]) s.erase(x);
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	int l = 1, ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		add(a[i]);
		while (l <= i && s.size() >= k + 1)
			del(a[l++]);
		ans += i - l + 1;
	}
	cout << ans;
}