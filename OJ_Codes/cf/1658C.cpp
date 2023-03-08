#include <bits/stdc++.h>

#define ll 			long long
#define pb 			push_back
#define ff 			first
#define ss 			second

#define yes 		cout << "YES\n"
#define no 			cout << "NO\n"
#define Case(i) 	cout << "Case " << int(i) << ": "

#define lop(n) 		for (int i = 0; i < n; i++)
#define lopj(n) 	for (int j = 0; j < n; j++)

#define all(x) 		x.begin(), x.end()
#define sortd(x) 	sort(x.rbegin(), x.rend())
#define bitcount(x) __builtin_popcount(x)

#define vin 		vector <int>
#define vll 		vector <ll>
#define pll 		pair <ll, ll>
#define pii 		pair <int, int>
#define vpll 		vector <pll>

#ifndef ONLINE_JUDGE
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

#define Y "YES"
#define N "NO"

string solve() {
	int n;
	cin >> n;
	int a[n];
	lop(n) cin >> a[i];
	if (n == 1) return Y;

	//next element check
	lop(n - 1) {
		if (a[i] == 1) {
			if (a[i + 1] != 2) return N;
		}
		else if (a[i] == n) {
			if (a[i + 1] != 1) return N;
		}
		else {
			if (a[i + 1] > a[i] + 1) return N;
		}
	}
	if (a[0] > a[n - 1] + 1) return N;

	//element count check
	int cnt[n + 2] = {0};
	lop(n) cnt[a[i]]++;
	if (cnt[1] != 1) return N;
	if (!cnt[2]) return N;
	for (int i = 3, j = n - 2; i <= n; i++, j--) {
		if (cnt[i] > j) return N;
	}


	return Y;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		cout << solve() << '\n';
	}

	return 0;
}
