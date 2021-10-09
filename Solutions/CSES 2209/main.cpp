#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 1e9 + 7;

int n, m;
int pow_m[1000001];

int qp(int a, int b)
{
  if (b == 0)
    return 1;
  int tmp = qp(a, b / 2);
  if (b % 2) return tmp * tmp % mod * a % mod;
  return tmp * tmp % mod;
}

int32_t main() 
{
  cin >> n >> m;
  pow_m[0] = 1;
  for (int i = 1; i <= 1000000; i++)
    pow_m[i] = pow_m[i - 1] * m % mod;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    ans = (ans + pow_m[__gcd(i, n)])%mod;
  ans = ans * qp(n, mod - 2) % mod;
  cout << ans;
  return 0;
}