#include<bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
#define __ ios_base::sync_with_stdio(false); cin.tie(NULL);

void vin(vector<ll> &v) {for (auto &it : v) cin>> it , it--;}
const ll N = 1e5 + 7 ;


map<ll,vector<pair<ll,ll>>>tun ;
map<ll,ll>mp ,ans ;
ll c[10] ;

ll dx[] = {-1,-1,-1,0,0,1,1,1} ;
ll dy[] = {-1,0,1,-1,1,-1,0,1} ;
const ll M = 1e7 ;
ll fun(ll x , ll y) {
    return ( (x * M) + y) ;
}

pair<ll,ll> get(ll x) {
    return {(x/M),x%M} ;
}
ll n , m ;
void dij(ll nn) {
    ans[nn] = 0 ;
    set<pair<ll,ll>> q ;
    q.insert({0,nn}) ;

    while(!q.empty()) {

        auto f  = *q.begin() ;
        ll w , now , x, y ;
        tie(w,now) = f ;
        q.erase(q.begin()) ;
        if (w > ans[now]) continue ;
        tie(x,y) = get(now) ;
     //   cout << endl << endl << x << ' ' << y << endl ;

        for (auto it : tun[now]) {
            ll de , co ;
            tie(de,co) = it ;
         //   cout << co << endl << endl ;
            if (ans[de] > ans[now] + co) {
                q.erase({ans[de],de}) ;
                ans[de] = ans[now] + co ;
                q.insert({ans[de],de}) ;
            }
        }

        for (int i = 0 ; i< 8 ; i++) {
            ll cnt = 1 ;
            while(1) {
                ll nx = x + cnt * dx[i] ;
                ll ny = y + cnt * dy[i] ;
            //    cout << nx << ' ' << ny << '\t' ;
                cnt ++ ;
                if (nx <= 0 or ny <= 0 or nx > n or ny > m) break ;
                ll id = fun(nx,ny) ;
                if (mp[id]) break ;
             //   cout << "ca " << ans[id] << ' ' <<ans[now] <<' ' << c[i] << ' ' << i << ' ' << dx[i] << ' ' << dy[i] << endl << endl ;  ;
                if (ans[id] <= ans[now] + c[i]) break ;
               // cout << "Co " ;
                q.erase({ans[id],id}) ;
                ans[id] = ans[now] + c[i] ;
                q.insert({ans[id],id}) ;
            }
        }
    }

}

void solve() {
    tun.clear() ;
    mp.clear() ;
    ans.clear() ;
    ll  p , q , i , j;
    cin >> n >> m >> p >> q ;
    ll sx , sy , dxx , dyy ;
    cin >> sx >> sy >> dxx >> dyy ;

    for (i = 0 ; i< 8 ; i++) cin >> c[i] ;

    for (i = 0 ; i< p ; i++) {
        ll ux , uy , vx, vy , w ;
        cin >> ux >> uy >> vx >> vy >> w ;
        ll tmp =fun(ux,uy) ;
        ll tmp2 = fun(vx,vy) ;
        tun[tmp].pb({tmp2,w}) ;
    }

    for (i = 0 ; i< q ; i++) {
        ll u , v ;
        cin >> u >> v ;
        mp[fun(u,v)] = 1 ;
    }

    for (i = 1 ; i<= n ; i++) {
        for (j = 1 ; j<= m  ; j++) {
            ans[fun(i,j)] = (ll) 1e17 ;
        }
    }

    dij(fun(sx,sy)) ;
    ll xx = ans[fun(dxx,dyy)] ;
    if (xx == (ll) 1e17) cout << "-1\n" ;
    else cout << xx << '\n' ;

}

int main() { __

    ll t=1 ;
    cin >> t ;
    for (ll cz = 1 ; cz<= t ; cz++) {
        cout << "Case " << cz << ": " ;
        solve() ;
    }

    return 0 ;
}







