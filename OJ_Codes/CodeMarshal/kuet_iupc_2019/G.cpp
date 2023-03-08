#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define pb push_back
#define pii pair<int,int>
const int mx=3e4+5;
vector<pii>adj[mx];
int sum;
int vis[mx];
int n,m,q,root;
int parent[mx];
int dist[mx],tot[mx],type[mx];
///0==singlular,1=circular
void dfs(int node,int par)
{
     vis[node]=1;
    parent[node]=root;
    for(auto son:adj[node])
    {

        if(son.first==par) continue;
        if(son.first==root)
        {
             sum+=son.second;
             continue;
        }
        if(vis[son.first]) continue;
        sum+=son.second;
        dist[son.first]=sum;

        dfs(son.first,node);
    }

}
void all_clear()
{
   for(int i=1; i<=n; i++)
   {
        adj[i].clear();
        vis[i]=0;
        dist[i]=0;
        tot[i]=0;
        type[i]=0;
        parent[i]=i;
   }
}
int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0);

   int t;
   cin>>t;
   int tc=0;
   while(t--)
   {
       cin>>n>>m;
       all_clear();
       for(int i=0; i<m; i++)
       {
           int x,y,z;
           cin>>x>>y>>z;
           adj[x].pb({y,z});
           adj[y].pb({x,z});
       }
       for(int i=1; i<=n; i++)
       {
           if(vis[i] || adj[i].size()>1) continue;
           sum=0;
           root=i;
           dfs(i,0);
           dist[root]=0;
           tot[root]=sum;

       }
         for(int i=1; i<=n; i++)
       {
           if(vis[i]) continue;
           sum=0;
           root=i;
           dfs(i,0);
           dist[root]=0;
           tot[root]=sum;
           type[root]=1;
       }

       cin>>q;
       cout<<"Case "<<++tc<<":"<<endl;
       while(q--)
       {
            int x,y;
            cin>>x>>y;
            if(parent[x]!=parent[y])
             {
                cout<<-1<<endl;
                continue;
             }
             if(type[parent[x]]==0)///singular
             {
                 int mx=max(dist[x],dist[y]);
                 int mn=min(dist[x],dist[y]);
                 cout<<mx-mn<<endl;
                 continue;
             }
              int mx=max(dist[x],dist[y]);
              int mn=min(dist[x],dist[y]);
              int ans=mx-mn;
              ans=min(ans,tot[parent[x]]-ans);
              cout<<ans<<endl;
       }
   }
}
/**
1
5 5
1 2 1
2 3 2
3 4 3
5 1 5
4 5 4
4
1 1
1 3
3 5
5 2

*/
