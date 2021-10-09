#include <bits/stdc++.h>

using namespace std;

#define int long long

typedef pair<int, int> ii;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int n = 8;

int k;
double E[111][111], f[111][111], g[111][111];

void upd(int sx, int sy)
{
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = 0;
	f[sx][sy] = 1;
	for (int _ = 1; _ <= k; _++)
	{                                   
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				g[i][j] = 0;
		for (int i = 1; i <= n; i++)		
			for (int j = 1; j <= n; j++)
				if (f[i][j] > 0.0)
				{	
					double den = 0;
					for (int z = 0; z < 4; z++)
					{
						int xx = i + dx[z];
						int yy = j + dy[z];
						if (1 <= xx && xx <= n && 1 <= yy && yy <= n)
							den += 1;
					}	
					for (int z = 0; z < 4; z++)
					{
						int xx = i + dx[z];
						int yy = j + dy[z];
						if (1 <= xx && xx <= n && 1 <= yy && yy <= n)
							g[xx][yy] += f[i][j] / den;
					}	
				}
		for (int i = 1; i <= n; i++)		
			for (int j = 1; j <= n; j++)
				f[i][j] = g[i][j];
	}
	double sum = 0;
	for (int i = 1; i <= n; i++)	
		for (int j = 1; j <= n; j++)
			sum += f[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			E[i][j] *= (sum - f[i][j]) / sum;

}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			E[i][j] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			upd(i, j);
	double ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans += E[i][j];
	cout << fixed << setprecision(6) << ans;
}