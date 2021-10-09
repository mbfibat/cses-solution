#include <bits/stdc++.h>

using namespace std;

int n;
int a[200001], deg[200001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		deg[i] = 1;
	for (int i = 1; i <= n - 2; i++)
	{
		cin >> a[i];
		deg[a[i]]++;
	}
	int ptr = 0;
	while(deg[++ptr] != 1){}
	int leaf = ptr;
	for (int i = 1; i <= n - 2; i++)
	{
		cout << leaf << ' ' << a[i] << '\n';
		if (--deg[a[i]] == 1 && a[i] < ptr)
			leaf = a[i];
		else
		{
			while(deg[++ptr] != 1){}
			leaf = ptr;
		}
	}
	cout << leaf << ' ' << n;
}