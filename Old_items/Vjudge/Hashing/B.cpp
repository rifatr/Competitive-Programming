#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

//const ll N = 2e3, mod1 = 1055482763, base1 = 1055476621, mod2 = 2113605293, base2 = 2049246427;
const ll N = 2e3, mod1 = 2e9+87, mod2 = mod1, base1 = 1e9+33, base2 = 1e9+181;
//const ll N = 2e3, mod1 = 1055482763, mod2 = mod1, base1 = 1055476621, base2 = 189343181;

ll ht1[N], ht2[N], power1[N], power2[N];

void powc()
{
	power1[0] = power2[0] = 1;

	for (int i = 1; i < N; i++)
		power1[i] = (power1[i - 1] * base1) % mod1;
    for (int i = 1; i < N; i++)
		power2[i] = (power2[i - 1] * base2) % mod2;
}

ll Hash(string const &s)
{
	ll n = (ll) s.size(), x = 0LL, y = 0LL;

	for (ll i = 0; i < n; i++)
		x = ((x * base1) + s[i]) % mod1;
    for (ll i = 0; i < n; i++)
		y = ((x * base2) + s[i]) % mod2;

	return (x << 32) | y;
}

int main()
{
//    freopen("C:/Users/AL-RSFR/Desktop/input.txt", "r", stdin);
//    freopen("C:/Users/AL-RSFR/Desktop/output.txt", "w", stdout);


    int t; cin >> t;
    cin.ignore();
    cin.ignore();

    while(t--)
    {
        string nm;
        unordered_map <ll, int> cnt;
        unordered_map <ll, string> name;
        vector <pair<string, double>> res;
        int tot = 0;

        while(getline(cin, nm))
        {
            int n = nm.size();
            if(n == 0)
                break;

            ll x = Hash(nm);
            cnt[x]++;
            name[x] = nm;
//            cout << nm << '\t' << x << "\t\t";
//            cout << name[x] << ' ' << cnt[x] << endl;
            tot++;
        }

        for(auto it = cnt.begin(); it != cnt.end(); it++)
        {
            ll x = it -> first;
            int y = it -> second;

            double ans = ((double) y / tot) * 100.0;
            res.push_back({name[x], ans});
        }

//        cout << cnt.size() << ' ' << res.size() << '\n';

        sort(res.begin(), res.end());
        for(int i = 0; i < (int) res.size(); i++)
            cout << res[i].first << ' ' << fixed << setprecision(4) << res[i].second << '\n';

        if(t) cout << '\n';
    }

    return 0;
}
