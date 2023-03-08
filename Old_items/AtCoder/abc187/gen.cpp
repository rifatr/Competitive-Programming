// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}
const int N = 2e5, M = 1e9;
int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int n = N;//rand(1, 7);
    cout << n << '\n';
    while(n--) {
        cout << M << ' ' << 1 << '\n';
    }
}

