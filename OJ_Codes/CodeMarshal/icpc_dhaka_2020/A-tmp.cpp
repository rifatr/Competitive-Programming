#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define vi vector<ll>
#define pb push_back
#define ff first
#define ss second
#define inf 2e18
#define ull unsigned long long
#define pi acos(-1.0)
#define mod 1000000007
#define lop0(n) for(ll i=0;i<n;i++)
#define lop(j,n) for(ll j=0;j<n;j++)
#define lop1(i,n) for(ll i=1;i<=n;i++)
#define all(v) v.begin(),v.end()
#define el '\n'
ll Set(ll N,ll pos)
{
    return N=N | (1LL<<pos);
}
ll reset(ll N,ll pos)
{
    return N= N & ~(1LL<<pos);
}
bool check(ll N,ll pos)
{
    return (bool)(N & (1LL<<pos));
}
ll dx[] = { 1,0,-1,0 };
ll dy[] = { 0,1,0,-1 };
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const ll N=50005+100;
ll v[N],tree[4*N];
void build(ll u,ll b,ll e)
{
    if(b==e)
    {
        tree[u]=v[b];
        return;
    }
    ll mid=(b+e)/2;
    build(2*u,b,mid);
    build(2*u+1,mid+1,e);
    tree[u]=min(tree[2*u],tree[2*u+1]);
}
ll query(ll u,ll b,ll e,ll i,ll j)
{
    if(i>e or j<b)
        return inf;
    if(b>=i and e<=j)
        return tree[u];
    ll mid=(b+e)/2;
    ll l=query(2*u,b,mid,i,j);
    ll r=query(2*u+1,mid+1,e,i,j);
    return min(l,r);
}
bool cmp(pair<ll,pair<ll,ll>>a,pair<ll,pair<ll,ll>>b)
{
    if(a.ff==b.ff)
        return a.ss.ff<b.ss.ff;
    return a.ff<b.ff;
}
signed main()
{
    ll t=1,cs=1;
    cin>>t;
    while(t--)
    {
        ll n,m;
        cin>>n>>m;
        vector<pair<ll,pair<ll,ll>>>vp;
        lop0(n)
        {
            ll pz,l,r;
            cin>>pz>>l>>r;
            vp.pb({l,{r,pz}});
        }
        sort(all(vp),cmp);
        lop1(i,m) cin>>v[i];
        lop0(4*m+5) tree[i]=0;
        build(1,1,m);
        ll ans = 0, pre = -1;
        lop0(n)
        {
            ll lo=vp[i].ff,hi=vp[i].ss.ff;
            //cout<<lo<< " "<<hi<<el;
            ll cost=query(1,1,m,lo,hi);
            //cout<<cost<<el;
            ll ind;
            while(lo<=hi)
            {
                ll mid=(lo+hi)/2;
                if(query(1,1,m,lo,mid)==cost)
                {
                    ind=mid;
                    hi=mid-1;
                }
                else lo=mid+1;
            }
           // cout<<ind<<el;
            if(pre = -1 or pre < vp[i].ff)
            {
                pre = ind;
                // vis[pre] = 1;
                ans += vp[i].ss.ss - v[pre];
            }
            else
            {
                ans += vp[i].ss.ss;
            }
        }
        // lop0(vp.size())
        // {
        // cout<<vp[i].ff<<" "<<vp[i].ss.ff<<el;
        // }
//        ll ans=0;
//        vi vis(n+5);
//        ll pre=-1;
//        lop0(vp.size())
//        {
//            if(vp[i].ff>pre or vp[i].ss.ff<pre)
//            {
//                ll mn=inf,id;
//                // cout<<i<<el;
//                for(ll j=vp[i].ff; j<=vp[i].ss.ff; j++)
//                {
//                    if(v[j]<mn)
//                    {
//                        mn=v[j];
//                        id=j;
//                    }
//                }
//                pre=id;
//                ans-=mn;
//            }
//            ans+=vp[i].ss.ss;
//        }


//
        cout<<"Case "<<cs++<<": ";
        cout<<ans<<el;
    }
}
