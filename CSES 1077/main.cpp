#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k;
int a[200001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	int s1 = 0, s2 = 0;

	multiset<int> mn;
	multiset<int, greater<int>> mx; 

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (mx.empty() || a[i] <= (*mx.begin())) {
			s1 += a[i];
			mx.insert(a[i]);
		}
		else {
			s2 += a[i];
			mn.insert(a[i]);	
		}
		if (i > k) {
			if (mx.find(a[i - k]) != mx.end()) {
				s1 -= a[i - k];
				mx.erase(mx.find(a[i - k]));
			}	
			else {
				s2 -= a[i - k];
				mn.erase(mn.find(a[i - k]));		
			}
		}
		while (mx.size() >= mn.size() + 2) {
			s2 += (*mx.begin());
			s1 -= (*mx.begin());
			mn.insert(*mx.begin());
			mx.erase(mx.begin());
		}
		while (mn.size() >= mx.size() + 1) {
			s1 += (*mn.begin());
			s2 -= (*mn.begin());
			mx.insert(*mn.begin());
			mn.erase(mn.begin());
		}

		if (i >= k) {
			int val = (*mx.begin());
			cout << s2 - mn.size() * val + mx.size() * val - s1 << ' ';
		}
	}
}