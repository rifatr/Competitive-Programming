#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << " , "<< #y << "=" << y<< endl
#define _                                                                                                              \
    ios::sync_with_stdio(false);                                                                                       \
    cin.tie(0);cout.tie(0);
#define ff first
#define ss second
#define pb push_back
#define pp pop_back

double x, y, sx, sy, sxx, sxy, a, tx, ty;

double f(ll t)
{
	double ret = (t*1.0*sxy - sx*sy)/(t*1.0*sxx - sx*sx);
	
	return ret;
}

void solve(ll t)
{
    sx=0 , sy = 0, sxx = 0, sxy = 0;
    for(ll i=0 ; i<t ; i++)
    {
    	cin >> x >> y;
    	sx += x;
    	sy += y;
    	sxx += (x*x);
    	sxy += (x * y);
    } 
    
    a = f(t);
    
    double lo = 0, hi = 1000;
    
    for(ll i=0 ; i<100 ; i++)
    {
    	double m1 = lo + (hi-lo)/3, m2 = hi - (hi - lo)/3;
    	tx = sx, ty = sy;
    	sx += m1;
    	
    	if(abs(a - m1) )
    }
    
}
int main()
{_
    int t = 1, cs = 1;
    while (1)
    {
    	cout << "Case " << cs++ << ": \n";
    	cin >> t;
    	if(t == 0) break;
        solve(t);
    }
    return 0;
}