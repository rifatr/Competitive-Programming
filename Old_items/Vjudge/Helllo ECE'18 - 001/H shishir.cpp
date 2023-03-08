#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t, k;
    vector<long long int>A;
    cin >> t;
    for(k=1; k<=t; k++)
    {
        long long int n,m,l, i, j, z, d,e,x,y;
        cin >> n >> m;
        for(i=0; i<n; i++)
        {
            cin>>l;
            A.push_back(l);
        }
        for(j=0; j<m; j++)
        {
            char s;
            cin>>s;
            cin.ignore();
            if(s=='R')
            {
                reverse(A.begin(),A.end());
            }
            else if(s=='P')
            {
                cin>>x>>y;
                swap(A[x],A[y]);
            }
            else if(s=='S')
            {
                cin>>d;
                for(z=0; z<n; z++)
                {
                    A[z]=A[z]+d;
                }
            }
            else if(s=='M')
            {
                cin>>e;
                for(z=0; z<n; z++)
                {
                    A[z]=A[z]*e;
                }
            }
            else if(s=='D')
            {
                cin>>k;
                for(z=0; z<n; z++)
                {
                    A[z]=A[z]/k;
                }
            }
        }

        printf("Case %d:\n",k);
        for(i=0; i<n; i++)
        {
            cout << A[i];
            if(i<n-1)
                cout << " ";
        }
        cout << endl;;
        A.clear();
    }
    return 0;
}
