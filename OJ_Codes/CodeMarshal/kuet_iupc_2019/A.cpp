#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main()
{
    int t;
    cin>>t;
    int tc=0;
    while(t--)
    {
        int n;
    cin>>n;
    int a[n+5],b[n+5];
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    stack<int>st;
    int i=0,j=0;
    int ok=1;
    while(i<n)
    {
        if(!st.empty() && st.top()==b[j])
        {
            ++j;
            st.pop();
            continue;
        }
        if(a[i]==b[j])
        {
           ++i,++j;
           continue;
        }
        st.push(a[i]);
        ++i;

    }
    while(!st.empty())
    {
       if(b[j]!=st.top())
       {
         ok=0;
         break;
       }
       ++j;
       st.pop();
    }
    cout<<"Case "<<++tc<<": ";
    if(ok) cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    }


}
