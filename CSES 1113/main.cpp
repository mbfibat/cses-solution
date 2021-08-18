#include <bits/stdc++.h>

using namespace std;

typedef pair<char, int> ci;
string s;
int nxt[1000001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	vector<ci> p;
	for (int i = 0; i < s.size(); i++)
		p.push_back(ci(s[i], i));
	sort(p.begin(), p.end());
	for (int i = 0; i < s.size(); i++)
		nxt[i] = p[i].second;
	int cur = nxt[0];
	while (cur != 0)
	{
		cout << p[cur].first;
		cur = nxt[cur];
	}
}