#include<bits/stdc++.h>

#define lop(n) for(int i = 0; i < n; i++)
#define pb push_back
#define ff first
#define ss second
#define all(x) x.begin(), x.end()

using namespace std;

struct stin
{
    string itm;
    int val;

    bool operator < (const stin &a) const
    {
        return itm < a.itm;
    }
};

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
    freopen("F input.txt", "r", stdin);

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tt, n, m, b, k, price, amnt;
    string binder, item, recipe;

    cin >> tt;
    cin.ignore();

    while(tt--)
    {
        getline(cin, binder);

        cin >> m >> n >> b;
        cin.ignore();

        vector <stin> ip(m), rp(n);
        stin iv;

        lop(m)
        {
            cin >> item >> price;
            iv.itm = item;
            iv.val = price;
            ip.pb(iv);
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
                int it = lower_bound(ip.itm.begin(), ip.itm.end(), item) - ip.itm.begin();
                price += ip[item] * amnt;
            }

            rp[recipe] = price;
        }

        bool f = false;

        cout << upper(binder) << '\n';

        for(auto it = rp.begin(); it != rp.end(); it++) {
            if(it -> ss <= b) {
                cout << it -> ff << '\n';
                b -= it -> ss;
                f = true;
            }
        }

        if(f == false) cout << "Too expensive!\n";

        cout << '\n';

        rp.clear();
        ip.clear();
    }



    return 0;
}


