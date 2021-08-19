#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, x;
ii a[5001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}	
	sort(a + 1, a + 1 + n);

	for (int i = 1; i <= n; i++) {
		int l = i + 1, r = n;
		while (l < r) {
			if (a[i].first + a[l].first + a[r].first < x) l++;
			else if (a[i].first + a[l].first + a[r].first > x) r--;
			else {
				cout << a[i].second << ' ' << a[l].second << ' ' << a[r].second;
				return 0;
			}
		}
	}
	cout << "IMPOSSIBLE";
}