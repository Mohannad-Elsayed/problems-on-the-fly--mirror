#include <bits/stdc++.h>
using ll = long long;
using namespace std;

namespace optimizedSolution {
    int solve(int n)
    {
        int lg = __lg(n);
        if ((1 << lg) == n || (1<<lg) - 1 == n || (1 << (lg+1)) - 1 == n)
            return(-1);
        return (1 << lg) -1;
        
    }
}

namespace bruteforceSolution {
    int solve(int x) {
        if ((x & (x - 1)) == 0 || (x & (x + 1)) == 0) {
            return -1;
        }
        
        int a = std::__lg(x);
        int b = __builtin_ctz(~x);
        
        int y = x ^ (1 << a) ^ (1 << b);
        return y;
    }
}


void test()
{
    int N = (int)1e9 + 1;

    for (int i = 2; i < N; i++) {
        int optimized = optimizedSolution::solve(i);
        int correct = bruteforceSolution::solve(i);
        if (correct == -1 && optimized == -1)
            continue;
        
        if (correct == -1 && optimized != -1) {
            cout << "At i = " << i << " optimized find an answer while correct didn't!";
            return;
        }
        if (correct != -1 && optimized == -1) {
            cout << "At i = " << i << " optimized didn't find an answer while there's one!";
            return;
        }

        int a = optimized, b = i;
        int c = a^b;
        if (!(a+b > c && a+c > b && b+c > a)) {
            cout << "At i = " << i << " optimized provided incorrect answer: " << optimized;
            return;
        }
    }
    
    cout << "All Numbers Passed!";
}
int main() {
    test();
    return 0;
}