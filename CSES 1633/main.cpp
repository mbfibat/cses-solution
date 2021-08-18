#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n;
int f[1000001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	f[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 6; j++)
			if ((i - j) >= 0)
				(f[i] += f[i - j]) %= mod;
	cout << f[n];
}