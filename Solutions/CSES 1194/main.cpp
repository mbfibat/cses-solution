#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
char dp[4] = {'D', 'L', 'U', 'R'};

int n, m;
int xs, ys;
vector<ii> posMonster;
char a[1001][1001], pre[1001][1001];

int disMonster[1001][1001], disPlayer[1001][1001];

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)		
		for (int j = 1; j <= m; j++) {
			disMonster[i][j] = disPlayer[i][j] = 1e9;
			cin >> a[i][j];
			if (a[i][j] == 'M') {
				posMonster.push_back(ii(i, j));
				disMonster[i][j] = 0;
			}	
			else if (a[i][j] == 'A') {
				xs = i, ys = j;
				disPlayer[i][j] = 0;
			}
		}

	queue<ii> q;
	for (ii p : posMonster)
		q.push(p);
	while(!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (1 <= xx && xx <= n && 1 <= yy && yy <= m && a[xx][yy] != '#' && disMonster[xx][yy] == 1e9) {
				disMonster[xx][yy] = disMonster[x][y] + 1;
				q.push(ii(xx, yy));
			}
		}
	}
	q.push(ii(xs, ys));
	while(!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (1 <= xx && xx <= n && 1 <= yy && yy <= m && a[xx][yy] != '#' && disPlayer[xx][yy] == 1e9 && disMonster[xx][yy] > disPlayer[x][y] + 1) {
				disPlayer[xx][yy] = disPlayer[x][y] + 1;
				pre[xx][yy] = (i + 2) % 4;
				q.push(ii(xx, yy));
			}
		}
	}
	for (int i = 1; i <= n; i++)	
		for (int j = 1; j <= m; j++)
			if (i == 1 || i == n || j == 1 || j == m) {
				if (disPlayer[i][j] != 1e9) {
					cout << "YES\n";
					cout << disPlayer[i][j] << '\n';

					string ans;
					int x = i, y = j;
					while (x != xs || y != ys) {
						int dir = pre[x][y];
						ans += dp[dir];
						x += dx[dir];
						y += dy[dir];
					}
					reverse (ans.begin(), ans.end());
					cout << ans;
					return 0;
				}
			}
	cout << "NO";
}