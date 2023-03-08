// Problem: Lucky Number
// Contest: LightOJ
// URL: https://lightoj.com/problem/lucky-number
// Time: 2022-02-02 03:32:35

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

const int N = 1.5e6;
int bit[N + 20];
vin lucky;

void edit(int pos, int x) {
    while (pos < N) {
        bit[pos] += x;
        pos += pos & -pos;
    }
}

int sum(int pos) {
    int s = 0;
    while (pos) {
        s += bit[pos];
        pos -= pos & -pos;
    }

    return s;
}

void precal() {
	for(int i = 1; i < N; i++)
		edit(i, 1);
	
	int k = 0;
	for(int i = 2; i < N; i++) {
		if(sum(i) - sum(i - 1) == 0) continue;
		
		for(int j = ((N - k - 1) / i) * i; j >= i; j -= i) {
			
			int lo = 1, hi = N - 1, mid, pos = -1;
			while(lo <= hi) {
				mid = (lo + hi) / 2;
				int s = sum(mid);
				if(s >= j) {
					hi = mid - 1;
					pos = mid;
				}
				else lo = mid + 1;
			}
			
			if(pos == -1) continue;
			edit(pos, -1);
			k++;
		}
	}
	
	for(int i = 1; i < N; i++) {
		if(sum(i) - sum(i - 1) == 1)
			lucky.pb(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	precal();
	int tc, t = 1;
	cin >> tc;

	while (tc--)
	{
		int n;
		cin >> n;
		Case(t++);
		print(lucky[--n]);
	}

	return 0;
}
