#include <bits/stdc++.h>

using namespace std;

int n;
int a[5001];
long long psum[5001];

int p[5001][5001];
long long f[5001][5001];

long long cost(int l, int r) {
	return psum[r] - psum[l - 1];
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		psum[i] = psum[i - 1] + a[i];
		f[i][i] = 0;
		p[i][i] = i;
	}	

	for (int i = n; i >= 1; i--)
		for (int j = i + 1; j <= n; j++) {
			f[i][j] = 1e18;
			for (int c = p[i][j - 1]; c <= min(j - 1, p[i + 1][j]); c++) {
				if (f[i][c] + f[c + 1][j] < f[i][j]) {
					p[i][j] = c;
					f[i][j] = f[i][c] + f[c + 1][j];
				}
			}
			f[i][j] += cost(i, j);
		}
	cout << f[1][n];  
}