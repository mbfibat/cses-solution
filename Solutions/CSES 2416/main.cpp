#include <bits/stdc++.h>

using namespace std;

template <typename T>
inline void Read(T& x)
{
    bool Neg = false;
    char c;
    for (c = getchar(); c < '0' || c > '9'; c = getchar())
        if (c == '-') Neg = !Neg;
    x = c - '0';
    for (c = getchar(); c >= '0' && c <= '9'; c = getchar())
        x = x * 10 + c - '0';
    if (Neg) x = -x;
}

template <typename T>
inline void Write(T x)
{
    if (x < 0)
    {
        putchar('-'); x = -x;
    }
    T p = 1;
    for (T temp = x / 10; temp > 0; temp /= 10) p *= 10;
    for (; p > 0; x %= p, p /= 10) putchar(x / p + '0');
}

int n, q;
int a[200011], nxt[200011][21];
long long val[200011][21], psum[200011];

int32_t main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Read(n); Read(q);
	for (int i = 1; i <= n; i++)
	{
		Read(a[i]);
		psum[i] = psum[i - 1] + a[i];
	}	
	stack<int> S;
	for (int i = 1; i <= n + 1; i++)
		for (int j = 0; j <= 20; j++)
			nxt[i][j] = n + 1;
	for (int i = 1; i <= n; i++)
	{
		while(!S.empty() && a[i] > a[S.top()])
		{
			nxt[S.top()][0] = i;			
			val[S.top()][0] = ((long long)a[S.top()]) * (i - S.top() - 1) - (psum[i - 1] - psum[S.top()]);
			S.pop();
		}
		S.push(i);
	}
	for (int j = 1; j <= 20; j++)
		for (int i = 1; i <= n; i++)
		{
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
			val[i][j] = val[i][j - 1] + val[nxt[i][j - 1]][j - 1];
		}
	while (q--)
	{
		int l, r;
		Read(l); Read(r);
		int pos = l;
		long long ans = 0;
		for (int j = 20; j >= 0; j--)
			if (nxt[pos][j] <= r)
			{
				ans += val[pos][j];
				pos = nxt[pos][j];
			}
		ans += ((long long)a[pos]) * (r - pos) - (psum[r] - psum[pos]);
		Write(ans); putchar('\n');
	}			
}