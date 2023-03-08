// Time: 2022-06-03 01:57:36    Problem: Tic Tac Toe Counting 
// URL: https://open.kattis.com/problems/tictactoecounting

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

int win[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
                 {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
                 {0, 4, 8}, {2, 4, 6}};
                 
int winner(string &s, char c) {
    int cnt = 0;
    lop(8) {
        cnt += s[win[i][0]] == c and s[win[i][1]] == c and s[win[i][2]] == c;
    }
    
    return cnt;
}

int check(string &s) {
    if(winner(s, 'X')) return 1;
    if(winner(s, 'O')) return 2;
    return 0;
}

map <string, int> dpx, dpy;
int rfsx(string s, int f) {
    if(dpx.count(s)) return dpx[s];
    int x = check(s);
    if(x) return x == 1;
    
    dpx[s] = x = 0;
    lop(9) {
        if(s[i] != '.') continue;
        
        s[i] = f ? 'O' : 'X';
        x += rfsx(s, !f);
        s[i] = '.';
    }
    
    return dpx[s] = x;
}
int rfsy(string s, int f) {
    if(dpy.count(s)) return dpy[s];
    int x = check(s);
    if(x) return x == 2;
    
    dpy[s] = x = 0;
    lop(9) {
        if(s[i] != '.') continue;
        
        s[i] = f ? 'O' : 'X';
        x += rfsy(s, !f);
        s[i] = '.';
    }
    
    return dpy[s] = x;
}

bool precheck(string &s, int x, int y) {
    bool isx = winner(s, 'X'), isO = winner(s, 'O');
    dbg2(isx, isO) dbg2(x, y)
    if(isx and isO) return 0;
    if(isx and x != y + 1) return 0;
    if(isO and x != y) return 0;
    
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--)
    {
        string s;
        cin >> s;
        
        int x = count(all(s), 'X'), y = count(all(s), 'O');
        if(x < y or x - y > 1 or !precheck(s, x, y)) {
            print(-1, -1);
            continue;
        }
        
        x = !(x == y);
        print(rfsx(s, x), rfsy(s, x));
    }

    return 0;
}