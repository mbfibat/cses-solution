#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n, x;
int a[101];
int f[1000001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> x;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	f[0] = 1;
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= n; j++)
			if ((i - a[j]) >= 0)
				(f[i] += f[i - a[j]]) %= mod;
	cout << f[x];
}