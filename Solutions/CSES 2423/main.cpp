#include <bits/stdc++.h>

using namespace std;

bool s;

int n, m;
char ans[101][101];

void output() {
	cout << "YES\n";
	if (s) {
		for (int j = 1; j <= m; j++) {
			for (int i = 1; i <= n; i++)	
				cout << ans[i][j];
			cout << '\n';
		}	
	} else {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				cout << ans[i][j];
			cout << '\n';
		}	
	}
}

string init[9] = {
"AABAA",
"ACBBA",
"DCCDD",
"DDBAD",
"CBBAA",
"CCDDB",
"AADBB",
"ABCCD",
"BBCDD"
};

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--) {
		cin >> n >> m;
		if (n == 1 || m == 1) {
			cout << "NO\n";
			continue;
		}	
		if (n % 3 && m % 3) {
			cout << "NO\n";
			continue;
		}
		s = false;
		if (m % 3 == 0) {
			swap(n, m);
			s = true;
		}

		if (m % 2 == 0) {
			for (int j = 1; j <= m; j += 2) {
				for (int i = 1; i <= n; i += 3) {
					ans[i][j] = ans[i][j + 1] = ans[i + 1][j] = ('A' + (j - 1) % 26);
					ans[i + 1][j + 1] = ans[i + 2][j] = ans[i + 2][j + 1] = ('A' + j % 26);
				}
			}	
		} else if (n % 2 == 0) {
			for (int i = 1; i <= n; i+= 2) {
				ans[i][1] = ans[i][2] = ans[i + 1][1] = ('A' + (i - 1) % 4);
				ans[i][3] = ans[i + 1][2] = ans[i + 1][3] = ('A' + i % 4);
			}

			for (int j = 4; j <= m; j += 2) {
				for (int i = 1; i <= n; i += 3) {
					ans[i][j] = ans[i][j + 1] = ans[i + 1][j] = ('A' + j % 26);
					ans[i + 1][j + 1] = ans[i + 2][j] = ans[i + 2][j + 1] = ('A' + (j + 1) % 26);
				}
			}				
		} else {
			if (n == 3 || m == 3) {
				cout << "NO\n";
				continue;
			}

			for (int i = 1; i <= 9; i++)
				for (int j = 1; j <= 5; j++)
					ans[i][j] = init[i - 1][j - 1];
			for (int i = 10; i <= n; i += 2) {
				ans[i][1] = ans[i][2] = ans[i + 1][1] = ('E' + i % 4);
				ans[i][3] = ans[i + 1][2] = ans[i + 1][3] = ('E' + (i + 1) % 4);
			}	
			for (int i = 10; i <= n; i += 3) {
				ans[i][4] = ans[i][5] = ans[i + 1][4] = 'I';
				ans[i + 1][5] = ans[i + 2][4] = ans[i + 2][5] = 'J';
			}

			for (int j = 6; j <= m; j += 2)
				for (int i = 1; i <= n; i += 3) {
					ans[i][j] = ans[i][j + 1] = ans[i + 1][j] = ('K' + j % 4);
					ans[i + 1][j + 1] = ans[i + 2][j] = ans[i + 2][j + 1] = ('K' + (j + 1) % 4);
				}
		}

		output();
	}
}