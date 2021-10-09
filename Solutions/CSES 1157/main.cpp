#include <bits/stdc++.h>

using namespace std;

int a[101][101];
bool mark[10001];

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
		{
			if (i == 1 && j == 1)
			{
				a[i][j] = 0;
				continue;
			}
			for (int k = 0; k <= 10000; k++)
				mark[k] = false;
			for (int k = 1; k < i; k++)
				mark[a[k][j]] = true;
			for (int l = 1; l < j; l++)
				mark[a[i][l]] = true;
			for (int k = 0; k <= 10000; k++)
				if (!mark[k])
				{
					a[i][j] = k;
					break;
				}
		}
	for (int i = 1; i <= 50; i++)
	{
		for (int j = 1; j <= 50; j++)
			cout << a[i][j] << ' ';
		cout << '\n';	
	}
}