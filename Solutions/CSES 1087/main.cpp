#include <bits/stdc++.h>

using namespace std;

string s;

int pre[101];
int nxt[1000001];
char val[1000001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s; int n = s.size(); s = '*' + s;
	pre['A'] = pre['C'] = pre['G'] = pre['T'] = n + 1;
	for (int i = n; i >= 0; i--)
	{                                                                        	
		if (pre['A'] == n + 1) val[i] = 'A';
		else if (pre['C'] == n + 1) val[i] = 'C';
		else if (pre['G'] == n + 1) val[i] = 'G';
		else if (pre['T'] == n + 1) val[i] = 'T';
		nxt[i] = max(pre['A'], max(pre['C'], max(pre['G'], pre['T'])));
		pre[s[i]] = i;
	}
	int cur = 0;
	string ans;
	while(cur != n + 1)
	{
		if (nxt[cur] == n + 1)
		{
			ans += val[cur];
			break;
		}
		cur = nxt[cur];
		ans += s[cur];
	}
	cout << ans;	
}