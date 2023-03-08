#include<bits/stdc++.h>

using namespace std;

bool IsPrime(int n)
{
    if(n < 2 || n % 2 == 0)
        return false;
    if(n == 2)
        return true;

    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0)
            return false;
    }

    return true;
}

int main()
{
    int n;

    cin >> n;

    if(IsPrime(n) == true)
        cout << "NO PUNISHMENT\n";
    else{
        for(int i = 0; i < n; i++)
            cout << "I DID NOT DO THE ASSIGNMENT.\n";
    }

    return 0;
}
