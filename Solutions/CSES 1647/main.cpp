#include <bits/stdc++.h>

using namespace std;

int a[200001];
int val[200001][21], mask[200001];

int comb(int x, int y) {
	return min(x, y);
}

void init(int l, int r, int lev) {
	if (l == r) 
		return;

	int mi = (l + r) / 2;
	val[mi][lev] = a[mi];
	for (int i = mi - 1; i >= l; i--)
		val[i][lev] = comb(a[i], val[i + 1][lev]);

	val[mi + 1][lev] = a[mi + 1];
	for (int i = mi + 2; i <= r; i++)
		val[i][lev] = comb(a[i], val[i - 1][lev]);
	for (int i = mi + 1; i <= r; i++)
		mask[i] |= (1 << lev);
	init(l, mi, lev + 1);
	init(mi + 1, r, lev + 1);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

 	int n, q; 
 	cin >> n >> q;
 	for (int i = 1; i <= n; i++)
 		cin >> a[i];
	init(1, n, 0);
	while (q--) {
		int l, r;
		cin >> l >> r;
		if (l == r) cout << a[l] << '\n';
		else {
			int lev = __builtin_ctz(mask[l] ^ mask[r]);
			cout << comb(val[l][lev], val[r][lev]) << '\n';
		}
	}
}