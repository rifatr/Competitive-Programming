#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    inf.readToken("[A-Z][a-z]{1, 100}", "s");
    inf.readEoln();
    inf.readEof();
}
