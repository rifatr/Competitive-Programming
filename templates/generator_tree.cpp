//generator to generate testcase
#include <bits/stdc++.h>
using namespace std;
#define ll long long
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// return a random number in [l, r] range
ll rand(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}
 
void tree() {
    int n = rand(1, 10); // number of nodes
    int t = rand(1, 5); // random parameter
 
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= t; j++)
            p[i] = max(p[i], (int)rand(0, i - 1));
    }
 
    vector<int> perm(n);
    for (int i = 0; i < n; i++) perm[i] = i;
    shuffle(perm.begin(), perm.end(), rng);
 
    vector<pair<int, int> > edges;
    for (int i = 1; i < n; i++)
        if (rand(0, 1))
            edges.push_back(make_pair(perm[i], perm[p[i]]));
        else
            edges.push_back(make_pair(perm[p[i]], perm[i]));
    shuffle(edges.begin(), edges.end(), rng);
 
    printf("%d\n", n);
    for (int i = 0; i + 1 < n; i++)
        printf("%d %d\n", edges[i].first + 1, edges[i].second + 1);
}

int main(int argc, char* argv[]) {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll t = rand(1, 1);
    cout << t << endl;
    while (t--) {
        tree();
    }
    return 0;
}
