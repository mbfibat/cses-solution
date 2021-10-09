#include <bits/stdc++.h>

using namespace std;

#define int long long

int q;
int n, k;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> q;
	while (q--) {
		cin >> n >> k;

		int s[2] = {1, 2}, st = 1, step = 2, sz = n;
		while (1) {
			int cnt = (sz + !st) / 2;
			if (k <= cnt) {
				cout << s[st] + (k - 1) * step << '\n';
				break;
			}
			else {
				s[st] = s[1 - st] + step;
				if (sz % 2 == 1)
					st = 1 - st;
				k -= cnt; sz -= cnt;
				if (s[0] > s[1]) swap(s[0], s[1]);
				step *= 2;
			}
		}
	}
}