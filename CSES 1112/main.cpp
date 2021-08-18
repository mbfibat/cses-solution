#include <bits/stdc++.h>

using namespace std;

#define int long long

const int mod = 1e9 + 7;

int n, m;
string s;

vector<int> p(111);
void build_pre()
{
	for (int i = 1; i < m; i++)
	{
		int cur = p[i - 1];
		while (cur > 0 && s[cur] != s[i])
			cur = p[cur - 1];
		p[i] = cur + (s[cur] == s[i]);
	}	
}

int aut[111][31];

void build_aut()
{
	build_pre();
	for (int i = 0; i < m; i++)
		for (int j = 0; j < 26; j++)
		{
			if (i > 0 && 'A' + j != s[i])
				aut[i][j] = aut[p[i - 1]][j];
			else
				aut[i][j] = i + ('A' + j == s[i]);
		}          
	cerr << aut[0][0] << '\n';
} 

int f[1011][111], g[1011][111];

int dp(int pos, int cur)
{
	if (pos > n)
		return (cur == m);
	if (g[pos][cur])
		return f[pos][cur];
	int ans = 0;
	for (int i = 0; i < 26; i++)
	{
		int nxt_m = (cur == m ? m : aut[cur][i]); 
	 	(ans += dp(pos + 1, nxt_m)) %= mod;
	}
	g[pos][cur] = 1;
	return f[pos][cur] = ans;
}

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;
	m = s.size();

	build_aut();
	cout << dp(1, 0);
}