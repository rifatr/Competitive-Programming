#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int a = inf.readInt(1, 1000, "a");
    int b = inf.readInt(1, 1000, "b");
    ensure(a <= b);
    int k = inf.readInt(1, 1000000, "k");
    inf.readEoln();
    inf.readEof();
}
