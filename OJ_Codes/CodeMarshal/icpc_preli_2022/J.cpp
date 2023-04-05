// Time: 2023-02-11 15:55:50 Problem: J. Product Quality Analyst
// URL: https://algo.codemarshal.org/contests/icpc-dhaka-22-preli/problems/J

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

#ifdef rifa
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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
		ll n, k;
		cin >> n >> k;
		ll a[n], sum = 0;
		lop(n) cin >> a[i], sum += a[i];
		ll mx = *max_element(a, a + n);
		sum += mx * --k;
		Case(cs++);
		print(sum);
		
		// ll ans = 0;
		// lop(n - 1) {
			// if(a[i] <= a[i + 1]) {
				// ans += a[i];
				// continue;
			// }
// 			
			// ll j = i + 1, sum = a[i];
			// while(j < n and sum > a[j]) {
				// // sum += a[j];
				// j++;
			// }
// 			
			// if(j == n) {
				// ans += a[i] + abs(a[i + 1] - a[i]) * (k - 1);
			// }
			// else {
				// ans += sum;
				// // i = j - 1;
				// dbg2(sum, ans)
			// }
// 			
			// // dbg3(i, sum, ans)
		// }
// 		
		// ans += a[n - 1] * k;
		// Case(cs++);
		// print(ans);
	}

	return 0;
}
