#include <bits/stdc++.h>

using namespace std;

int n;
int r[111];
double suf[111];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> r[i];
	suf[n + 1] = 1;
	for (int i = n; i >= 1; i--)
		suf[i] = suf[i + 1] * r[i];
	double ans = 0;	
	for (int i = 1; i <= n; i++)
	{
		double den = suf[i];
		double tmp = 0;
		for (int j = 1; j <= r[i]; j++)
			for (int k = i + 1; k <= n; k++)
				tmp += min(r[k], j - 1) * suf[i + 1] / r[k];
		ans += tmp / den;
	}
	cout << fixed << setprecision(6) << ans;
}