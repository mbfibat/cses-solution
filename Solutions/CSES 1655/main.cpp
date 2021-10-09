#include <bits/stdc++.h>

using namespace std;

int n;
int a[200001];

struct Node
{
	int nxt[2] = {-1, -1};
	Node(){}
};

struct StructTrie
{
	vector<Node> Trie = {Node()};

	void update(int x)
	{
		int cur = 0;
		for (int i = 30; i >= 0; i--)
		{
			int c = x >> i & 1;
			if (Trie[cur].nxt[c] == -1)
			{
				Trie[cur].nxt[c] = Trie.size();
				Trie.push_back(Node());
			}	
			assert(Trie[cur].nxt[c] != -1);
			cur = Trie[cur].nxt[c];
		}
	}

	int query(int x)
	{
		int cur = 0, ans = 0;
		for (int i = 30; i >= 0; i--)
		{
			ans *= 2;
			int c = x >> i & 1;
			if (Trie[cur].nxt[!c] != -1)
			{
				ans++;
				cur = Trie[cur].nxt[!c];
			}
			else
				cur = Trie[cur].nxt[c];	
		}
		return ans;
	}
}T;


int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	int pxor = 0;
	T.update(0);
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pxor ^= a[i];
		ans = max(ans, T.query(pxor));
		T.update(pxor);
	}	
	cout << ans;
}