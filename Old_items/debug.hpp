// #include <bits/stdc++.h>
using namespace std;

#define dbg(x) cout << #x << " = "; debug(x); cout << '\n';
#define dbg2(x, y) cout << #x << " = "; debug(x); cout << "\t"; dbg(y);
#define dbg3(x, y, z) cout << #x << " = "; debug(x); cout << "\t"; dbg2(y, z);
#define ddbg(x) cout << #x << " = [ "; for(auto z : x) debug(z); cout << "]\n";


#define sob template < typename T
#define sb2 template < typename T, typename TT

sob > void debug(T x) {cout << x << ' ';}
// sb2 > void debug(T x, TT y) {cout << x << ' ' << y << ' ';}

sob > void debug(vector <T> v) {cout << "[ "; for (T z : v) debug(z); cout << "]";}
sob > void debug(deque <T> v) {cout << "[ "; for (T z : v) debug(z); cout << "]";}
sob > void debug(set <T> v) {cout << "[ "; for (T z : v) debug(z); cout << "]";}
sob > void debug(multiset <T> v) {cout << "[ "; for (T z : v) debug(z); cout << "]";}

sb2 > void debug(pair <T, TT> x) {cout << "{ " << x.first << ' ' << x.second << " } ";}

sb2 > void debug(map <T, TT> v) {cout << "[ "; for (auto z : v) debug(z); cout << "]";}
sb2 > void debug(map <T, vector<TT>> v) {cout << "\n"; for (auto z : v) cout << "\t" << z.first << " -> ", debug(z.second), cout << '\n';}
sb2 > void debug(map <T, deque<TT>> v) {cout << "\n"; for (auto z : v) cout << "\t" << z.first << " -> ", debug(z.second), cout << '\n';}
sb2 > void debug(map <T, set<TT>> v) {cout << "\n"; for (auto z : v) cout << "\t" << z.first << " -> ", debug(z.second), cout << '\n';}
sb2 > void debug(map <T, multiset<TT>> v) {cout << "\n"; for (auto z : v) cout << "\t" << z.first << " -> ", debug(z.second), cout << '\n';}

sb2 > void debug(multimap <T, TT> v) {cout << "[ "; for (auto z : v) debug(z); cout << "]";}
sb2 > void debug(multimap <T, vector<TT>> v) {cout << "\n"; for (auto z : v) cout << "\t" << z.first << " -> ", debug(z.second), cout << '\n';}
sb2 > void debug(multimap <T, deque<TT>> v) {cout << "\n"; for (auto z : v) cout << "\t" << z.first << " -> ", debug(z.second), cout << '\n';}
sb2 > void debug(multimap <T, set<TT>> v) {cout << "\n"; for (auto z : v) cout << "\t" << z.first << " -> ", debug(z.second), cout << '\n';}
sb2 > void debug(multimap <T, multiset<TT>> v) {cout << "\n"; for (auto z : v) cout << "\t" << z.first << " -> ", debug(z.second), cout << '\n';}
// sob > void debug(T x[], int n) {for (int i = 0; i++ < n;) cout << *x++ << (i < n ? ' ' : '\n');}