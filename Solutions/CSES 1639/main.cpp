#include <bits/stdc++.h>
 
using namespace std;
 
string s, t;
 
int f[5001][5001];
 
int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	cin >> s >> t;
	int n = s.size(), m = t.size();
 
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++) {
			if (!i && !j) {
				f[i][j] = 0;
				continue;
			}	
 
			f[i][j] = 1e9;
			if (i > 0) f[i][j] = min(f[i][j], f[i - 1][j] + 1);
			if (j > 0) f[i][j] = min(f[i][j], f[i][j - 1] + 1);
			if (i > 0 && j > 0) f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
			if (i > 0 && j > 0 && s[i - 1] == t[j - 1]) f[i][j] = min(f[i][j], f[i - 1][j - 1]);
		}
	cout << f[n][m];
}