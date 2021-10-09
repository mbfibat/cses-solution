#include <bits/stdc++.h>

using namespace std;

int n, x;
int a[101];
int f[1000001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x;
	for (int i = 1; i <= n; i++) cin >> a[i];

	f[0] = 0;
	for (int i = 1; i <= x; i++) {
		f[i] = 1e9;
		for (int j = 1; j <= n; j++) 
			if ((i - a[j]) >= 0 && f[i - a[j]] != -1)
				f[i] = min(f[i], f[i - a[j]] + 1);
		if (f[i] == 1e9) f[i] = -1;
	}
	cout << f[x];
}