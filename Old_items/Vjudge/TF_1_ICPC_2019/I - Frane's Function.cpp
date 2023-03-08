#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, i;
    int b;
    vector <int> divisor;

    cin >> n;

    if(n == 1) {
        cout << "0" << endl;
        return 0;
    }
    for(i = 1; i * i <= n; i++) {
        if(n % i == 0 && i != n / i) {
            divisor.push_back(i);
            divisor.push_back(n / i);
        }
        else if(n % i == 0)
            divisor.push_back(i);
    }
    sort(divisor.begin(), divisor.end());

    b = divisor.size();

    cout << n - divisor.at(b - 2) << endl;

    return 0;
}
