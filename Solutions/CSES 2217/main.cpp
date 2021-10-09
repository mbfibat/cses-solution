#include <bits/stdc++.h>

using namespace std;

int n, q;
int a[200001], p[200001];

int ans = 0;
void inc(int x) {
	if (x < n && p[x + 1] < p[x]) ans++;
	if (x > 1 && p[x - 1] > p[x]) ans++;	
}

void del(int x) {
	if (x < n && p[x + 1] < p[x]) ans--;
	if (x > 1 && p[x - 1] > p[x]) ans--;	
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		p[a[i]] = i;
	}

	for (int i = 2; i <= n; i++)
		if (p[i - 1] > p[i])
			ans++;

	while (q--) {
		int l, r; cin >> l >> r;
		if (l > r) swap(l, r);
		if (l != r) {
			bool c = (abs(a[l] - a[r]) == 1);
			del(a[l]), del(a[r]);
			if (c && a[l] > a[r]) ans++;
			swap(a[l], a[r]);
			p[a[l]] = l;
			p[a[r]] = r;
			inc(a[l]);
			inc(a[r]);
			if (c && a[l] > a[r]) ans--;
		}
		cout << ans + 1 << '\n';
	}
}