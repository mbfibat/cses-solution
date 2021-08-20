#include <bits/stdc++.h>

using namespace std;

int a, b;

int f[501][501];
bool mf[501][501];

int dp(int a, int b) {
	if (a == b) return 0;
	if (mf[a][b]) return f[a][b];

	int cur = 1e9;
	for (int i = 1; i <= a / 2; i++) cur = min(cur, dp(i, b) + dp(a - i, b) + 1);
	for (int i = 1; i <= b / 2; i++) cur = min(cur, dp(a, i) + dp(a, b - i) + 1);

	mf[a][b] = true;
	return f[a][b] = cur;
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b;
	cout << dp(a, b);
}