/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
*/
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define powr(x,n,p) for(int axy=0 ; axy<p ; axy++){x=x*n;}
#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define yes cout<<"yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
#define no cout<<"no\n"
#define nl cout<<"\n"
#define fr0(n,q) for(q=0 ; q<n ; q++)
#define fr1(n,q) for(q=1 ; q<=n ; q++)
#define mp make_pair
#define scl(x) scanf("%lld",&x)
#define sci(x) scanf("%d",&x)
#define lst(x) x[x.size()-1]
#define llst(x) x[x.size()-2]
#define md 1000000007
#define check(x,y) (x&(1LL<<y))
#define set(x,y) x=(x|(1LL<<y))
#define off(x,y) x=(x&(~(1LL<<y)))
#define pi acos(-1)
#define inf (1LL<<50)
#define N  1000005
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi acos(-1)
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//s.find_by_order(2) -> element at index 2
//s.order_of_key(3) -> lower bound of 3

/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/


ll f1[N],f2[N],r1[N],r2[N],n,ans;

vector <ll> g[N];
string s;


void dfs(ll node,ll pre,ll pwr1,ll pwr2){
    ll b1=1009,b2=5701,m1=1024688864201,m2=68289980006401;

    ll val=s[node-1]+69;

    f1[node] = (((f1[pre]%m1)*b1)%m1 + val*b1)%m1;
    f2[node] = (((f2[pre]%m2)*b2)%m2 + val*b2)%m2;

    pwr1=((pwr1%m1)*(b1%m1))%m1;
    pwr2=((pwr2%m2)*(b2%m2))%m2;

    r1[node]= (val*pwr1)%m1;
    r2[node]= (val*pwr2)%m2;

    r1[node]= (r1[node]+r1[pre])%m1;
    r2[node]= (r2[node]+r2[pre])%m2;

    if(f1[node]==r1[node] && f2[node]==r2[node]){
        ans++;
    }

    for(auto to : g[node]){
        if(to==pre) continue;

        dfs(to,node,pwr1,pwr2);
    }

}


int main()
{


    fastio;

    int t,tc=1;
    cin>>t;


    while(t--){
        ll i,j;
        cin>>n>>s;

        for(i=0 ; i<=n ; i++){
            g[i].clear();
        }
        ans=0;

        for(i=1 ; i<n ; i++){
            ll u,v;
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }


        dfs(1,0,1,1);

        ll g=__gcd(ans,n);

        cout<<"Case "<<tc++<<": ";

        cout<<(ans/g)<<"/"<<(n/g);
        nl;





    }
    
    


    
    return 0;


}