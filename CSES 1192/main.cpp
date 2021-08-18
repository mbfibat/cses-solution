#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[1001][1001];
bool vis[1001][1001];

bool valid(int x, int y) {
	return (a[x][y] == '.') && (1 <= x) && (x <= n) && (1 <= y) && (y <= m);
}

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
	vis[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (valid(xx, yy) && !vis[xx][yy])
			dfs(xx, yy);
	}	
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];

	int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (valid(i, j) && !vis[i][j]) {
				cnt++;
				dfs(i, j);	
			}
	cout << cnt;
}