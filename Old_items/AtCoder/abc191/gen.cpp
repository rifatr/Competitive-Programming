// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int t = rand(1, 1);
//    cout << t << '\n';
    while (t--)
    {
        int n = rand(1, 10), k = rand(1, 10);
        cout << n << ' ' << k << '\n';
        while(k--)
        cout << rand(1, n) << ' ' << rand(1, n) << ' ' << rand(1, 20) << '\n';

    }
}

