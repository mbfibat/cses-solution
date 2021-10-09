#include <bits/stdc++.h>

using namespace std;


int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<bool> mark(n + 1);
		for (int i = 1; i <= n; i++)
			mark[i] = false;
		int cnt = 0, ans = 0;
		for (int i = 1; ; i = (i % n) + 1) {
			if (!mark[i]) cnt++;
			if (cnt == 2) {
				cnt = 0;
				k--;
				mark[i] = true;
				if (!k) {
					ans = i;
					break;
				}
			}
		}
		cout << ans << '\n';
	}
}