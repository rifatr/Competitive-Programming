#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case #" << int(i) << ": "

#define lop(n) for (int i = 0; i < n; i++)
#define lopj(n) for (int j = 0; j < n; j++)
#define loop(i, a, b) for (int i = a; i < b; i++)

#define all(x) x.begin(), x.end()
#define sortd(x) sort(x.rbegin(), x.rend())

#define vin vector <int>
#define vll vector <ll>
#define pll pair <ll, ll>
#define pii pair <int, int>
#define vpll vector <pll>

#ifndef rifat
#include <debug.hpp>
#else
#define dbg(x)
#define ddbg(x)
#define dbg2(x, y)
#define dbg3(x, y, z)
#endif

#define sob template < typename T
#define sb2 template < typename T, typename TT
sob > void print(T x) {std::cout << x << '\n';}
sb2 > void print(T x, TT y) {std::cout << x << ' ' << y << '\n';}
sb2 > void print(std::pair <T, TT> x) {std::cout << x.ff << ' ' << x.ss << '\n';}
sob > void print(std::vector <T> v) {for (auto z : v) std::cout << z << ' '; std::cout << '\n';}
sob > void print(T x[], int n) {for (int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ' : '\n');}

using namespace std;

const ll N = 5e5 + 10, mod = 1e9 + 7;

ll a[2][N], b[2][N];

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		Case(cs++);

		ll n; cin >> n;
		lop(n) {
			int x, y; cin >> a[0][i] >> a[1][i];
		}

		ll q; cin >> q;
		lop(q) {
			int x, y; cin >> b[0][i] >> b[1][i];
		}

		ll sum = 0;
		auto cal = [&] (int k) {
			ll asum, a2sum, bsum, b2sum;
			asum = a2sum = bsum = b2sum = 0;

			lop(n) {
				asum += a[k][i];
				a2sum += a[k][i] * a[k][i];
				asum %= mod;
				a2sum %= mod;
			}
			lop(q) {
				bsum += b[k][i];
				b2sum += b[k][i] * b[k][i];
				bsum %= mod;
				b2sum %= mod;
			}

			ll x = (q * a2sum) % mod;
			ll y = (n * b2sum) % mod;
			ll z = (2 * asum * bsum) % mod;
			sum = (sum + x + y - z + mod) % mod;
			if (sum < 0) sum += mod;
		};

		cal(0), cal(1);
		print(sum);
	}

	return 0;
}