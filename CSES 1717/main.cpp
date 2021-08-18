#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mod = 1e9 + 7;

int n;
ll f[1000001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	f[1] = 0;
	f[2] = 1;
	for (int i = 3; i <= n; i++)
		f[i] = (i - 1) * (f[i - 1] + f[i - 2]) % mod;
	cout << f[n];	
}