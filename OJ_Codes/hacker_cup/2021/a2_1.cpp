#include "bits/stdc++.h"

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case #" << int(i) << ": "

#define lop(n) for (int i = 0; i < n; i++)
#define lopj(n) for (int j = 0; j < n; j++)

#define all(x) x.begin(), x.end()
#define sortd(x) sort(x.rbegin(), x.rend())
#define bitcount(x) __builtin_popcount(x)

#define vin vector <int>
#define vll vector <ll>
#define pll pair <ll, ll>
#define pii pair <int, int>
#define vpll vector <pll>

#ifndef ONLINE_JUDGE
#define dbg(x) cout << #x << " = " << x << endl;
#define dbg2(x, y) cout << #x << " = " << x << "\t", dbg(y);
#define dbg3(x, y, z) cout << #x << " = " << x << "\t", dbg2(y, z);
#define ddbg(x) cout << #x << " = [ "; for(auto z : x) cout << z << ' '; cout << "]\n";
#else
#define dbg(x)
#define adbg(x)
#define dbg2(x, y)
#define dbg3(x, y, z)
#define ddbg(x)
#endif

#define sob template < typename T
#define sb2 template < typename T, typename TT
sob > void print(T x) {std::cout << x << '\n';}
sb2 > void print(T x, TT y) {std::cout << x << ' ' << y << '\n';}
sb2 > void print(std::pair <T, TT> x) {std::cout << x.ff << ' ' << x.ss << '\n';}
sob > void print(std::vector <T> v) {for (auto z : v) std::cout << z << ' '; std::cout << '\n';}
sob > void print(T x[], int n) {for (int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ' : '\n');}

using namespace std;

const ll mod = 1e9 + 7, N = 1e6;
string s;
ll ind[N];

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, t = 1;
	cin >> tc;

	while (tc--)
	{
		Case(t++);

		ll n; cin >> n;
		cin >> s;
		int cc[3] = {0};
		lop(n) {
			if (s[i] == 'F') cc[0]++;
			else if (s[i] == 'X') cc[1]++;
			else cc[2]++;
		}

		if (!cc[1] or !cc[2]) {
			print(0);
			continue;
		}

		int i = 0;
		while (!s[i] == 'F') i++;
		for (int j = i - 1; j >= 0; j--)
			s[j] = s[i];

		ind[0] = 0;
		for (int i = 1; i < n; i++)
			ind[i] = s[i] != 'F' ? i : ind[i - 1];

		ll ans = 0;
		for (ll i = 1; i < n; i++) {
			if (s[i] == 'F' or s[i] == s[ind[i - 1]]) continue;

			ll z = ((ind[i - 1] + 1) * (n - i)) % mod;
			ans = (ans + z) % mod;
		}

		print(ans);
	}

	return 0;
}