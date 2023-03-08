#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a,w,d;
    char t;
    string m;
    cin>>n;
    vector<tuple<long long,long long,char,long long,string> >v;
    for(long long i=0;i<n;i++)
    {
     cin>>a>>w>>t;
     cin.ignore();
     cin>>d>>m;
     v.push_back(make_tuple(a,w,t,d,m));
    }
    sort(v.begin(),v.end());

    //cout << v[0].first;
    for(long long i = 0; i < n; i++) {
        cout << get<0>(v[i]) << " " << get<1>(v[i]) << " " << get<2>(v[i])
            << " " << get<3>(v[i]) << " " << get<4>(v[i]) << "\n";
    }
    return 0;
}
