#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> ii;

int n, x;
int a[101], b[101], c[101];
int f[100001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];

	vector<ii> v;
	for (int i = 1; i <= n; i++) {
		cin >> c[i];
		int cnt = 1;
		while (cnt <= c[i]) {
			v.push_back(ii(cnt * a[i], cnt * b[i]));			
			c[i] -= cnt;
			cnt *= 2;
		}
		if (c[i]) 
			v.push_back(ii(c[i] * a[i], c[i] * b[i]));			
	}	
	for (int i = 0; i < v.size(); i++)
		for (int w = x; w >= 0; w--)
			if (w + v[i].first <= x)
				f[w + v[i].first] = max(f[w + v[i].first], f[w] + v[i].second);
	cout << *max_element(f, f + 1 + x);
}