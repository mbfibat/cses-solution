#include <bits/stdc++.h>

using namespace std;
                
#define int long long

int a[3][100001];
int v[3];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= 2; i++) 
		for (int j = 1; j <= n; j++)
			cin >> a[i][j];

	int ans = 0;
	for (int j = 1; j <= n; j++) {
		v[1] += a[1][j] - 1;
		v[2] += a[2][j] - 1;
		while (v[1] * v[2] < 0) {
			ans++;
			for (int i = 1; i <= 2; i++) {
				if (v[i] < 0) v[i]++;
				else v[i]--;
			}	
		}
		for (int i = 1; i <= 2; i++)
			ans += abs(v[i]);
	}
	cout << ans;
}