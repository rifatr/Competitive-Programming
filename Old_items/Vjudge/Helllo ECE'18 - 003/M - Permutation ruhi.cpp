#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int>a;
    int i,j,b,c,n,p,q,r,t,x,k;

    cin>>n;


    for(i=0; i<n; i++)
    {
        cin>>x;
        a.push_back(x);
    }
    if(!is_sorted(a.begin(),a.end()))
    {
        prev_permutation(a.begin(),a.end());

        for(i=0; i<n; i++)
        {
            if(i!=n-1)
            {
                cout<<a[i]<<" ";
            }
            else
            {
                cout<<a[i];
            }
        }
        cout<<endl;
    }


    next_permutation(a.begin(),a.end());
    for(i=0; i<n; i++)
    {
        if(i!=n-1)
        {
            cout<<a[i]<<" ";
        }
        else
        {
            cout<<a[i];
        }
    }
    cout<<endl;
    if(!is_sorted(a.begin(),a.end(),greater<int>()))
    {
        next_permutation(a.begin(),a.end());

        for(i=0; i<n; i++)
        {
            if(i!=n-1)
            {
                cout<<a[i]<<" ";
            }
            else
            {
                cout<<a[i];
            }
        }
        cout<<endl;
    }


    return 0;

}
