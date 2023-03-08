#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define loop(j, a, b) for(int j = a; j < b; j++)
#define yes cout << "Yes\n"
#define no cout << "No\n"

const int N = 2e5 + 5;
ll a[N], cnt[N];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll n, w;
	cin >> n >> w;

	lop(n)
	{
		int s, e, p;
		cin >> s >> e >> p;
		cnt[s] += p;
		cnt[e] -= p;
	}

	if (cnt[0] > w)
	{
		no;
		return 0;
	}
	loop(i, 1, N)
	{
		cnt[i] += cnt[i - 1];
		if (cnt[i] > w)
		{
			no;
			return 0;
		}
	}

	yes;
	return 0;
}
