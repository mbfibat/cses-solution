#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int n, x;
int a[1001];
map<int, ii> mp;

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++)
			if (mp.find(x - (a[i] + a[j])) != mp.end()) {
				cout << mp[x - (a[i] + a[j])].first << ' ' << mp[x - (a[i] + a[j])].second << ' ' << i << ' ' << j << '\n';
				return 0;
			}
		for (int j = 1; j < i; j++)
			mp[a[i] + a[j]] = ii(i, j);
	}
	cout << "IMPOSSIBLE";
}