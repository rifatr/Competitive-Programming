// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

string s = "0123456789";

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int t = rand(1, 5);
    cout << t << '\n';
    while (t--)
    {
        int n = rand(1, 20), k = rand(1, 100);
        cout << n << ' ' << k << '\n';
        while(n--)
        cout << rand(1, k - 1) << ' ';
        cout << '\n';
    }
}

