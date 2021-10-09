#include <bits/stdc++.h>
 
using namespace std;
const string filename = "test";
 
typedef pair<int, int> ii;
 
struct CycleSort
{
	vector<int> solve(string &s)
	{
		int n = s.size();
		int cur_c = 0;
		vector<int> cnt(max(200, n), 0);
		vector<int> p(n), c(n), pn(n), cn(n);
 
		// k = 0
		for (int i = 0; i < n; i++)
			cnt[s[i]]++;
		for (int i = 1; i <= 200; i++)
			cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--)
			p[--cnt[s[i]]] = i;
		c[p[0]] = 0;
		cur_c = 1;                                                       	
		for (int i = 1; i < n; i++)
		{											
			if (s[p[i]] != s[p[i - 1]])
				cur_c++;
			c[p[i]] = cur_c - 1;
		}
		// k = 1 to ceil(log(n))
		for (int k = 0; (1 << k) < n; k++)
		{
			for (int i = 0; i < n; i++) // sort by second part
			{
				pn[i] = p[i] - (1 << k);
				if (pn[i] < 0)
					pn[i] += n;
			}
			// sort by first part
			fill(cnt.begin(), cnt.begin() + cur_c, 0);
			for (int i = 0; i < n; i++)
				cnt[c[pn[i]]]++;
			for (int i = 1; i < cur_c; i++)
				cnt[i] += cnt[i - 1];
			for (int i = n - 1; i >= 0; i--)
				p[--cnt[c[pn[i]]]] = pn[i];
			cn[p[0]] = 0;
			cur_c = 1;
			for (int i = 1; i < n; i++)
			{
				ii cur = ii(c[p[i]], c[(p[i] + (1 << k)) % n]);
				ii pre = ii(c[p[i - 1]], c[(p[i - 1] + (1 << k)) % n]);
				if (cur != pre)
					cur_c++;
				cn[p[i]] = cur_c - 1;
			}
			c.swap(cn);
		}
		return p;
	}
}CS;
 
string s;
 
int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
    freopen( (filename + ".inp").c_str(), "r", stdin);
    freopen( (filename + ".out").c_str(), "w", stdout);

	cin >> s;
	vector<int> p = CS.solve(s);
	rotate(s.begin(), s.begin() + p[0], s.end());
	cout << s;
	cerr << "nTime elapsed: " << 1000*clock()/CLOCKS_PER_SEC << " ms\n";
}