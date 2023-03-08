#include<bits/stdc++.h>

using namespace std;

#define yes cout << " is an armstrong number!\n"
#define no cout << " is not an armstrong number!\n"

int cube(int a)
{
    return a * a * a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x, test, a[3], n;

    cin >> test;

    while(test--)
    {
        cin >> x;
        cout << x;

        n = x;
        for(int i = 0; i < 3; i++)
            a[i] = n % 10, n /= 10;

        if(cube(a[0]) + cube(a[1]) + cube(a[2]) == x)
            yes;
        else
            no;
    }

    return 0;
}

