#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> ii;

int a, b, n;
ii val[200001];

int pre[200001], suf[200001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> n;
	for (int i = 1; i <= n; i++)	
		cin >> val[i].first >> val[i].second;
	sort(val + 1, val + 1 + n, greater<ii>());

	priority_queue<int> p1, p2;
	for (int i = 1; i <= a + b; i++) {
		pre[i] = pre[i - 1];
		if (i <= a) {
			pre[i] += val[i].first;
			p1.push(val[i].second - val[i].first);
		}	
		else {
			pre[i] += val[i].second;
			p2.push(val[i].first - val[i].second);
		}
		while (!p1.empty() && !p2.empty()) {
			if (p1.top() + p2.top() > 0) {
				int t1 = p1.top(), t2 = p2.top();
				p1.pop(); p2.pop();
				p1.push(-t2); p2.push(-t1);
				pre[i] += (t1 + t2);
			}
			else break;
		}
	}

	priority_queue<int> p;
	for (int i = n - 1; i >= a; i--) {
		p.push(val[i + 1].second);
		if (i >= a + b) continue;
		suf[i] = suf[i + 1] + p.top();
		p.pop();			
	}

	int ans = 0;
	for (int i = a; i <= a + b; i++) {
//		cerr << pre[i] << ' ' << suf[i] << '\n';
		ans = max(ans, pre[i] + suf[i]);
	}	
	cout << ans;	
}