#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

string S;
int n;
int cnt[26];
set<ii> s;

void trace(int pos, int pre)
{
	if (pos == n + 1)
		return;
	int nxt_sz = n - pos; 	
	if ((nxt_sz + 1) / 2 < (*s.rbegin()).first)
	{
		ii p = (*s.rbegin());
		char c = 'A' + p.second;
		cout << c;
		s.erase(p);
		p.first--;
		cnt[p.second]--;
		if (p.first)
			s.insert(p);
		trace(pos + 1, p.second);
	}
	else
	{
		for (int i = 0; i < 26; i++)
			if (cnt[i] && i != pre)
			{
				char c = 'A' + i;
				cout << c;
				s.erase(ii(cnt[i], i));
				cnt[i]--;
				if (cnt[i])
					s.insert(ii(cnt[i], i));
				trace(pos + 1, i);	
				break;
			}	
	}
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> S;
	n = S.size();
	for (int i = 0; i < n; i++)
		cnt[S[i] - 'A']++;
	for (int i = 0; i < 26; i++)
		if (cnt[i])
			s.insert(ii(cnt[i], i));
	if ((n + 1) / 2 < (*s.rbegin()).first)
	{
		cout << -1;
		return 0;
	}
	trace(1, -1);
}