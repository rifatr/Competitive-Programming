#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("B input.txt", "r", stdin);

    vector<pair<int,int> > s;
    int i,j,t,l,w,h,g,a,x,y=0;
    while(t!=0)
    {
        y=1;
        cin>>t;
        for(i=0; i<t; i++)
        {
            cin>>l>>w>>h;
            y=l*w*h;
            cout<<"l = " << l << " w = " << w << " h = " << h << " y = " << y <<endl;
            s.push_back(make_pair(h,y));

        }
        cout << "input newa shesh\n";
        sort(s.begin(),s.end());

        for(i=0; i<t; i++)
            cout<<s[i].first<<" "<<s[i].second<<endl;

//        if(t!=0)
//        {
//            cout<<s[0].first<<" "<<s[0].second<<endl;
//            cout<<s[t-1].first<<" "<<s[t-1].second<<endl;
//        }

        cout << "looper kaj shesh\n";

    }
}

