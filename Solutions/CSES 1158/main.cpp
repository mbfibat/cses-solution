#include <bits/stdc++.h>

using namespace std;

int n, x;
int a[1001], b[1001];

int f[100001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];


	for (int i = 1; i <= n; i++)
		for (int j = x; j >= 0; j--)
			if (j - a[i] >= 0)
				f[j] = max(f[j], f[j - a[i]] + b[i]);

	int ans = 0;
	for (int j = 0; j <= x; j++) ans = max(ans, f[j]);
	cout << ans;
}