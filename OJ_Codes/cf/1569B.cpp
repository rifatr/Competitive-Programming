#include "bits/stdc++.h"

#define ll long long
#define pb push_back
#define ff first
#define ss second

#define yes cout << "YES\n"
#define no cout << "NO\n"
#define Case(i) cout << "Case " << int(i) << ": "

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

void solve() {
		int n;
		string s;
		cin >> n >> s;
		
		char grid[n][n];
		lop(n) lopj(n) grid[i][j] = 'X';
		
		for(int k = 0; k < n; k++) {
			if(s[k] == '1') {
				lop(n) {
					if(i != k) {
						if(grid[k][i] == 'X') {
							grid[k][i] = '=';
							grid[i][k] = '=';
						}
					}
				}
			}
		}
		
		for(int k = 0; k < n; k++) {
			if(s[k] == '2') {
				lop(n) {
					if(i != k and s[i] == '2' and grid[k][i] == 'X') {
						grid[k][i] = '+';
						grid[i][k] = '-';
						break;
					}
				}
			}
		}
		
		
		lop(n) {
			bool f = 0;
			lopj(n) {
				if(s[i] == '1' and grid[i][j] == '-') {
					no;
					return;
				}
				else if(s[i] == '2' and grid[i][j] == '+') f = 1;
			}
			if(s[i] == '2' and !f) {
				no;
				return;
			}
		}
		
		lop(n) {
			lopj(n) {
				if(i != j and grid[i][j] == 'X') grid[i][j] = '=';
			}
		}
		
		yes;
		lop(n) {
			lopj(n) cout << grid[i][j];
			cout << '\n';
		}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		solve();
	}

	return 0;
}
