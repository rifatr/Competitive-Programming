#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define nn '\n'
#define ff first
#define ss second
#define fo(i,n) for(i=0;i<n;i++)
#define Fo(i,k,n) for(i=k;k<n?i<n:i>n;k<n?i+=1:i-=1)
#define deb(x) cerr << #x << "=" << x << endl
#define deb2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Setpre(n) cout<<fixed<<setprecision(n)
#define all(x) x.begin(), x.end()
#define rev(x) reverse(all(x))
#define sortall(x) sort(all(x))
#define UNIQUE(a) (a).erase(unique(all(a)),(a).end())
#define SZ(a) (int)a.size()
#define mem(a,b) memset(a,b,sizeof(a))
#define itr(it, a) for(auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define fast_IO ios_base::sync_with_stdio(0), cin.tie(0)
#define Set(x, k) (x |= (1LL << k))
#define Unset(x, k) (x &= ~(1LL << k))
#define Check(x, k) (x & (1LL << k))
#define Toggle(x, k) (x ^ (1LL << k))
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int>  pii;
typedef pair<ll, ll>    pll;
typedef vector<int>     vi;
typedef vector<ll>      vl;
typedef vector<pii>     vpii;
typedef vector<pll>     vpll;
typedef vector<vi>      vvi;
typedef vector<vl>      vvl;
template <typename T> void display (T const& coll){typename T::const_iterator pos;typename T::const_iterator end(coll.end());for(pos=coll.begin(); pos!=end; ++pos) cout << *pos << ' ';cout << endl;}
template <typename T> using PQ = priority_queue<T>;
template <typename T> using QP = priority_queue<T,vector<T>,greater<T>>;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> using ordered_multiset = tree<T, null_type,less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
template <typename T,typename R> using ordered_map = tree<T, R , less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T,typename R> using ordered_multimap = tree<T, R , less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T> T BigMod (T b, T p, T m) {if (p == 0) return 1; if (p % 2 == 0) {T s = BigMod(b, p / 2, m); return ((s % m) * (s % m)) % m;} return ((b % m) * (BigMod(b, p - 1, m) % m)) % m;}
template <typename T> T ModInv (T b, T m) {return BigMod(b, m - 2, m);}
template <typename T> T euclide(T a, T b, T &x, T &y) {if (a < 0) {T d = euclide(-a, b, x, y); x = -x; return d;}   if (b < 0) {T d = euclide(a, -b, x, y); y = -y; return d;}   if (b == 0) {x = 1; y = 0; return a;} else {T d = euclide(b, a % b, x, y); T t = x; x = y; y = t - (a / b) * y; return d;}}
inline void swap(ll &x, ll &y) {ll temp = x; x = y; y = temp;}
inline ll GCD(ll a, ll b) { return b == 0 ? a : GCD(b, a % b); }
inline ll LCM(ll a, ll b) { return a * b / GCD(a, b); }
inline ll Ceil(ll p, ll q)  {return p < 0 ? p / q : p / q + !!(p % q);}
inline ll Floor(ll p, ll q) {return p > 0 ? p / q : p / q - !!(p % q);}
inline double logb(ll base,ll num){ return (double)log(num)/(double)log(base);}
inline bool isPerfectSquare(long double x){ if (x >= 0) { long long sr = sqrt(x);return (sr * sr == x); }return false; }
double euclidean_distance(ll x1,ll y1,ll x2,ll y2){double a=(x2-x1)*(x2-x1);double b=(y2-y1)*(y2-y1);double c=(double)sqrt(a+b);return c;}
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) {
	return uniform_int_distribution<int>(l, r) (rng);
}

namespace io{
	template<typename First, typename Second> ostream& operator << ( ostream &os, const pair<First, Second> &p ) { return os << p.first << " " << p.second; }
	template<typename First, typename Second> ostream& operator << ( ostream &os, const map<First, Second> &mp ) { for( auto it : mp ) { os << it << endl;  } return os; }
	template<typename First> ostream& operator << ( ostream &os, const vector<First> &v ) { bool space = false; for( First x : v ) { if( space ) os << " "; space = true; os << x; } return os; }
	template<typename First> ostream& operator << ( ostream &os, const set<First> &st ) { bool space = false; for( First x : st ) { if( space ) os << " "; space = true; os << x; } return os; }
	template<typename First> ostream& operator << ( ostream &os, const multiset<First> &st ) { bool space = false; for( First x : st ) { if( space ) os << " "; space = true; os << x; } return os; }
 
	template<typename First, typename Second> istream& operator >> ( istream &is, pair<First, Second> &p ) { return is >> p.first >> p.second; }
	template<typename First> istream& operator >> ( istream &is, vector<First> &v ) { for( First &x : v ) { is >> x; } return is; }
	
	long long fastread(){ char c; long long d = 1, x = 0; do c = getchar(); while( c == ' ' || c == '\n' ); if( c == '-' ) c = getchar(), d = -1; while( isdigit( c ) ){ x = x * 10 + c - '0'; c = getchar(); } return d * x; }
	
	static bool sep = false;
 
	using std::to_string;
 
	string to_string( bool x ){ return ( x ? "true" : "false" ); }
	string to_string( const string & s ){ return "\"" + s + "\""; }
	string to_string( const char * s ){ return "\"" + string( s ) + "\""; }
	string to_string ( const char & c ) { string s; s += c; return "\'" + s + "\'"; }
 
