#include <bits/stdc++.h>
#include <testlib.h>

using namespace std;

#define ll long long
#define lop(n) for(int i = 0; i < n; i++)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
// return a random number in [l, r] range
ll rand(ll l, ll r) {
    return uniform_int_distribution<ll>(l, r)(rng);
}

//generate an array of length n where each element in [l, r] range
void Array(ll n, ll l, ll r) {
    for (int i = 0; i < n; i++)
        cout << rand(l, r) << (i < n - 1 ? ' ' : '\n');
}
void distinct_array(int n, int l, int r) {
    set <int> st;
    while (st.size() != n) {
        st.insert(rand(l, r));
    }
    vector <int> a(st.begin(), st.end());
    // do not shuffle if you want increasing array
    shuffle(a.begin(), a.end(), rng);

    println(a);
}

//generate a string of lowercase letters of length n
void String(int n) {
    for (int i = 0; i < n; i++)
        cout << (char) ('a' + rand(0, 25));
    cout << '\n';
}

void String(int n, char l, char r) {
    for (int i = 0; i < n; i++)
        cout << (char) rand(l, r);
    cout << '\n';
}

const int N = 1e4;

vector <vector<int>> eg;

int main(int argc, char* argv[]) {
    // registerGen(argc, argv, 1);

    println(N);

    for (int i = 0; i < 100; i++) {
        for (int j = 1; j <= 100; j++) {
            eg.push_back({i + j, i});
        }
    }

    cout << "[[" << eg[0][0] << "," << eg[0][1] << "]";
    for (int i = 1; i < eg.size(); i++) {
        cout << ",[" << eg[i][0] << "," << eg[i][1] << "]";
    }
    cout << "]\n";

    println(0);
    println(N - 1);

    // println(eg.size());

    return 0;
}

