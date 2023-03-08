// Problem: F. Find the Substrings	Time: 2022-03-29 23:52:34 
// URL: https://algo.codemarshal.org/contests/icpc-dhaka-preli-18/problems/F

#include <bits/stdc++.h>

#define ll 			long long
#define pb 			push_back
#define ff 			first
#define ss 			second

#define yes 		cout << "YES\n"
#define no 			cout << "NO\n"
#define Case(i) 	cout << "Case " << int(i) << ":\n"

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

#define sob template < typename T
#define sb2 template < typename T, typename TT
sob > void print(T x) {std::cout << x << '\n';}
sb2 > void print(T x, TT y) {std::cout << x << ' ' << y << '\n';}
sb2 > void print(std::pair <T, TT> x) {std::cout << x.ff << ' ' << x.ss << '\n';}
sob > void print(std::vector <T> v) {for (auto z : v) std::cout << z << ' '; std::cout << '\n';}
sob > void print(T x[], int n) {for (int i = 0; i++ < n;) std::cout << *x++ << (i < n ? ' ' : '\n');}

using namespace std;

const ll N = 1e6 + 10, mod = 1e9+7;
ll n, q, allsub[N], unqsub[N];
string s;
int SA[N], LCP[N]; //suffix array, longest common prefix
int RA[N], tempRA[N]; //rank array, temporary rank array
int tempSA[N]; //temoporary suffix array
int c[N];
int Phi[N], PLCP[N];
// second approach: O(n log n)
// the input string, up to 100K characters
// the length of input string
// rank array and temporary rank array
// suffix array and temporary suffix array
// for counting/radix sort
void countingSort(int k) {    // O(n)
    int i, sum, maxi = max(300ll, n);
    // up to 255 ASCII chars or length of n
    memset(c, 0, sizeof c);
    // clear frequency table
    for (i = 0; i < n; i++)
        // count the frequency of each integer rank
        c[i + k < n ? RA[i + k] : 0]++;
    for (i = sum = 0; i < maxi; i++) {
        int t = c[i]; c[i] = sum; sum += t;
    }
    for (i = 0; i < n; i++)
        // shuffle the suffix array if necessary
        tempSA[c[SA[i] + k < n ? RA[SA[i] + k] : 0]++] = SA[i];

    for (i = 0; i < n; i++)
        // update the suffix array SA
        SA[i] = tempSA[i];
}

void buildSA() {
    int i, k, r;
    for (i = 0; i < n; i++) RA[i] = s[i];
    // initial rankings
    for (i = 0; i < n; i++) SA[i] = i;
    // initial SA: {0, 1, 2, ..., n-1}
    for (k = 1; k < n; k <<= 1) {
        // repeat sorting process log n times
        countingSort(k); // actually radix sort: sort based on the second item
        countingSort(0);
        // then (stable) sort based on the first item
        tempRA[SA[0]] = r = 0;
        // re-ranking; start from rank r = 0
        for (i = 1; i < n; i++)
            // compare adjacent suffixes
            tempRA[SA[i]] = // if same pair => same rank r; otherwise, increase r
                (RA[SA[i]] == RA[SA[i - 1]] && RA[SA[i] + k] == RA[SA[i - 1] + k]) ? r : ++r;
        for (i = 0; i < n; i++)
            // update the rank array RA
            RA[i] = tempRA[i];

        if (RA[SA[n - 1]] == n - 1) break;
        // nice optimization trick
    }
}

void buildLCP() {
    int i, L;
    Phi[SA[0]] = -1;
    // default value
    for (i = 1; i < n; i++)
        // compute Phi in O(n)
        Phi[SA[i]] = SA[i - 1];
    // remember which suffix is behind this suffix
    for (i = L = 0; i < n; i++) {
        // compute Permuted LCP in O(n)
        if (Phi[i] == -1) { PLCP[i] = 0; continue; }
        // special case
        while (s[i + L] == s[Phi[i] + L]) L++;
        // L increased max n times
        PLCP[i] = L;
        L = max(L - 1, 0);
        // L decreased max n times
    }
    for (i = 0; i < n; i++)
        // compute LCP in O(n)
        LCP[i] = PLCP[SA[i]];
    // put the permuted LCP to the correct position
}
// n = string length + 1
// s = the string
// memset(LCP, 0, sizeof(LCP));  setting all index of LCP to zero
// buildSA(); for building suffix array
// buildLCP(); for building LCP array
// LCP is the longest common prefix with the previous suffix here
// SA[0] holds the empty suffix "\0".

void precal() {
    allsub[1] = 26;
    for(ll i = 2; i <= n; i++) {
        allsub[i] = (allsub[i - 1] * 26) % mod; //all possible substring of size i
    }
    
    memset(LCP, 0, sizeof(LCP));
    buildSA();
    buildLCP();
    
    memset(unqsub, 0, sizeof(unqsub));
    for(int i = 0; i < n; i++) {
        int subs = n - SA[i]; // total substring of length 1 to n - SA[i]
        unqsub[LCP[i] + 1]++; // substring upto size LCA[i] exists
        unqsub[subs + 1]--;
    }
    for(int i = 1; i <= n; i++) {
        unqsub[i] = (unqsub[i] + unqsub[i - 1]) % mod;
        allsub[i] = (allsub[i] - unqsub[i] + mod) % mod;
        allsub[i] = (allsub[i] + allsub[i - 1]) % mod;
    }
}

void solve() {
    cin >> s >> q;
    n = s.size();
    
    precal();
    
    while(q--) {
        int l, r;
        cin >> l >> r;
        
        print((allsub[r] - allsub[l - 1] + mod) % mod);
    }
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc, cs = 1;
	cin >> tc;

	while (tc--)
	{
	    Case(cs++);
		solve();
	}

	return 0;
}