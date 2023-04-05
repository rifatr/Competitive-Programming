// Time: 2023-02-11 15:08:39 Problem: A. A Game with Grandma
// URL: https://algo.codemarshal.org/contests/icpc-dhaka-22-preli/problems/A

#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "Jhinuk\n"
#define no cout << "Grandma\n"
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

const int N = 110;
int n, dp[N][3], pos[N];
string s[3];

int rfs(int i, int f) {
	if(i >= n - 1) return f;
	auto &x = dp[i][f];
	if(~x) return x;
	
	x = f;
	if(!pos[i]) x = rfs(i + 1, f);
	else {
		if(!f) {
			x |= rfs(i + 2, 1 - f);
			x |= rfs(i + 3, 1 - f);
		}
		else {
			x &= rfs(i + 2, 1 - f);
			x &= rfs(i + 3, 1 - f);
		}
	}
	
	return x;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		cin >> n;
		lop(3) cin >> s[i];
		
		auto ck = [&] (int i, int j) {
			return s[i][j] == 'O' and s[i][j + 1] == 'O' and s[i + 1][j] == 'O' and s[i+1][j+1] == 'O';
		};
		
		lop(n - 1) {
			pos[i] = ck(0, i) | ck(1, i);
		}
		
		memset(dp, -1, sizeof dp);
		int ans = rfs(0, 0);
		Case(cs++);
		ans ? yes : no;
	}

	return 0;
}
