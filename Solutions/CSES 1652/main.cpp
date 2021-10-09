#include <bits/stdc++.h>

using namespace std;

int n, q;

char c[1001][1001];
int psum[1001][1001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> c[i][j];
			psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + (c[i][j] == '*');
		}

	while (q--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << psum[x2][y2] - psum[x1 - 1][y2] - psum[x2][y1 - 1] + psum[x1 - 1][y1 - 1] << '\n';
	}
}