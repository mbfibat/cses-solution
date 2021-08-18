#include <bits/stdc++.h>

using namespace std;

#define int long long

int n;
int f[20][20][2], g[20][20][2], ans[20];

int cal(int pos, int cnt_1, bool f1)
{            
	if (pos > 19)
	{
		if (f1) return cnt_1;
		return 0;
	}	
	if (g[pos][cnt_1][f1])
		return f[pos][cnt_1][f1];
	int cur = 0;
	for (int i = 0; i <= 9; i++)
		cur += cal(pos + 1, cnt_1 + (i == 1), (f1 || i));
	g[pos][cnt_1][f1] = 1;
	return f[pos][cnt_1][f1] = cur;	
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	int pre_1 = 0;
	for (int i = 1; i <= 19; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (cal(i + 1, pre_1 + (j == 2), 0) + pre_1 + (j == 1) > n)
			{
				ans[i] = j - 1;
				if (ans[i] == 1) pre_1++;
				break;
			}	
			n -= cal(i + 1, pre_1 + (j == 2), 0) + pre_1 + (j == 1);
			if (j == 9)
				ans[i] = 9;
		}	
	}
	for (int i = 1; i <= 19; i++)
		if (ans[i])
		{
			for (int j = i; j <= 19; j++)
				cout << ans[j];
			return 0;
		}
}   