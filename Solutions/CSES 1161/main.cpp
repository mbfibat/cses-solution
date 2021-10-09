#include <bits/stdc++.h>

using namespace std;

int x, n;
priority_queue<int, vector<int>, greater<int>> pq;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> x >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		pq.push(x);
	}
	long long ans = 0;
	while(pq.size() != 1)
	{
		int a = pq.top(); pq.pop();
		int b = pq.top(); pq.pop();
		pq.push(a + b);
		ans += a + b;
	}
	cout << ans;
}