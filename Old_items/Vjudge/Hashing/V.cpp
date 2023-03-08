#include<iostream>
#include<map>
#include<string>
#include<cstdlib>
#include<cstdio>
#include <vector>

using namespace std;

typedef long long ll;

const ll N = 1e6 + 23, mod1 = 1055482763, base1 = 1051, mod2 = 2113605293, base2 = 1337;
ll ht1[25], ht2[25];

int main()
{
	string s;
	vector <string> st;
	map <ll, int> pre;

	while (getline(cin, s))
	{
		st.push_back(s);

		int n = s.size();
		ll x = 0, y = 0;
		for (int i = 0; i < n; i++)
		{
			x = ((x * base1) + s[i]) % mod1;
			y = ((y * base2) + s[i]) % mod2;
			ll z = (x << 32) | y;
			pre[z]++;
		}
	}

	int n = st.size();
	for (int i = 0; i < n; i++)
	{
		string t = "";
		int m = st[i].size();
		ll x = 0, y = 0;
		for (int j = 0; j < m; j++)
		{
			t.push_back(st[i][j]);

			x = ((x * base1) + st[i][j]) % mod1;
			y = ((y * base2) + st[i][j]) % mod2;
			ll z = (x << 32) | y;

			if (pre[z] == 1) break;
		}

		cout << st[i] << ' ' << t << '\n';
	}

	return 0;
}