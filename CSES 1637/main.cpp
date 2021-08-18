#include <bits/stdc++.h>

using namespace std;

int n;
int f[1000001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	f[0] = 0;
	for (int i = 1; i <= n; i++) {
		f[i] = 1e9;
		int x = i;
		while (x != 0) {
			int d = x % 10;
			f[i] = min(f[i], f[i - d] + 1);
			x /= 10;
		}
	}
	cout << f[n];
}