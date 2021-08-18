#include <bits/stdc++.h>

using namespace std;

int n, q;
int nxt[200001][31];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> nxt[i][0];
	for (int j = 1; j <= 30; j++)
		for (int i = 1; i <= n; i++)
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
	while (q--) {
		int u, dis;
		cin >> u >> dis;
		for (int j = 30; j >= 0; j--)
			if (dis >> j & 1)
				u = nxt[u][j];
		cout << u << '\n';
	}
}