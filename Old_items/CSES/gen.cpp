// generating a random sequence of distinct elements
#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

string s = "0123456789";

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
    int t = rand(1, 10);
    //cout << t << '\n';
    while (t--)
    {
        cout << (char) ('A' + rand(0, 1));
    }
    cout << '\n';
}

