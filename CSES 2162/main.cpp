#include <bits/stdc++.h>

using namespace std;

int n;
int nxt[200000];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	if (n == 1) return cout << 1, 0;
	for (int i = 0; i < n; i++)
		nxt[i] = (i + 1) % n;
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		cout << nxt[cur] + 1 << ' ';
		nxt[cur] = nxt[nxt[cur]];
		cur = nxt[cur];
	}
}