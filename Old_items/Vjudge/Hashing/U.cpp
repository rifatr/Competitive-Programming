#include<iostream>
#include<set>
#include<cstring>
#include<cstdlib>
#include <cstdio>
#include<algorithm>
#include<vector>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 123, base = 1e9 + 7;

ll Hash(string const &s)
{
	ll n = (ll) s.size(), x = 0LL;

	for (ll i = 0; i < n; i++)
		x = ((x * base) + s[i]) % mod;

	return x;
}

bool prefix(string const &s, string const &t)
{
	if (t.size() < s.size())
		return 0;

	ll y = Hash(s);
	ll n = (ll) t.size(), x = 0LL;
	for (ll i = 0; i < n; i++)
	{
		x = ((x * base) + t[i]) % mod;

		if (x == y)
			return 1;
	}

	return 0;
}

vector <string> num, res;

int main()
{
	freopen("/home/rifat/input.txt", "r", stdin);

	int n;
	string s;

	while (getline(cin, s))
	{
		num.push_back(s);

		while (getline(cin, s))
		{
			if (s[0] == '9')
				break;

			num.push_back(s);
		}

		sort(num.begin(), num.end());
		int n = num.size();

		string ans = "immediately decodable";
		for (int i = 0; i < n - 1; i++)
		{
			if (prefix(num[i], num[i + 1]))
			{
				ans = "not immediately decodable";
				break;
			}
		}

		res.push_back(ans);
		num.clear();
	}

	n = res.size();
	for (int i = 0; i < n; i++)
	{
		cout << "Set " << i + 1 << " is ";
		cout << res[i] << '\n';
	}

	return 0;
}
