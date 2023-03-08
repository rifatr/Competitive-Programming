#include<bits/stdc++.h>

using namespace std;

long long one(int n, int a, int p)
{
    long long sum;

    sum = a * n;
    if(n > 5)
        sum += p;

    return sum;
}

long long two (int n, int b, int p)
{
    long long sum;
    n /= 2;

    sum = b * n;
    if(n > 5)
        sum += p;

    return sum;
}
int main()
{
    long long n, a, b, p, sum, sum2;

    cin >> n >> a >> b >> p;

    if(n % 2 != 0) {
        sum = one(n, a, p);
        cout << sum << endl;
        return 0;
    }

    sum = one(n, a, p);
    sum2 = two(n, b, p);

    if(sum < sum2)
        cout << sum << endl;
    else
        cout << sum2 << endl;

    return 0;
}
