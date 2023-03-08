#include<bits/stdc++.h>

#define ll              long long
#define pb              push_back
#define ff              first
#define ss              second
#define mp              make_pair

#define scan(a)         scanf("%d", &a)
#define scanl(a)        scanf("%lld", &a)
#define scand(a)        scanf("%lf", &a)
#define scan2(a, b)     scanf("%d %d", &a, &b)
#define scanl2(a, b)    scanf("%lld %lld", &a, &b)
#define scand2(a, b)    scanf("%lf %lf", &a, &b)

#define yes             cout << "yes\n"
#define no              cout << "no\n"
#define Case(i)         cout << "Case " << int(i) << ": "

#define lop(n)          for(int i = 0; i < n; i++)
#define lopj(n)         for(int j = 0; j < n; j++)
#define loop(k, a, b)   for(int k = a; k < b; k++)
#define loopr(j, b, a)  for(int j = b; j >= a; j--)
#define lopc(i, a, b, c) for(int i = a; i < b; i += c)

#define all(x)          x.begin(), x.end()
#define sorta(x)        sort(x.begin(), x.end())
#define sortd(x)        sort(x.rbegin(), x.rend())
#define mem0(a)         memset(a, 0, sizeof(a))
#define mem1(a)         memset(a, -1, sizeof(a))

#define vin             vector <int>
#define vll             vector <ll>
#define vst             vector <string>
#define pll             pair <ll, ll>
#define pss             pair <string, string>
#define vpll            vector <pll>

#define fread           freopen("input.txt", "r", stdin)
#define fwrite          freopen("output.txt", "w", stdout)
#define fastio          ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

#define mod             (const int) 1e9+7
#define PI              acos(-1.0)
#define inf             (1LL << 61)

using namespace std;

const ll N = 1e10;
string s = "110", s1 = "10", s2 = "11", s3 = "01";

ll solve()
{
	ll n;
	string t;

	cin >> n >> t;

	if (n == 1)
	{
		if (t[0] == '1')
			return 2 * N;

		return N;
	}

	if (n == 2)
	{
		if (t == s1 or t == s2)
			return N;
		if (t == s3)
			return N - 1;

		return 0;
	}

	lop(n - 1)
	{
		if (t[i] == '0' and t[i + 1] == '0')
			return 0;
		if (i and t[i] == '1' and t[i - 1] == '1' and t[i + 1] == '1')
			return 0;
		if (i and t[i] == '1' and t[i - 1] == '0' and t[i + 1] == '0')
			return 0;
	}

	// ll zr = 0;
	// lop(n) zr += t[i] == '0';

	// if (t[n - 1] == '0')
	// 	zr--;
	// return N - zr;

	string tt = t.substr(n - 3, 3);

	ll z = 0;
	if (t[0] == '1' and t[1] == '0')
		z = 1;
	else if (t[0] == '0')
		z = 2;
	ll zz = 0;

	if (tt == s)
		return N - ((n + z - 1) / 3);

	return N - ((n + z) / 3);
}

int main()
{
	fastio;

	cout << solve() << '\n';

	return 0;
}

// 11011011