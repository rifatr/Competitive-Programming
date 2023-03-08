#include <bits/stdc++.h>
#define int long long

typedef long long LL ;
#define int long long

using namespace std;

const int N=1e6+7, MOD=1e9+7 ;

int a[N], l, r, q, pw[N], oc[35][N], n, tot, sp ;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pw[0]=1 ;
    for(int i=1; i<N; ++i)pw[i]=pw[i-1]*2%MOD ;


    cin>>n>>q ;

    for(int i=1; i<=n; ++i)
        cin>>a[i] ;

    for(int i=0; i<=32; ++i)
    {
        for(int j=1; j<=n; ++j)
        {
            if(a[j]&(1LL<<i))oc[i][j]=1 ;

            oc[i][j]+=oc[i][j-1] ;

        }

    }

    while(q--)
    {
        cin>>l>>r ;
        int ans=0, c ;

        for(int i=0; i<=32; ++i)
        {

            tot=oc[i][r]-oc[i][l-1] ;

            if(tot==0)continue ;

            sp=r-l+1-tot ;

            c=pw[tot-1]*pw[sp]%MOD ;
            c=c*(1LL<<i)%MOD ;

            ans+=c ;

        }

        cout<<ans%MOD<<'\n';

    }


}

