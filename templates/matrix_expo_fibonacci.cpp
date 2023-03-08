// Time: 2022-04-23 01:48:13	Problem: A - Fibonacci
// URL: https://vjudge.net/contest/490393#problem/A

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case " << int(i) << ": "

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

#ifdef rifat
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

const ll N = 2, mod = 1000000007;

struct matrix {
	ll mat[N][N];

	matrix(int a, int b, int c, int d) {
		mat[0][0] = a;
		mat[0][1] = b;
		mat[1][0] = c;
		mat[1][1] = d;
	}

	matrix operator * (const matrix &another) {
		matrix res(0, 0, 0, 0);

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					res.mat[i][j] = (res.mat[i][j] + mat[i][k] * another.mat[k][j]);
					if (res.mat[i][j] > 8 * mod * mod) res.mat[i][j] -= 8 * mod * mod; // to reduce mod operation, 8*mod*mod
				}

				res.mat[i][j] %= mod;
			}
		// res.mat[i][j] = (res.mat[i][j] + mat[i][k] * another.mat[k][j]) % mod;
		return res;
	}
};

matrix expo(matrix a, ll n) {
	if (n == 1) return a;

	matrix ret = expo(a, n / 2);
	ret = ret * ret;
	if (n & 1) ret = ret * a;

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc = 1;
	// cin >> tc;

	while (tc--)
	{
		ll a = 0, b = 1, n; // f[0] = a, f[1] = b, f[n] = f[n - 1] + f[n - 2]
		cin >> n;

		if (n <= 1) {
			cout << (n ? b : a) << '\n';
			continue;
		}

		matrix res(1, 1, 1, 0);
		res = expo(res, n - 1);
		ll ans = res.mat[0][0] * b + res.mat[0][1] * a;
		cout << ans % mod << '\n';
	}

	return 0;
}
