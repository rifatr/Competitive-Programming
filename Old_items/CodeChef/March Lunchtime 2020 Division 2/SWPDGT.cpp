#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    int t, a, b, sum = 0;
    vector <int> digits;

    cin >> t;

    while(t--)
    {
        cin >> a >> b;

        int maxa  = a + b;

        if((a < 10 && b < 10) || (a % 10 == 0 && b % 10 == 0)) {
            cout << maxa << endl;
            continue;
        }

        int s = a, t;
        while(s > 0)
        {
            digits.push_back(s % 10);
            s /= 10;
        }
        s = b;
        while(s > 0)
        {
            digits.push_back(s % 10);
            s /= 10;
        }

        sort(digits.begin(), digits.end(), greater <int> ());

        s = 0; t = 0;
        if(digits.size() == 3)
        {
            s += digits[0];
            s *= 10;
            s += digits[1];

            t = digits[2];
        }

        else
        {
            s += digits[0];
            s *= 10;
            s += digits[1];

            t += digits[2];
            t *= 10;
            t += digits[3];
        }

        cout << max(maxa, s + t) << endl;

        digits.clear();
    }
}
