#include<bits/stdc++.h>
#include<cmath>
using namespace std;



int main()
{
    int n,i,x,q,j;
    cin>>n>>q;
    int a[n];
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(j=0; j<q; j++)
    {
        cin>>x;
        int high,low,mid;
        low=0;
        high=n - 1;

        while(1)
        {
            mid=(low+high)/2;

            if(a[mid]<x)
                low=mid+1;

            else if(a[mid]>x)
                    high=mid-1;

            else if(a[mid]==x)
            {
                cout<<mid<<endl;
                break;
            }
            if(low>=high)
            {
                cout<<"-1"<<endl;
                break;
            }
        }
    }
    return 0;
}

