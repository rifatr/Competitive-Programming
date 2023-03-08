#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, n, s;
    vector <int> p, d, f;
    vector <bool> df;

    cin >> t;

    while(t--)
    {
        cin >> n >> s;

        for(int i = 0; i < n; i++) {
            int in; cin >> in;
            p.push_back(in);
        }
        for(int i = 0; i < n; i++) {
            int in; cin >> in;
            df.push_back(in);
        }

        for(int i = 0; i < n; i++) {
            if(df[i] == 0)
                d.push_back(p[i]);
            else
                f.push_back(p[i]);
        }

        sort(d.begin(), d.end());
        sort(f.begin(), f.end());

        if(d.size() == 0 || f.size() == 0)
            cout << "no\n";
        else if(d[0] + f[0] + s <= 100)
            cout << "yes\n";
        else
            cout << "no\n";

        p.clear();
        df.clear();
        d.clear();
        f.clear();
    }


    return 0;
}
