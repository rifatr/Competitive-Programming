#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"


int cap(string s)
{
    int k = 0;

    for(auto &z : s)
        if(z >= 'A' and z <= 'Z')
            k++;

    cout << k << " ";
    return k;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    int n, k;
    long long s = 0, x, xx;

    cin >> n;

    lop(2, n)
    {
        k = n;

        while(k)
        {
            int p = k % i;
            k -= p;
            k /= i;

            s += p;
        }
    }

    x = n - 2;

    xx = __gcd(s, x);

    cout << s / xx << '/' << x / xx << '\n';

    return 0;
}

