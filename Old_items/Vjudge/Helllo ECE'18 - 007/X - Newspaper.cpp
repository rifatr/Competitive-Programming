#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(b) for(int i = 0; i < b; i++)
#define lopr(a, b) for(int i = a; i < b; i++)


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("X input.txt", "r", stdin);

    int x, test;

    cin >> test;

    while(test--)
    {
        int lines, paid_char;
        ll price, total_paid = 0;
        char c;
        string line;
        map <char, ll> values;

        cin >> paid_char;

        //c =
        lopr(32, 127) {
            c = (char) i;
            values[c] = 0;

            //cout << c << values[c] << '\n';
        }

        lop(paid_char)
        {
            cin >> c >> price;
            values[c] = price;
            //cout << c << values[c] << '\n';
        }

        cin >> lines;
        cin.ignore();

        lop(lines)
        {
            getline(cin, line);

            int n = line.size();
            lop(n) {
                total_paid += values[line[i]];
//                if(values[line[i]])
//                    cout << line[i] << values[line[i]] << '\n';
            }
        }

        double ammount = (double) total_paid / 100;

        printf("%.2lf$\n", ammount);
    }

    return 0;
}

