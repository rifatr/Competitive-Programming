#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

typedef long long ll;

int p[200005];

int findrep(int x)
{
	if (p[x] == x)
		return x;
	return p[x] = findrep(p[x]);
}

void Union(int a, int b)
{
	p[findrep(b)] = findrep(a);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

#ifndef ONLINE_JUDGE
	auto start = high_resolution_clock::now();
	freopen("/home/rifat/input.txt", "r", stdin);
	freopen("/home/rifat/output.txt", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;

	ll a[n], b[n], c[n];

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		p[i] = i;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i];
	}

	for (int i = 0; i < n; i++)
		c[i] = b[i] - a[i];

	for (int i = 0; i < m; ++i)
	{
		int x, y;
		cin >> x >> y;
		Union(y - 1, x - 1);
	}

	for (int i = 0; i < n; i++)
	{
		int x = findrep(i);
		//cout << i + 1 << ' ' << ++x << endl;
	}

	ll aa[n + 1] = {0};

	for (int i = 0; i < n; i++)
		aa[p[i]] += c[i];

	for (int i = 0; i < n; ++i)
	{
		if (aa[i] != 0LL)
		{
			cout << "No\n";
			return 0;
		}
	}

	cout << "Yes\n";



#ifndef ONLINE_JUDGE
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);
	cout << "\nTime: " << duration.count() << "ms" << endl;
#endif

	return 0;
}