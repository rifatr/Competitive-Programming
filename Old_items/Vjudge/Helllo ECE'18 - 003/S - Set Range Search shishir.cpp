#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,t,k,l,w;
    set<int>s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>t>>k;
        if(t==0)
        {
           s.insert(k);
           cout<<s.size()<<endl;
        }
        if(t==1)
        {
            cout<<s.count(k)<<endl;
        }
        if(t==2)
        {
            s.erase(k);
        }
        if(t==3)
        {
            cin>>l>>w;
                //set<int>::iterator it,it1,j;
                auto it=lower_bound(s.begin(),s.end(),l);
                auto it1=upper_bound(s.begin(),s.end(),w);
                for(;it!=it1 && it != s.end();it++)
                {
                cout<<*it<<endl;
                }
        }
    }
    return 0;
}
