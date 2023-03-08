#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 60;
int n, k, a[N], bit[N];
pair <int, int> tmp[N];

bool comp(pair <int, int> &a, pair <int, int> &b) {
    return a.first == b.first ? a.second > b.second : a.first < b.first;
}

void edit(int pos) {
    while (pos <= n) {
        bit[pos] += 1;
        pos += pos & -pos;
    }
}

int sum(int pos) {
    int s = 0;
    while (pos) {
        s += bit[pos];
        pos -= pos & -pos;
    }

    return s;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);

    int tc;
    cin >> tc;

    while (tc--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            tmp[i] = {x, i};
        }
        sort(tmp + 1, tmp + n + 1, comp);

        int p = 1;
        for (int i = 1; i <= n; i++)
            a[tmp[i].second] = p++;

        int won = 0; // careful about overflow
        for (int i = n; i; i--)
        {
            won += sum(a[i] - 1);
            edit(a[i]);
        }
        cout << won << '\n';

        for (int i = 0; i < n + 10; i++) bit[i] = 0;
    }

    return 0;
}