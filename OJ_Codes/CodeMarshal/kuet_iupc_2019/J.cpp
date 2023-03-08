#include <bits/stdc++.h>
//#define int long long

//typedef long long LL ;
//#define int long long

using namespace std;

const int N=1e5+7, MOD=1e9+7 ;

int a[N], test, idp[N][15], b[N], ddp[N][15], k, n , tree[4*N] ;

void update(int nd,int be,int en,int l,int r,int v){

    if(be>r or en<l)return ;

    if(be>=l and en<=r)
    { tree[nd]=max(tree[nd],v) ; return ; }

    int md=(be+en)/2 ;
    update(nd<<1,be,md,l,r,v) ; update(nd<<1|1,md+1,en,l,r,v) ;

    tree[nd]=max(tree[nd<<1],tree[nd<<1|1]) ;
}


int query(int nd,int be,int en,int l,int r){

    if(be>=l and en<=r)
     return tree[nd];

     if(be>r or en<l)
     return 0 ;

    int md=(be+en)/2 ;

    return max( query(nd<<1,be,md,l,r) , query(nd<<1|1,md+1,en,l,r) ) ;
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin>>test ;

    for(int tt=1;tt<=test;++tt){


    cin>>n>>k ;

    for(int i=1; i<=n; ++i)
        cin>>a[i] ;

    for(int i=1; i<=n; ++i)
        cin>>b[i] ;

    for(int i=1; i<=n; ++i)
    {

        for(int j=0; j<=k; ++j)
            idp[i][j]=1 ;

        for(int j=i-1; i-j-1<=k and j>0; --j)
        {

            if( a[j]<=a[i] )
            {

                for(int d=0; d<=k; ++d)
                {

                    //cout<<" i "<<i<<" j "<<j<<" d "<<d<<" dp "<<idp[j][d]<<endl ;

                    if(d+i-j-1>k)
                        break ;

                    idp[i][d+i-j-1]=max(idp[i][d+i-j-1],idp[j][d]+1) ;
                }
            }
        }
    }

    b[n+1]=MOD ;
    for(int i=0; i<=k; ++i)ddp[n+1][i]=0 ;

    for(int i=n; i>=1; --i)
    {

        for(int j=0; j<=k; ++j)
            ddp[i][j]=1 ;

        for(int j=i+1; j-i-1<=k and j<=n; ++j)
        {

            if( b[j]>=b[i] )
            {

                for(int d=0; d<=k; ++d)
                {

                    if(d+j-i-1>k)break ;

                    ddp[i][d+j-i-1]=max(ddp[i][d+j-i-1],ddp[j][d]+1) ;

                }
            }
        }
    }

    int ans=1 ;

    for(int i=n;i>=1;--i)
       for(int j=0;j<=k;++j)
            ans=max(ans,idp[i][j]) ;

     for(int i=1;i<=n;++i)
       for(int j=0;j<=k;++j)
            ans=max(ans,ddp[i][j]) ;

    for(int i=1,len=0;i<=n;++i){

        len=0 ;
        for(int j=0;j<=k;++j){
          len=max(len,ddp[i][j]) ;
        }

        update(1,1,N-5,b[i],b[i],len) ;
    }


    for(int i=n,len;i>=1;--i){
        len=0 ;
       for(int j=0;j<=k;++j){
          len=max(len,idp[i][j]) ;
        }

        ans=max(ans,len+query(1,1,N-5,a[i],N-5)) ;
    }


    cout<<"Case "<<tt<<": "<<ans<<endl ;

    memset(tree,0,sizeof(tree)) ; memset(idp,0,sizeof(idp)) ; memset(ddp,0,sizeof(ddp)) ;

    }

    return 0 ;
}

