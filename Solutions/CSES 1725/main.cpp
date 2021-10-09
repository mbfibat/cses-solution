#include <bits/stdc++.h>

using namespace std;

int n, a, b;
double f[601];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> a >> b;
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 6 * n; j >= 0; j--)
		{
			f[j] = 0;
			for (int k = 1; k <= 6; k++)
				if (j - k >= 0)
					f[j] += f[j - k] / 6;
		}
	double ans = 0;	
	for (int i = a; i <= b; i++)
		ans += f[i];
	cout << fixed << setprecision(6) << ans;
}