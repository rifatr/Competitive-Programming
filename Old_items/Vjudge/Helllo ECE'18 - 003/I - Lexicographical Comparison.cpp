#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll i, n, m;

    cin >> n;
    ll A[n];
    for(i = 0; i < n; i++)
        cin >> A[i];

    cin >> m;
    ll B[m];
    for(i = 0; i < m; i++)
        cin >> B[i];

    cout << lexicographical_compare(A, A + n, B, B + m) << endl;

    return 0;
}
