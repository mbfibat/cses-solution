#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int n;
string s[1000];
int f[1000][1000];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (s[i][j] == '*') continue;
			if (i == 0 && j == 0) f[i][j] = 1;
			else {
				if (i > 0) (f[i][j] += f[i - 1][j]) %= mod;
				if (j > 0) (f[i][j] += f[i][j - 1]) %= mod;
			}
		}
	cout << f[n - 1][n - 1];
}