#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAX_T = 10000;
const ll MAX_N = 1e18;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int t = MAX_T;
    println(t);
    for (int i = 1; i <= t; ++i) {
        setTestCase(i);
        long long n = rnd.next(1LL, MAX_N);
        println(n);
    }
    return 0;
}
