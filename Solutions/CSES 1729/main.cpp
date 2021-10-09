#include <bits/stdc++.h>

using namespace std;

int n, k;
int p[101];
bool f[1000001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin  >> n >> k;
	for (int i = 1; i <= k; i++)
	{
		cin >> p[i];
		f[p[i]] = true;
	}	
	sort(p + 1, p + 1 + k);
	for (int i = 1; i <= n; i++)
	{
		cout << (f[i] ? 'W' : 'L');
		if (!f[i])
			for (int j = 1; j <= k; j++)
			{
				if (i + p[j] > n) break;
				f[i + p[j]] = true;
			}	
	}
}