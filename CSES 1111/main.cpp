#include <bits/stdc++.h>

using namespace std;

string s;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> s;
	int n = s.size();
	// Manacher goes brr brr
	int ans = 0, pos = -1;
	vector<int> d1(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
	    int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
	    while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
	        k++;
	    }
	    d1[i] = k--;
	    if (i + k > r) {
	        l = i - k;
	        r = i + k;
	    }
	    if (d1[i] * 2 - 1 > ans)
	    {
	    	ans = d1[i] * 2 - 1;
	    	pos = i;
	    }
	}
	vector<int> d2(n);
	for (int i = 0, l = 0, r = -1; i < n; i++) {
	    int k = (i > r) ? 0 : min(d2[l + r - i + 1], r - i + 1);
	    while (0 <= i - k - 1 && i + k < n && s[i - k - 1] == s[i + k]) {
	        k++;
	    }
	    d2[i] = k--;
	    if (i + k > r) {
    	    l = i - k - 1;
	        r = i + k ;
	    }
	    if (d2[i] * 2 > ans)
	    {
	    	ans = d2[i] * 2;
	    	pos = i;
	    }
	}
	if (ans % 2 == 1)
	{
		for (int i = pos - ans / 2; i <= pos + ans / 2; i++)
			cout << s[i];
	}
	else
	{
		for (int i = pos - ans / 2; i <= pos + ans / 2 - 1; i++)
			cout << s[i];
	}
}