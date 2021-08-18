#include <bits/stdc++.h>

using namespace std;

int n;
int a[200011];

int l[200001], r[200001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	stack<int> S;
	S.push(0);
	for (int i = 1; i <= n; i++)
	{
		while(a[i] <= a[S.top()])
			S.pop();
		l[i] = S.top();
		S.push(i);
	}
	while(!S.empty()) S.pop();
	S.push(n + 1);
	for (int i = n; i >= 1; i--)
	{
		while(a[i] < a[S.top()])
			S.pop();
		r[i] = S.top();	
		S.push(i);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans = max(ans, 1LL * (r[i] - l[i] - 1) * a[i]);
	cout << ans;
}