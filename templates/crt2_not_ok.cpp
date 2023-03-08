// Time: 2023-02-09 18:21:07 Problem: G - G
// URL: https://vjudge.net/contest/542355#problem/G

#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 520;

int ext_gcd(int a,int b,int *x,int *y)
{
    if(b==0)
    {
        *x=1;
        *y=0;
        return a;
    }
  int x1,y1;
  int g=ext_gcd(b,a%b,&x1,&y1);
  *x=y1;
  *y=x1-(a/b)*y1;
  return  g;
}

/** Works for non-coprime moduli.
 Returns {-1,-1} if solution does not exist or input is invalid.
 Otherwise, returns {x,L}, where x is the solution unique to mod L
*/
pair<int, int> crt( vector<int> A, vector<int> M ) {
    if(A.size() != M.size()) return {-1,-1}; /** Invalid input*/
 
    int n = A.size();
 
    int a1 = A[0];
    int m1 = M[0];
    /** Initially x = a_0 (mod m_0)*/
 
    /** Merge the solution with remaining equations */
    for ( int i = 1; i < n; i++ ) {
        int a2 = A[i];
        int m2 = M[i];
 
        int g = __gcd(m1, m2);
        if ( a1 % g != a2 % g ) return {-1,-1}; /** No solution exists*/
 
        /** Merge the two equations*/
        int p, q;
        ext_gcd(m1/g, m2/g, &p, &q);
 
        int mod = m1 / g * m2; /** LCM of m1 and m2*/
 
        /** We need to be careful about overflow, but I did not bother about overflow here to keep the code simple.*/
        int x = (a1*(m2/g)*q + a2*(m1/g)*p) % mod;
 
        /** Merged equation*/
        a1 = x;
        if (a1 < 0) a1 += mod; /** Result is not suppose to be negative*/
        m1 = mod;
    }
    return {a1, m1};
}

 

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);

	int tc;
	cin >> tc;

	while (tc--)
	{
		int n; cin >> n;
		vin a(n), b(n);
		lop(n) {
			cin >> a[i] >> b[i];
			if(i % 2) b[i] = (a[i] - b[i]) % a[i]; // this line is for problem statement
		}
		
		auto x = crt(b, a);
		if(x.ff == -1) print("Impossible");
		else print(x.ff);
	}

	return 0;
}
