// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int t = rand(1, 1000);
    cout << t << '\n';
    while (t--)
    {
        int n = rand(1, 80), k = rand(1, min(n, 3));
        cout << n << ' ' << k << '\n';
        string s, t;
        for (int i = 0; i < n; i++)
            s.push_back((char) ('a' + rand(0, 25)));
        for (int i = 0; i < n; i++)
            t.push_back((char) ('a' + rand(0, 25)));

        cout << s << '\n' << t << '\n';
    }
}

