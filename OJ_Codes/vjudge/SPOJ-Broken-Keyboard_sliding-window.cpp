// Problem: A - Broken Keyboard
// Contest: Virtual Judge - Daily Recap
// URL: https://vjudge.net/contest/471073#problem/A
// Time: 2021-11-29 15:42:40

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

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int k;
	while(cin >> k and k) {
		string s;
		cin.ignore();
		getline(cin, s);
		
		map <char, int> cnt;
		deque <char> dq;
		int ans = 0, i = 0, n = s.size();
		while(i < n) {
			dq.pb(s[i]);
			cnt[s[i]]++;
			if(cnt.size() == k) {
				ans = max(ans, (int)dq.size());
			}
			else if(cnt.size() > k) {
				cnt[dq[0]]--;
				if(!cnt[dq[0]]) cnt.erase(dq[0]);
				dq.pop_front();
			}
			
			i++;
		}
		
		if(!ans) ans = max(ans, (int)dq.size());
		
		print(ans);
	}

	return 0;
}