#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	priority_queue<int> pq; pq.push(0);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		pq.push(x);
		if (x < pq.top()) {
			pq.push(x);
			ans += abs(pq.top() - x);
			pq.pop();
		}
	}
	cout << ans;
}