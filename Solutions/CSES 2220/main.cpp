#include <bits/stdc++.h>

using namespace std;

#define int long long

string a, b;

int f[21][11][2][2];
bool g[21][11][2][2];

int dp(int pos, int pre, bool f1, bool f2, string &cur) {
	if (pos > 20) return f1;
	if (g[pos][pre][f1][f2]) return f[pos][pre][f1][f2];

	int cnt = 0;
	for (int d = 0; d <= 9; d++) {
		if (d == pre) continue;
		if (!f2 && (d > cur[pos] - '0')) continue;
		int nxt_d = ((!f1 && !d) ? 10 : d);
		bool nxt_f1 = (f1 || d != 0); 
		bool nxt_f2 = (f2 || (d < cur[pos] - '0'));
		cnt += dp(pos + 1, nxt_d, nxt_f1, nxt_f2, cur);
	}

	g[pos][pre][f1][f2] = 1;
	return f[pos][pre][f1][f2] = cnt;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b;

	bool ok = true;
	for (int i = 0; i < (int)a.size(); i++)
		if (a[i] == a[i + 1]) {
			ok = false;
			break;
		}

	while (a.size() <= 20) a = '0' + a;
	while (b.size() <= 20) b = '0' + b;

	memset(g, false, sizeof g);
	int r = dp(0, 10, 0, 0, b);
	memset(g, false, sizeof g);
	int l = dp(0, 10, 0, 0, a);

	cout << r - l + ok;		  
}