#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    registerGen(argc, argv, 1);

    int a = rnd.next(1, 1000), b = rnd.next(a, 1000), k = rnd.next(1, 10 ^ 6);

    println(a, b, k);

    return 0;
}