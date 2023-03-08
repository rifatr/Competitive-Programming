#include <bits/stdc++.h>

using namespace std;

#define lop(a, n) for(int i = a; i < n; i++)

const int N = ('z' - 'A') + 2;
int n, type, cnt[N];
string s;
bool vis[N];

int main()
{
	cin >> n >> s;

	lop(0, n) vis[s[i] - 'A'] = 1;
	lop(0, N) type += vis[i];

	int ans = (1 << 30), c = 0;
	for (int i = 0, j = 0; i < n; i++)
	{
		for (; j < n and c != type; j++)
		{
			if (!cnt[s[j] - 'A'])
				c++;

			cnt[s[j] - 'A']++;

		}

		if (c == type)
		{
			ans = min(ans, j - i);
			cnt[s[i] - 'A']--;
			if (!cnt[s[i] - 'A']) c--;
		}
	}

	cout <<  ans << '\n';

	return 0;
}