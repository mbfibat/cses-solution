#include <bits/stdc++.h>

using namespace std;

const int sz = 8;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int cnt = 0;
int id[sz + 1][sz + 1];

void ans()
{
	for (int i = 1; i <= sz; i++)
	{
		for (int j = 1; j <= sz; j++)
			cout << id[i][j] << ' ';
		cout << '\n';
	}
	exit(0);	
}

void backtrack(int x, int y)
{
	id[x][y] = ++cnt;
	if (cnt == sz * sz)
		ans();
	vector<iii> p;
	for (int i = 0; i < 8; i++)
	{
		int xx = x + dx[i];
		int yy = y + dy[i];
		if (1 <= xx && xx <= sz && 1 <= yy && yy <= sz && !id[xx][yy])
		{
			int pos = 0;
			for (int j = 0; j < 8; j++)
			{
				int xxx = xx + dx[j];
				int yyy = yy + dy[j];
				if (1 <= xxx && xxx <= sz && 1 <= yyy && yyy <= sz && !id[xxx][yyy])
					pos++;
			}	
			p.push_back(iii(pos, ii(xx, yy)));
		}		
	}
	sort(p.begin(), p.end());
	for (iii a : p)
		backtrack(a.second.first, a.second.second);
	id[x][y] = 0;
	cnt--;
}

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x, y;
	cin >> x >> y;
	backtrack(y, x);
}