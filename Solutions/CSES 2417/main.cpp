#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
int a[100001];

int f[1000001], g[1000001];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f[a[i]]++;
	}

	for (int i = 1; i <= 1000000; i++)
		for (int j = i * 2; j <= 1000000; j += i)
			f[i] += f[j];
	for (int i = 1000000; i >= 1; i--) {
		g[i] = f[i] * (f[i] - 1) / 2;
		for (int j = i * 2; j <= 1000000; j += i)
			g[i] -= g[j];
	}	
	cout << g[1];
}