	template<typename Type> string to_string( vector<Type> );
	template<typename First, typename Second> string to_string( pair<First, Second> );
	template<typename Collection> string to_string( Collection );
 
	template<typename First, typename Second> string to_string( pair<First, Second> p ){ return "{" + to_string( p.first ) + ", " + to_string( p.second ) + "}"; }
	template<typename Type> string to_string( vector<Type> v ) { bool sep = false; string s = "["; for( Type x: v ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "]"; return s; }
	template<typename Collection> string to_string( Collection collection ) { bool sep = false; string s = "{"; for( auto x: collection ){ if( sep ) s += ", "; sep = true; s += to_string( x ); } s += "}"; return s; }
 
	void print() { cerr << endl; sep = false; }
	template <typename First, typename... Other> void print( First first, Other... other ) { if( sep ) cerr << " | "; sep = true; cerr << to_string( first ); print( other... ); }
	
} using namespace io;

struct custom_hash {
	static uint64_t splitmix64(uint64_t x) {
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}
	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

const double EPS = 1e-9;
const int N = 1e7+10;
const int M = 1e9+7;

/*===================================================================//
				███╗   ██╗ █████╗ ███████╗██╗███████╗
				████╗  ██║██╔══██╗██╔════╝██║██╔════╝
				██╔██╗ ██║███████║█████╗  ██║███████╗
				██║╚██╗██║██╔══██║██╔══╝  ██║╚════██║
				██║ ╚████║██║  ██║██║     ██║███████║
				╚═╝  ╚═══╝╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝
//====================================================================*/


// ll a[N];
// vl g[N];
ll T=0;

vector<ll> smallest_factor;
vector<bool> prime;
vector<ll> primes;
 
void sieve(ll maximum) {
	maximum = max(maximum, 2LL);
	smallest_factor.assign(maximum + 1, 0);
	prime.assign(maximum + 1, true);
	prime[0] = prime[1] = false;
	primes = {2};
 
	for (int p = 2; p <= maximum; p += 2) {
		prime[p] = p == 2;
		smallest_factor[p] = 2;
	}
 
	for (int p = 3; p * p <= maximum; p += 2)
		if (prime[p])
			for (int i = p * p; i <= maximum; i += 2 * p)
				if (prime[i]) {
					prime[i] = false;
					smallest_factor[i] = p;
				}
 
	for (int p = 3; p <= maximum; p += 2)
		if (prime[p]) {
			smallest_factor[p] = p;
			primes.push_back(p);
		}
}

vl primeFactor(ll n){
	vl res;
	while(n>1){
		ll a=smallest_factor[n];
		res.pb(a);
		while(n%a==0) n/=a;
	}
	return res;
}

#define uumap unordered_map

uumap <ll, ll> pff(ll n) {
	uumap <ll, ll> res;
	while(n > 1) {
		ll a = smallest_factor[n];
		while(n % a == 0) {
			n /= a;
			res[a]++;
		}
	}
	return res;
}

void solve() {
	ll n=0,a=0,b=0,i=0,j=0,k=0,l=0,r=0,ans=0,temp=0,cnt=0,sum=0;
	string s,s1,s2,s3;
	cin>>n;
	vl v(n),vv(n);
	cin>>v>>vv;
	bool alice=1,bob=1;
	set<ll> sv,svv;
	fo(i,n){
		vl tempo=primeFactor(v[i]);
		for(auto &it:tempo) sv.insert(it);
		tempo=primeFactor(vv[i]);
		for(auto &it:tempo) svv.insert(it);
	}

	for(auto it:svv){
		if(!sv.count(it)){
			alice=0;
			break;
		}
	}
	set<pll> st;
	auto vag=[](ll a,ll b){
		ll g=__gcd(a,b);
		a/=g;
		b/=g;
		pll res=make_pair(a,b);
		return res;
	};
	// pll now=vag(v[0],vv[0]);
	
	auto af = pff(v[0]), bf = pff(vv[0]);
	ll gun = 1, vaag = 1;
	for(auto &x : af) {
		ll y = x.ff;
		while(af[y] != bf[y]) {
			if(af[y] > bf[y]) {
				vaag *= x.ff;
				af[y]--;
			}
			else {
				gun *= x.ff;
				af[y]++;
			}
		}
	}
	for(auto &x : bf) {
		ll y = x.ff;
		while(af[y] != bf[y]) {
			if(af[y] > bf[y]) {
				vaag *= x.ff;
				af[y]--;
			}
			else {
				gun *= x.ff;
				af[y]++;
			}
		}
	}
	
	auto guf = primeFactor(gun);
	// dbg2(gun, vaag) dbg(guf)

	fo(i,n){
		if(v[i] % vaag) {
			bob = 0;
			break;
		}
		for(auto &x : guf) {
			if(v[i] % x) {
				bob = 0;
				break;
			}
		}
		if(!bob) break;
		v[i] *= gun;
		v[i] /= vaag;

		if(v[i] != vv[i]) {
			bob = 0;
			break;
		}
	}
	cout<<"Case "<<++T<<": "<<(alice?"Yes":"No")<<" "<<(bob?"Yes":"No")<<nn;
}

int main() {
	fast_IO;
	
	// #ifndef ONLINE_JUDGE
	//     freopen("input.txt","r",stdin);
	//     freopen("output.txt","w",stdout);
	// #endif
	sieve(N);
	int t = 1;
	cin >> t;
	while(t--) {
		
		solve();
	}

	return 0;
}