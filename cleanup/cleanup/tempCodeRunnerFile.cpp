#include "102942D.cpp"
#include <iostream>
#include <cassert>
using namespace std;

// Brute force solution for testing
string bruteForce(int a, int b) {
    for (int i = 0; i < 30; i++) {
        if (((a >> i) & 1) && ((b >> i) & 1))
            return "YES";
    }
    return "NO";
}

// Stress test function
void stressTest() {
    for (int t = 0; t < 1000; t++) {
        int a = rnglr(0, 1e6);
        int b = rnglr(0, 1e6);

        // Capture output of the main solution
        stringstream ss;
        streambuf* oldCout = cout.rdbuf(ss.rdbuf());
        cout.clear();
        cout << a << " " << b << endl;
        solve();
        string mainOutput = ss.str();
        cout.rdbuf(oldCout);

        // Compare with brute force solution
        string expectedOutput = bruteForce(a, b);
        assert(mainOutput.find(expectedOutput) != string::npos);
    }
    cout << "All stress tests passed!" << endl;
}

int main() {
    stressTest();
    return 0;
}