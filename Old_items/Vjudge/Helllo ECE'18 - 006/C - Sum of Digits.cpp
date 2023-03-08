#include<bits/stdc++.h>

using namespace std;

string stoin(string s);
string rev(string s);

int main()
{
    string n;

    int na;

    cin >> n;

    int c = 0;

    while(n.size() > 1)
    {
        //cout << "n = " << n << '\n';
        n = stoin(n);
        c++;
    }

    cout << c << '\n';

    return 0;
}

string stoin(string s)
{
    int x = 0, k = 0, i = 0;
    string p = "0";

    while(i < s.size())
    {
        x = s[i] - '0';

        int j = 0;

        while(x)
        {
            k = p[j] - '0';

            x += k;

            char c = (x % 10) + '0';

            p[j] = c;
            x /= 10;
            j++;

            if(j > p.size()) {
                p.append("1");
                break;
            }
        }

        i++;
    }

    return rev(p);
}

string rev(string s)
{
    int n = s.size();
    for(int i = 0; i < n / 2; i++)
        swap(s[i], s[n - (i + 1)]);

    return s;
}
