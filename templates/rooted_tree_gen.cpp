#include "testlib.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctime>
#include <climits>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define forn(i, n) for (int i = 0; i < int(n); i++)

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int n = rnd.next(1, 10);//opt<int>(1);
    int t = n;//rnd.next(1, 10);//opt<int>(2);

    vector<int> p(n);
    forn(i, n)
    if (i > 0)
        p[i] = rnd.wnext(i, t);

    printf("%d\n", n);
    vector<int> perm(n);
    forn(i, n) perm[i] = i;
    shuffle(perm.begin(), perm.end());

    vector<int> pp(n);
    for (int i = 0; i < n; i++)
        pp[perm[i]] = perm[p[i]];

    for (int i = 0; i < n; i++)
    {
        printf("%d", pp[i] + 1);
        if (i + 1 < n)
            printf(" ");
    }
    printf("\n");

    // forn(i, n) cout << p[i] << ' '; cout << '\n';
    // forn(i, n) cout << perm[i] << ' '; cout << '\n';

    return 0;
}