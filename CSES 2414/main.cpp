#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n;
int a[101], b[5001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	cin >> n;
	for (int i = 1; i <= n * (n - 1) / 2; i++)
		cin >> b[i];
	sort(b + 1, b + 1 + n);
	int sum12 = b[1], sum13 = b[2];;
	for (int i = 3; i <= min(2 * n, n * (n - 1) / 2); i++) {
		int sum23 = b[i];
		int tot = (sum12 + sum23 + sum13) / 2;

		a[1] = tot - sum23;
		a[2] = tot - sum13;
		a[3] = tot - sum12;

		priority_queue<iii, vector<iii>, greater<iii>> pq;

		pq.push(iii(b[1], ii(1, 2)));
		pq.push(iii(b[2], ii(1, 3)));
		int cur = 4;
		bool ok = true;
		for (int j = 1; j <= n * (n - 1) / 2; j++) {
			if (pq.empty() || pq.top().first != b[j]) {
				if (cur > n) {
					ok = false;
					break;
				}	
				a[cur] = b[j] - a[1];
				pq.push(iii(a[2] + a[cur], ii(2, cur)));
				cur++;
			}
			else {
				iii tmp = pq.top();
				int val = tmp.first, l = tmp.second.first, r = tmp.second.second;
				pq.pop();
				if (l + 1 < r)
					pq.push(iii(val - a[l] + a[l + 1], ii(l + 1, r)));
			}
		}
		if (ok)
			break;
	}
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
}