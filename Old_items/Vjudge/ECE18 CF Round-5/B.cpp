#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define lop(a, b) for(int i = a; i < b; i++)
#define lopj(a, b) for(int j = a; j < b; j++)
#define yes cout << "yes\n"
#define no cout << "no\n"

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin)

    ll n, k;

    cin >> n >> k;

    int job[n + 1], taim[n + 1];
    vector <ll> idl[k + 1];
    vector <ll> v;

    lop(1, n + 1) cin >> job[i];
    lop(1, n + 1) cin >> taim[i];

    lop(1, n + 1)
    {
        idl[job[i]].push_back(taim[i]);
    }

    ll p = 0;
    lop(1, k + 1) {
        if(idl[i].size() == 0)
            p++;
        else if(idl[i].size() > 1)
            sort(idl[i].begin(), idl[i].end());
    }

//    lop(1, k + 1)
//    {
//        cout << i << '\t';
//        lopj(0, idl[i].size())
//            cout << idl[i][j] << ' ';
//        cout << endl;
//    }

    lop(1, k + 1)
    {
        if(idl[i].size() > 1)
        {
            int z = 0;
            lopj(0, idl[i].size() - 1)
                v.push_back(idl[i][j]);
        }
    }

    sort(v.begin(), v.end());

    ll s = 0;

    lop(0, p)
        s += v[i];

    cout << s << endl;


    return 0;
}

