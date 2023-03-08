#include <bits/stdc++.h>
using namespace std;

#define print(x) printf("%d\n", x)

int rand(int a, int b) {
    return a + rand() % (b - a + 1);
}

int main(int argc, char* argv[]) {
    srand(atoi(argv[1])); // atoi(s) converts an array of chars to int

    int t = rand(1, 5);
    cout << t << '\n';
    while (t--)
    {
        int n = rand(1, 5), q = rand(1, 5);
        cout << n << ' ' << q << '\n';

        for (int i = 0; i < n; i++)
        {
            cout << rand(0, 20) << (i < n - 1 ? ' ' : '\n');
        }

        while (q--)
        {
            int cmd = rand(1, 3);
            cout << cmd << ' ';

            if (cmd == 1)
                print(rand(0, n - 1));
            else if (cmd == 2)
                cout << rand(0, n - 1) << ' ' << rand(0, 20) << '\n';
            else
            {
                int l = rand(0, n - 1), r = rand(l, n - 1);
                cout << l << ' ' << r << '\n';
            }
        }
    }
}

