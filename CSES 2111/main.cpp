#include <bits/stdc++.h>

using namespace std;

#define int long long

using cd = complex<double>;
const double PI = acos(-1);

struct Template_FFT
{
	void fft(vector<cd> &a, bool invert)
	{
	    int n = a.size();
	
	    for (int i = 1, j = 0; i < n; i++)
	    {
	        int bit = n >> 1;
	        for (; j & bit; bit >>= 1)
	            j ^= bit;
	        j ^= bit;
	
	        if (i < j)
	            swap(a[i], a[j]);
	    }
	                                                   
	    for (int len = 2; len <= n; len <<= 1)
	    {
	        double ang = 2 * PI / len * (invert ? -1 : 1);
	        cd wlen(cos(ang), sin(ang));
	        for (int i = 0; i < n; i += len)
	        {
	            cd w(1);
	            for (int j = 0; j < len / 2; j++)
	            {
	                cd u = a[i + j], v = a[i + j + len / 2] * w;
	                a[i + j] = u + v;
	                a[i + j + len / 2] = u - v;
	                w *= wlen;
	            }
	        }
	    }
	
	    if (invert)
	        for (cd &x : a)
	            x /= n;
	}
	
	vector<int> multiply(vector<int> const& a, vector<int> const& b)
	{
		vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
		int n = 1;
		while(n < a.size() + b.size())
			n <<= 1;
		fa.resize(n);
		fb.resize(n);
	
		fft(fa, false);
		fft(fb, false);
	
		for (int i = 0; i < n; i++)
			fa[i] *= fb[i];
		fft(fa, true);
	
		vector<int> result(n);
		for (int i = 0; i < n; i++)
			result[i] = long(fa[i].real() + 0.5);
		return result;
	}
}FFT;

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int k, n, m;
	cin >> k >> n >> m;
	vector<int> a(k + 1, 0), b(k + 1, 0);
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		a[x]++;
	}
	for (int i = 0; i < m; i++) {
		int x; cin >> x;
		b[x]++;
	}
	vector<int> c = FFT.multiply(a, b);
	for (int i = 2; i <= 2 * k; i++)
		cout << c[i] << ' ';
}