#include <bits/stdc++.h>

using namespace std;

string s;
bool vis[8][8];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
string str = "URDL";

int ans = 0;

int n = 7;

void backtrack(int pos, int x, int y) {
	if (pos >= n * n - 1) {
		ans++;
		return;
	}	
	if (x == n && y == 1) return;

	if (s[pos] == '?') {
		for (int i = 0; i < 4; i++) {
			int xx = x + dx[i];
			int yy = y + dy[i];
			if (1 <= xx && xx <= n && 1 <= yy && yy <= n && !vis[xx][yy]) {
				int xxx = xx + dx[i];
				int yyy = yy + dy[i];
				if (xxx < 1 || n < xxx || yyy < 1 || n < yyy || vis[xxx][yyy]) {
					int xl = xx + dx[(i + 1) % 4];
					int yl = yy + dy[(i + 1) % 4];
					int xr = xx + dx[(i + 3) % 4];
					int yr = yy + dy[(i + 3) % 4];
					if (1 <= xl && xl <= n && 1 <= yl && yl <= n &&
					1 <= xr && xr <= n && 1 <= yr && yr <= n && !vis[xl][yl] && !vis[xr][yr])
						continue;
				} 
				vis[xx][yy] = true;
				backtrack(pos + 1, xx, yy);
				vis[xx][yy] = false;
			}
		}
		return;
	}
	int dir = str.find(s[pos]);
   	int xx = x + dx[dir];
   	int yy = y + dy[dir];
   	if (1 <= xx && xx <= n && 1 <= yy && yy <= n && !vis[xx][yy]) {
   		int xxx = xx + dx[dir];
   		int yyy = yy + dy[dir];
   		if (xxx < 1 || n < xxx || yyy < 1 || n < yyy || vis[xxx][yyy]) {
   			int xl = xx + dx[(dir + 1) % 4];
   			int yl = yy + dy[(dir + 1) % 4];
   			int xr = xx + dx[(dir + 3) % 4];
   			int yr = yy + dy[(dir + 3) % 4];
   			if (1 <= xl && xl <= n && 1 <= yl && yl <= n &&
   			1 <= xr && xr <= n && 1 <= yr && yr <= n && !vis[xl][yl] && !vis[xr][yr])
   				return;
   		} 
   		vis[xx][yy] = true;
   		backtrack(pos + 1, xx, yy);
   		vis[xx][yy] = false;
   	}
}

int main(int argc, char** argv) {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	vis[1][1] = true;
	backtrack(0, 1, 1);
	cout << ans;
}