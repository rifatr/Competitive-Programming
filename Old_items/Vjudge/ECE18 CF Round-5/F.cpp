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

    int n, m, k, a, b;

    cin >> n >> m >> k;

    bool info[n + 1][m + 1];

    lop(1, n + 1) lopj(1, m + 1) cin >> info[i][j];

    ll notification[n + 1] = {0}, ownmsg[n + 1] = {0};
    ll tmsg[m + 1] = {0};

    lop(1, k + 1)
    {
        cin >> a >> b;
        ownmsg[a]++;
        tmsg[b]++;

//        lopj(1, n + 1)
//            if(info[j][b] and j != a)
//                notification[j]++;
    }

    lop(1, n + 1)
    {
        lopj(1, m + 1)
        {
            if(info[i][j])
            {
                notification[i] += tmsg[j];
            }
        }
        notification[i] -= ownmsg[i];
    }

    lop(1, n + 1)
        cout << notification[i] << " ";

    return 0;
}

