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

void solve() {
  int n; cin >> n;
  int a[n]; lop(n) cin >> a[i];
  sort(a, a + n);

  deque <int> ans(n);
  int k = 0;
  for (int j = 0; j < n; j += 2)
    ans[j] = a[k++];
  for (int j = 1; j < n; j += 2)
    ans[j] = a[k++];

  ans.pb(ans[0]); ans.push_front(ans[n - 1]);
  bool f = 1;
  for (int i = 1; i < n; i++) {
    if (ans[i] > ans[i + 1] and ans[i] > ans[i - 1]);
    else if (ans[i] < ans[i + 1] and ans[i] < ans[i - 1]);
    else f = 0;
  }

  if (f) {
    yes;
    loop(i, 1, n + 1) cout << ans[i] << ' ';
    cout << '\n';
    return;
  }

  ans.pop_back(), ans.pop_front();
  reverse(a, a + n);
  k = 0;
  for (int j = 0; j < n; j += 2)
    ans[j] = a[k++];
  for (int j = 1; j < n; j += 2)
    ans[j] = a[k++];

  ans.pb(ans[0]); ans.push_front(ans[n - 1]);
  f = 1;
  for (int i = 1; i < n; i++) {
    if (ans[i] > ans[i + 1] and ans[i] > ans[i - 1]);
    else if (ans[i] < ans[i + 1] and ans[i] < ans[i - 1]);
    else f = 0;
  }

  if (f) {
    yes;
    loop(i, 1, n + 1) cout << ans[i] << ' ';
    cout << '\n';
    return;
  }

  no;
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