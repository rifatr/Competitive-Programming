#include<bits/stdc++.h>

#define lop(n) for(int i = 0; i < n; i++)
#define ff first
#define ss second

using namespace std;

string upper(string s)
{
    int saiz = s.size();

    lop(saiz)
        if(s[i] >= 'a' and s[i] <= 'z')
            s[i] -= 32;

    return s;
}

int main()
{
    //freopen("F input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt, n, m, b, k, price, amnt;
    string binder, item, recipe;

    cin >> tt;

    while(tt--)
    {
        map <string, int> ip;

        cin.ignore();
        getline(cin, binder);

        cin >> m >> n >> b;
        cin.ignore();

        pair<int , string> rp[n];

        lop(m)
        {
            cin >> item >> price;
            ip[item] = price;
        }

        lop(n)
        {
            cin.ignore();
            getline(cin, recipe);

            cin >> k;
            price = 0;

            lop(k)
            {
                cin >> item >> amnt;
                price += ip[item] * amnt;
            }

            rp[i].ff = price;
            rp[i].ss = recipe;
        }

        sort(rp, rp + n);

        bool f = false;

        cout << upper(binder) << '\n';

        lop(n) {
            if(rp[i].ff <= b) {
                cout << rp[i].ss << '\n';
                //b -= it -> ss;
                f = true;
            }
        }

        if(f == false) cout << "Too expensive!\n";

        cout << '\n';
    }



    return 0;
}

