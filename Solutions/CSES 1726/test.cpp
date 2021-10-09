#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n = 2, k = 4;
int a[111][111], b[111][111];

int Try()
{
	unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
	default_random_engine gen(seed);
	uniform_int_distribution<int> dis(0, 3);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			a[i][j] = 1;
	for (int _ = 1; _ <= k; _++)
	{
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				b[i][j] = 0;
		for (int i = 1; i <= n; i++)		
			for (int j = 1; j <= n; j++)
				for (int z = 1; z <= a[i][j]; z++)
					while(1)
					{
						int dir = dis(gen);
						int xx = i + dx[dir];
						int yy = j + dy[dir];
						if (1 <= xx && xx <= n && 1 <= yy && yy <= n)
						{
							b[xx][yy]++;
							break;
						}	
					}	
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				a[i][j] = b[i][j];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cnt += (!a[i][j]);
	return cnt;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	double ans = 0;
	int T = 1000;
	for (int i = 1; i <= T; i++)
		ans += Try();
	cout << fixed << setprecision(6) << ans / T;
}