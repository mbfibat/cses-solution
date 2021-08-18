#include <bits/stdc++.h>

using namespace std;

int n, k;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	double den = pow(k, n);
	double ans = 0;
	for (int mx = 1; mx <= k; mx++)
		ans += mx * (pow(mx, n) - pow(mx - 1, n)) / den;		
	cout << fixed << setprecision(6) << ans;
}