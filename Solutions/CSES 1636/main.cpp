#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n, x;
int f[1000001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x;
	f[0] = 1;
	for (int i = 1; i <= n; i++) {
		int t; cin >> t;
		for (int j = 0; j <= x; j++)
			if (j + t <= x)
				(f[j + t] += f[j]) %= mod;
	}
	cout << f[x];
}