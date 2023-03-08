// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int t = rand(1, 1);
    //cout << t << '\n';
    while (t--)
    {
        int n = rand(1, 5);
        cout << n << '\n';

        while(n--)
        cout << rand(0, 100) << ' ' << rand(0, 100) << '\n';
    }

    cout << 0 << '\n';
}

